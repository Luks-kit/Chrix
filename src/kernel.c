#include "uart.h"
#include "mem.h"
#include "irq.h"
#include "sched.h"

void k_main(void) {
    uart_init();
    uart_puts("Kernel started! Welcome to CHRix ARM64!\n");

    irq_init();

    while (1) {
        uart_puts("Tick...\n");
        for (volatile int i = 0; i < 1000000; i++); // crude delay
    }
}

