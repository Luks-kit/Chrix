.global exception_vectors
exception_vectors:
    b sync_el1t      // Synchronous EL1t
    b irq_el1t       // IRQ EL1t
    b fiq_el1t       // FIQ EL1t
    b serr_el1t      // SError EL1t
    // ... repeat for EL1h, EL0_64, etc.

