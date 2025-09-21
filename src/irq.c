#include "irq.h"
#include "uart.h"

#define MAX_IRQ 64
static irq_handler_t irq_table[MAX_IRQ];

void irq_init(void) {
    for (int i = 0; i < MAX_IRQ; i++) {
        irq_table[i] = 0;
    }
    uart_puts("[irq] initialized\n");
}

void irq_enable(uint32_t irq) {
    uart_puts("[irq] enable not implemented\n");
    (void)irq;
}

void irq_disable(uint32_t irq) {
    uart_puts("[irq] disable not implemented\n");
    (void)irq;
}

void irq_register(uint32_t irq, irq_handler_t handler) {
    if (irq < MAX_IRQ) {
        irq_table[irq] = handler;
    }
}

