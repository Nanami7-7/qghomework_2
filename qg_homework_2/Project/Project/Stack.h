typedef struct StackNode 
{
    int data;               
    struct StackNode* next; 
} StackNode;

// ������ջ�ṹ��
typedef struct LinkedStack 
{
    StackNode* top;// ջ��ָ��
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