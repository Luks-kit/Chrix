.section .vectors, "ax"
.align 11               // 2KB alignment
.global vectors
vectors:
    // Current EL, SP0
    b sync_current_el_sp0
    b irq_current_el_sp0
    b fiq_current_el_sp0
    b serr_current_el_sp0

    // Current EL, SPx
    b sync_current_el_spx
    b irq_current_el_spx
    b fiq_current_el_spx
    b serr_current_el_spx

    // Lower EL, AArch64
    b sync_lower_el_aarch64
    b irq_lower_el_aarch64
    b fiq_lower_el_aarch64
    b serr_lower_el_aarch64

    // Lower EL, AArch32 
    b sync_lower_el_aarch32
    b irq_lower_el_aarch32
    b fiq_lower_el_aarch32
    b serr_lower_el_aarch32

// Example handler stubs
sync_current_el_sp0:
    // save registers, branch to C handler
    bl exception_handler
    eret

irq_current_el_sp0:
    bl irq_handler
    eret

fiq_current_el_sp0:
    bl fiq_handler
    eret

serr_current_el_sp0:
    bl serr_handler
    eret


