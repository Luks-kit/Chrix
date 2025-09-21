#pragma once
#include <stdint.h>

// IRQ init and handler registration
typedef void (*irq_handler_t)(void);

void irq_init(void);
void irq_enable(uint32_t irq);
void irq_disable(uint32_t irq);
void irq_register(uint32_t irq, irq_handler_t handler);

