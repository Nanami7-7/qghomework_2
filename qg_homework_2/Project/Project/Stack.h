typedef struct StackNode 
{
    int data;               
    struct StackNode* next; 
} StackNode;

// 定义链栈结构体
typedef struct LinkedStack 
{
    StackNode* top;// 栈顶指针
    int size;
} LinkedStack;

LinkedStack* Init_LinkedStack();
int isEmpty(LinkedStack* stack);
int pop(LinkedStack* stack);
void push(LinkedStack* stack, int val);
int peek(LinkedStack* stack);
int getSize(LinkedStack* stack);
void destroyStack(LinkedStack* stack);
void printStack(LinkedStack* stack);
int getPriority(char op);