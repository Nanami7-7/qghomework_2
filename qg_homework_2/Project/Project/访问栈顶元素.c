#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int peek(LinkedStack* stack) 
{
    if (isEmpty(stack)) {
        printf("Õ»¿Õ£¬ÎÞÕ»¶¥ÔªËØ£¡\n");
        exit(1);
    }
    return stack->top->data;
}