#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
int pop(LinkedStack* stack) 
{
    StackNode* temp = stack->top; // ��ʱ����ջ���ڵ�
    int val = temp->data;       // ��ȡջ���ڵ��ֵ
    stack->top = stack->top->next; // ����ջ��ָ��
    free(temp);                   // �ͷ�ԭջ���ڵ���ڴ�
    stack->size--;                // ջ��С��1
    return val;
}
