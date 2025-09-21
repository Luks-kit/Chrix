#pragma once
#include <stdint.h>

// Minimal task struct
typedef struct task {
    uint64_t id;
    void (*entry)(void);
    struct task *next;
} task_t;

void sched_init(void);
void sched_add(task_t *t);
void sched_tick(void);
void sched_run(void);

