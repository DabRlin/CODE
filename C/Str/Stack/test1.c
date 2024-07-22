#include <stdio.h>
#include <stdlib.h>

#define MAX 50
// 栈结构定义
typedef struct stack
{
    int data[MAX];
    int top;
} Stack;

// 函数声明
void initStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void printStack(Stack *s);
// 主函数
int main()
{
    return 0;
}

// 函数实现

// 初始化栈
void initStack(Stack *s)
{
    s->top = -1;
}

// 判断栈空
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// 判断栈满
int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

// 入栈
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("栈已满无法入栈");
        return;
    }
    s->data[++s->top] = value;
}

// 出栈并返回值
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("栈已空无法出栈");
        return;
    }
    return s->data[s->top--];
}

// 打印栈
void printStack(Stack *s)
{
    if (isEmpty(s))
    {
        printf("栈为空");
        return;
    }
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}