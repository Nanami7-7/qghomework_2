#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void printStack(LinkedStack* stack) 
{
    StackNode* current = stack->top; // ��ջ����ʼ����
    printf("��ջ���ݣ���ջ����ջ�ף�: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next; // �ƶ�����һ���ڵ�
    }
    printf("\n");
}