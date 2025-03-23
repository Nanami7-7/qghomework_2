#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include <ctype.h>
#include <string.h>

// 操作数栈节点结构
typedef struct OperandNode {
    int data;
    struct OperandNode* next;
} OperandNode, * OperandStack;

// 运算符栈节点结构
typedef struct OperatorNode {
    char op;
    struct OperatorNode* next;
} OperatorNode, * OperatorStack;

// 操作数栈初始化
void initOperand(OperandStack* s) { *s = NULL; }

// 运算符栈初始化
void initOperator(OperatorStack* s) { *s = NULL; }

// 操作数入栈
void pushOperand(OperandStack* s, int data) {
    OperandNode* newNode = (OperandNode*)malloc(sizeof(OperandNode));
    newNode->data = data;
    newNode->next = *s;
    *s = newNode;
}

// 操作数出栈
int popOperand(OperandStack* s) {
    if (*s == NULL) {
        fprintf(stderr, "操作数栈空\n");
        exit(EXIT_FAILURE);
    }
    OperandNode* temp = *s;
    int data = temp->data;
    *s = (*s)->next;
    free(temp);
    return data;
}

// 运算符入栈
void pushOperator(OperatorStack* s, char op) {
    OperatorNode* newNode = (OperatorNode*)malloc(sizeof(OperatorNode));
    newNode->op = op;
    newNode->next = *s;
    *s = newNode;
}

// 运算符出栈
char popOperator(OperatorStack* s) {
    if (*s == NULL) {
        fprintf(stderr, "运算符栈空\n");
        exit(EXIT_FAILURE);
    }
    OperatorNode* temp = *s;
    char op = temp->op;
    *s = (*s)->next;
    free(temp);
    return op;
}

// 获取栈顶运算符
char topOperator(OperatorStack s) {
    return s ? s->op : '\0';
}

// 获取运算符优先级
int getPriority(char op) {
    switch (op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '(': return 0;
    default: return -1;
    }
}

// 执行运算
void calculate(OperatorStack* opStack, OperandStack* numStack) {
    // 检查操作数数量
    if (*numStack == NULL || (*numStack)->next == NULL) {
        fprintf(stderr, "表达式错误\n");
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
            fprintf(stderr, "除零错误\n");
            exit(EXIT_FAILURE);
        }
        pushOperand(numStack, b / a);
        break;
    }
}

// 主逻辑
int evaluateExpression(const char* expr) {
    OperandStack numStack;
    OperatorStack opStack;
    initOperand(&numStack);
    initOperator(&opStack);

    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        if (expr[i] == ' ') continue;

        if (isdigit(expr[i])) {  // 处理数字
            int num = 0;
            while (i < len && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;  // 回退一位
            pushOperand(&numStack, num);
        }
        else if (expr[i] == '(') {  // 左括号直接入栈
            pushOperator(&opStack, '(');
        }
        else if (expr[i] == ')') {  // 右括号处理
            while (topOperator(opStack) != '(') {
                if (!opStack) {
                    fprintf(stderr, "括号不匹配\n");
                    exit(EXIT_FAILURE);
                }
                calculate(&opStack, &numStack);
            }
            popOperator(&opStack);  // 弹出左括号
        }
        else {  // 处理运算符
            while (opStack && getPriority(expr[i]) <= getPriority(topOperator(opStack))) {
                calculate(&opStack, &numStack);
            }
            pushOperator(&opStack, expr[i]);
        }
    }

    // 处理剩余运算符
    while (opStack) {
        if (topOperator(opStack) == '(') {
            fprintf(stderr, "括号不匹配\n");
            exit(EXIT_FAILURE);
        }
        calculate(&opStack, &numStack);
    }

    int result = popOperand(&numStack);
    if (numStack != NULL) {
        fprintf(stderr, "表达式错误\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

