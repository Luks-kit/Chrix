.section .text.boot
.globl _start
_start:
    // set up stack
    ldr x0, =stack_top
    mov sp, x0

    // clear BSS
    ldr x1, =__bss_start
    ldr x2, =__bss_end
1:  cmp x1, x2
    b.hs 2f
    str xzr, [x1], #8
    b 1b
2:

    bl k_main

hang:
    wfe
    b hang

.section .bss
.align 16
stack:
    .skip 4096
stack_top:

