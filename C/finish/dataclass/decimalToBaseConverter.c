#include <stdio.h>
#include <stdlib.h>

// 定义栈结构
typedef struct {
    int top;
    int* array;
} Stack;

// 创建一个新栈
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->array = (int*)malloc(sizeof(int) * capacity);
    return stack;
}

// 判断栈是否为空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 入栈操作
void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// 出栈操作
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return -1;
}

// 十进制转换为d进制的函数
void decimalToBase(int decimal, int base) {
    Stack* stack = createStack(100); // 创建一个栈，用于存储转换后的数字

    while (decimal > 0) {
        int remainder = decimal % base;
        push(stack, remainder);
        decimal /= base;
    }

    printf("转换结果为：");
    while (!isEmpty(stack)) {
        int digit = pop(stack);
        if (digit < 10) {
            printf("%d", digit);
        } else {
            printf("%c", 'A' + digit - 10); // 将大于等于10的余数转换为对应的字母
        }
    }

    printf("\n");
}

int main() {
    int n, d;
    printf("请输入一个十进制数：");
    scanf("%d", &n);
    printf("请输入目标进制（例如，2代表二进制，8代表八进制，16代表十六进制）：");
    scanf("%d", &d);

    decimalToBase(n, d);

    return 0;
}
