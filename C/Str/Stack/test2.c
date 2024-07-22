#include <stdio.h>
#include <stdlib.h>

// 栈节点定义
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 栈定义
typedef struct stack
{
    Node *top;
} Stack;

// 函数声明
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void initStack(Stack *s);
int isEmpty(Stack *s);
void freeStack(Stack *s);
void printStack(Stack *s);

// 主函数
int main()
{
    Stack s;
    initStack(&s);

    // 测试操作
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printStack(&s); // 输出：30 - 20 - 10 -

    int value = pop(&s);
    printf("出栈元素：%d\n", value); // 输出：30
    printStack(&s);                  // 输出：20 - 10 -

    value = peek(&s);
    printf("栈顶元素：%d\n", value); // 输出：20

    freeStack(&s);

    return 0;
}

// 函数实现

// 初始化栈
void initStack(Stack *s)
{
    s->top = NULL;
}

// 判断栈空
int isEmpty(Stack *s)
{
    return s->top == NULL;
}

// 入栈
void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("内存分配失败");
        return;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// 出栈
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    int value;
    Node *temp = s->top;
    value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

// 获取栈顶元素
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s->top->data;
}

// 打印全栈
void printStack(Stack *s)
{
    if (isEmpty(s))
    {
        printf("当前栈为空\n");
        return;
    }
    Node *temp = s->top;
    while (temp != NULL)
    {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 释放栈
void freeStack(Stack *s)
{
    Node *temp = s->top;
    while (temp != NULL)
    {
        Node *freeNode = temp;
        temp = temp->next;
        free(freeNode);
    }
    s->top = NULL;
}