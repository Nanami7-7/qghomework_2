#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void push(LinkedStack* stack, int val) 
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->next = stack->top; // 更新新加节点指针域
    newNode->data = val;     // 更新新加节点数据域
    stack->top = newNode;       // 更新栈顶
    stack->size++;           // 更新栈大小
}
