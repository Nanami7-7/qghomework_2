#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void destroyStack(LinkedStack* stack) 
{
    while (!isEmpty(stack)) {
        pop(stack); // ���ε������нڵ㣬�ͷ��ڴ�
    }
    stack->size = 0; // ȷ��ջ��СΪ0
}