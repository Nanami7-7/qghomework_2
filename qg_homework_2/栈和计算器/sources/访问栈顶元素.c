#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int peek(LinkedStack* stack) 
{
    if (isEmpty(stack)) {
        printf("ջ�գ���ջ��Ԫ�أ�\n");
        exit(1);
    }
    return stack->top->data;
}