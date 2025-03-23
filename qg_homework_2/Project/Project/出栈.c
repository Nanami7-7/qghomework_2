#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
int pop(LinkedStack* stack) 
{
    StackNode* temp = stack->top; // 临时保存栈顶节点
    int val = temp->data;       // 获取栈顶节点的值
    stack->top = stack->top->next; // 更新栈顶指针
    free(temp);                   // 释放原栈顶节点的内存
    stack->size--;                // 栈大小减1
    return val;
}
