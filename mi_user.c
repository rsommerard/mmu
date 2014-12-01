#include <stdlib.h>
#include <stdio.h>
#include "hardware.h"
#include "mi_syscall.h"


int sum(void *ptr) 
{
    int i;
    int sum = 0;
    
    for(i = 0; i < PAGE_SIZE * N/2 ; i++)
        sum += ((char*)ptr)[i];
    return sum;
}

