#pragma once
#include <stddef.h>
#include <stdint.h>

// Basic memory management stubs
void mem_init(void *heap_start, size_t heap_size);
void *kmalloc(size_t size);
void kfree(void *ptr);

