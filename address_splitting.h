#pragma once

#include "mmu.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

/**
 * --------------------------------- PROBLEM 1 --------------------------------------
 * Checkout PDF Section 3 For this Problem
 *
 * Split the virtual address into its virtual page number and offset.
 * 
 * HINT: 
 *      -Examine the global defines in pagesim.h, which will be necessary in 
 *      implementing these functions.
 * ----------------------------------------------------------------------------------
 */

/**
 * Gets the Virtual Page Number (VPN) from the Virtual Address.
 * 
 * @param addr The virtual address to get the VPN from.
 * @returns The VPN
 */
static inline vpn_t get_vaddr_vpn(vaddr_t addr) {
    // Get the mask
    // int mask = (1 << (VADDR_LEN - OFFSET_LEN)) - 1;
    // int mask = (1 << (sizeof(vpn_t) * 8)) - 1;
    int mask = NUM_PAGES - 1;

    // Shift the Address by 
    return (vpn_t) ((addr >> OFFSET_LEN) & mask);
}

static inline uint16_t get_vaddr_offset(vaddr_t addr) {
    int mask = (1 << (OFFSET_LEN)) - 1;
    return (uint16_t) (addr & mask);
}

static inline pte_t* get_page_table(pfn_t ptbr, uint8_t *memory) {
    return 0;
}

static inline pte_t* get_page_table_entry(vpn_t vpn, pfn_t ptbr, uint8_t *memory) {
    return 0;
}

static inline paddr_t get_physical_address(pfn_t pfn, uint16_t offset) {
    return 0;
}

#pragma GCC diagnostic pop
