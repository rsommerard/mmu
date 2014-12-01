#ifndef _H_MI_SYSCALL_H_
#define _H_MI_SYSCALL_H_

#define SYSCALL_SWTCH_0 16
#define SYSCALL_SWTCH_1 17

#define MMU_IRQ         13
#define MMU_FAULT_ADDR  0xCD
#define TLB_ADD_ENTRY   0xCE	
#define MMU_CMD         0x66	


#define PAGE_SIZE 4096

#define PM_PAGES 256
#define PM_SIZE PM_PAGES * PAGE_SIZE  /* 1Mo */

#define VM_PAGES 4096
#define VM_SIZE VM_PAGES * PAGE_SIZE  /* 16 Mo */

#define N 2048


#define vpage_of_vaddr(vaddr) (((vaddr) >> 12) & 0xFFF)

struct tlb_entry_s
{
    unsigned tlbe_cfu:8;
    unsigned tlbe_virtual_page:12;
    unsigned tlbe_physical_page:8;
    unsigned tlbe_x_access:1;
    unsigned tlbe_w_access:1;
    unsigned tlbe_r_access:1;
    unsigned tlbe_used:1;
};

int ppage_of_vaddr(int process, unsigned vaddr);

int sum(void *ptr);

#endif
