#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    /* ��ʼ��ջ */
    LinkedStack* stack = Init_LinkedStack();

    /* Ԫ����ջ */
    push(stack, 1);
    push(stack, 3);
    push(stack, 2);
    push(stack, 5);
    push(stack, 4);

   
    printStack(stack);


    /* ����ջ��Ԫ�� */
    int val = peek(stack);
    printf("ջ��Ԫ�� top = %d\r\n", val);

    /* Ԫ�س�ջ */
    val = pop(stack);
    printf("��ջԪ�� pop = %d, ��ջ�� stack =  ", val);
    printStack(stack);

    /* ��ȡջ�ĳ��� */
    printf("ջ�ĳ��� size = %d\n", getSize(stack));

    /* �ж��Ƿ�Ϊ�� */
    int empty = isEmpty(stack);
    printf("ջ�Ƿ�Ϊ�� = %s\n", empty ? "true" : "false");

    // �ͷ��ڴ�
    destroyStack(stack);

   
        char expr[100];
        printf("�������������ʽ��");
        fgets(expr, sizeof(expr), stdin);
        expr[strcspn(expr, "\n")] = '\0';  // ȥ�����з�

        printf("��������%d\n", evaluateExpression(expr));
       
    


    
    return 0;

}