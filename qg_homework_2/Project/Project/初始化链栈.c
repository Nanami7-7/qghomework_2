#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

LinkedStack* Init_LinkedStack() 
{
    LinkedStack* s = malloc(sizeof(LinkedStack));
    s->top = NULL;
    s->size = 0;
    return s;
}