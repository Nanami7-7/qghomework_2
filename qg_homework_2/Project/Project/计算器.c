#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include <ctype.h>
#include <string.h>

// ������ջ�ڵ�ṹ
typedef struct OperandNode {
    int data;
    struct OperandNode* next;
} OperandNode, * OperandStack;

// �����ջ�ڵ�ṹ
typedef struct OperatorNode {
    char op;
    struct OperatorNode* next;
} OperatorNode, * OperatorStack;

// ������ջ��ʼ��
void initOperand(OperandStack* s) { *s = NULL; }

// �����ջ��ʼ��
void initOperator(OperatorStack* s) { *s = NULL; }

// ��������ջ
void pushOperand(OperandStack* s, int data) {
    OperandNode* newNode = (OperandNode*)malloc(sizeof(OperandNode));
    newNode->data = data;
    newNode->next = *s;
    *s = newNode;
}

// ��������ջ
int popOperand(OperandStack* s) {
    if (*s == NULL) {
        fprintf(stderr, "������ջ��\n");
        exit(EXIT_FAILURE);
    }
    OperandNode* temp = *s;
    int data = temp->data;
    *s = (*s)->next;
    free(temp);
    return data;
}

// �������ջ
void pushOperator(OperatorStack* s, char op) {
    OperatorNode* newNode = (OperatorNode*)malloc(sizeof(OperatorNode));
    newNode->op = op;
    newNode->next = *s;
    *s = newNode;
}

// �������ջ
char popOperator(OperatorStack* s) {
    if (*s == NULL) {
        fprintf(stderr, "�����ջ��\n");
        exit(EXIT_FAILURE);
    }
    OperatorNode* temp = *s;
    char op = temp->op;
    *s = (*s)->next;
    free(temp);
    return op;
}

// ��ȡջ�������
char topOperator(OperatorStack s) {
    return s ? s->op : '\0';
}

// ��ȡ��������ȼ�
int getPriority(char op) {
    switch (op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '(': return 0;
    default: return -1;
    }
}

// ִ������
void calculate(OperatorStack* opStack, OperandStack* numStack) {
    // ������������
    if (*numStack == NULL || (*numStack)->next == NULL) {
        fprintf(stderr, "���ʽ����\n");
        exit(EXIT_FAILURE);
    }

    char op = popOperator(opStack);
    int a = popOperand(numStack);
    int b = popOperand(numStack);

    switch (op) {
    case '+': pushOperand(numStack, b + a); break;
    case '-': pushOperand(numStack, b - a); break;
    case '*': pushOperand(numStack, b * a); break;
    case '/':
        if (a == 0) {
            fprintf(stderr, "�������\n");
            exit(EXIT_FAILURE);
        }
        pushOperand(numStack, b / a);
        break;
    }
}

// ���߼�
int evaluateExpression(const char* expr) {
    OperandStack numStack;
    OperatorStack opStack;
    initOperand(&numStack);
    initOperator(&opStack);

    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        if (expr[i] == ' ') continue;

        if (isdigit(expr[i])) {  // ��������
            int num = 0;
            while (i < len && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;  // ����һλ
            pushOperand(&numStack, num);
        }
        else if (expr[i] == '(') {  // ������ֱ����ջ
            pushOperator(&opStack, '(');
        }
        else if (expr[i] == ')') {  // �����Ŵ���
            while (topOperator(opStack) != '(') {
                if (!opStack) {
                    fprintf(stderr, "���Ų�ƥ��\n");
                    exit(EXIT_FAILURE);
                }
                calculate(&opStack, &numStack);
            }
            popOperator(&opStack);  // ����������
        }
        else {  // ���������
            while (opStack && getPriority(expr[i]) <= getPriority(topOperator(opStack))) {
                calculate(&opStack, &numStack);
            }
            pushOperator(&opStack, expr[i]);
        }
    }

    // ����ʣ�������
    while (opStack) {
        if (topOperator(opStack) == '(') {
            fprintf(stderr, "���Ų�ƥ��\n");
            exit(EXIT_FAILURE);
        }
        calculate(&opStack, &numStack);
    }

    int result = popOperand(&numStack);
    if (numStack != NULL) {
        fprintf(stderr, "���ʽ����\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

