#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void destroyStack(LinkedStack* stack) 
{
    while (!isEmpty(stack)) {
        pop(stack); // 依次弹出所有节点，释放内存
    }
    stack->size = 0; // 确保栈大小为0
}