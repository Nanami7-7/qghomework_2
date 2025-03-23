#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    /* 初始化栈 */
    LinkedStack* stack = Init_LinkedStack();

    /* 元素入栈 */
    push(stack, 1);
    push(stack, 3);
    push(stack, 2);
    push(stack, 5);
    push(stack, 4);

   
    printStack(stack);


    /* 访问栈顶元素 */
    int val = peek(stack);
    printf("栈顶元素 top = %d\r\n", val);

    /* 元素出栈 */
    val = pop(stack);
    printf("出栈元素 pop = %d, 出栈后 stack =  ", val);
    printStack(stack);

    /* 获取栈的长度 */
    printf("栈的长度 size = %d\n", getSize(stack));

    /* 判断是否为空 */
    int empty = isEmpty(stack);
    printf("栈是否为空 = %s\n", empty ? "true" : "false");

    // 释放内存
    destroyStack(stack);

   
        char expr[100];
        printf("请输入算术表达式：");
        fgets(expr, sizeof(expr), stdin);
        expr[strcspn(expr, "\n")] = '\0';  // 去除换行符

        printf("计算结果：%d\n", evaluateExpression(expr));
       
    


    
    return 0;

}