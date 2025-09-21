#include "mem.h"

// Very dumb bump allocator
static uint8_t *heap_ptr;
static uint8_t *heap_end;

void mem_init(void *heap_start, size_t heap_size) {
    heap_ptr = (uint8_t *)heap_start;
    heap_end = heap_ptr + heap_size;
}

void *kmalloc(size_t size) {
    if (heap_ptr + size > heap_end) {
        return 0; // out of memory
    }
    void *ptr = heap_ptr;
    heap_ptr += size;
    return ptr;
}

void kfree(void *ptr) {
    // no-op for now (bump allocator doesn’t free)
    (void)ptr;
}


