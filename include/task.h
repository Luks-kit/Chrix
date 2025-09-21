#include <stdint.h>

typedef struct {
    uint64_t *stack;
    int state; // RUNNING, READY, etc.
} task_t;

void scheduler_add(task_t *task);
void scheduler_tick(); // called by timer interrupt

