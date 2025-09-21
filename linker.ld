ENTRY(_start)

SECTIONS
{
    . = 0x40000000;   /* QEMU virt machine default kernel load address */

    .text.boot : {
        *(.text.boot)
    }

    .text : {
        *(.text*)
    }

    .rodata : {
        *(.rodata*)
    }

    .data : {
        __data_start = .;
        *(.data*)
        __data_end = .;
    }

    .bss : {
        __bss_start = .;
        *(.bss*)
        *(COMMON)
        __bss_end = .;
    }

    /DISCARD/ : { *(.note*) *(.comment*) }
}

