#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
void push(LinkedStack* stack, int val) 
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->next = stack->top; // �����¼ӽڵ�ָ����
    newNode->data = val;     // �����¼ӽڵ�������
    stack->top = newNode;       // ����ջ��
    stack->size++;           // ����ջ��С
}
