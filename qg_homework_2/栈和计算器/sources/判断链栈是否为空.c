#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
int isEmpty(LinkedStack* stack) 
{
    return stack->top == NULL;
}