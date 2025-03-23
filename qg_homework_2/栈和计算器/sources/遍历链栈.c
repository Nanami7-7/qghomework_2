#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void printStack(LinkedStack* stack) 
{
    StackNode* current = stack->top; // 从栈顶开始遍历
    printf("链栈内容（从栈顶到栈底）: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next; // 移动到下一个节点
    }
    printf("\n");
}