#include "sched.h"
#include "uart.h"

static task_t *task_list = 0;
static task_t *current = 0;

void sched_init(void) {
    task_list = 0;
    current = 0;
}

void sched_add(task_t *t) {
    t->next = 0;
    if (!task_list) {
        task_list = t;
    } else {
        task_t *iter = task_list;
        while (iter->next) iter = iter->next;
        iter->next = t;
    }
}

void sched_tick(void) {
    if (!current) {
        current = task_list;
        return;
    }
    if (current->next) {
        current = current->next;
    } else {
        current = task_list; // wrap around
    }
}

void sched_run(void) {
    if (current && current->entry) {
        uart_puts("[sched] switching to task\n");
        current->entry();
    }
}

