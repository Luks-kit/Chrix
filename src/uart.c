#include "uart.h"
#include <stdint.h>

#define UART0_BASE 0x09000000   // QEMU virt machine

static inline void mmio_write(uint64_t reg, uint32_t val) {
    *(volatile uint32_t*)reg = val;
}
static inline uint32_t mmio_read(uint64_t reg) {
    return *(volatile uint32_t*)reg;
}

void uart_init(void) {
    // PL011 UART init (bare minimum)
}

void uart_putc(char c) {
    while (mmio_read(UART0_BASE + 0x18) & (1 << 5)); // TXFF
    mmio_write(UART0_BASE, c);
}

void uart_puts(const char *s) {
    while (*s) {
        if (*s == '\n') uart_putc('\r');
        uart_putc(*s++);
    }
}

