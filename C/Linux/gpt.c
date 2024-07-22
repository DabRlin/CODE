#include <stdio.h>

// 函数原型：交换两个整数的值
void swap(int *a, int *b);

int main() {
    int x = 5, y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);

    // 调用 swap() 函数，传递 x 和 y 的地址
    swap(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}

// 函数定义：交换两个整数的值
void swap(int *a, int *b) {
    int temp;

    temp = *a; // 保存 a 指针所指向的值
    *a = *b;   // 将 b 指针所指向的值赋给 a 指针所指向的位置
    *b = temp; // 将保存的值赋给 b 指针所指向的位置
}