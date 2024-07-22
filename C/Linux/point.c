#include <stdio.h>
#include <stdlib.h>

// 函数声明，参数是一个指向指针的指针
void modifyPointer(int **ptr) {
    printf("在 modifyPointer 中: ptr 的地址: %p, ptr 的值 (p 的地址): %p, ptr 指向的值: %p\n", (void *)&ptr, (void *)ptr, (void *)*ptr);
    *ptr = (int *)malloc(sizeof(int));  // 修改 ptr 所指向的指针，使其指向新分配的内存
    **ptr = 20;  // 设置新分配的内存的值
    printf("在 modifyPointer 中 malloc 之后: ptr 的地址: %p, ptr 的值 (p 的地址): %p, ptr 指向的值: %p, 新地址的值: %d\n", (void *)&ptr, (void *)ptr, (void *)*ptr, **ptr);
}

void modifyValue(int *ptr) {
    printf("在 modifyValue 中: ptr 的地址: %p, ptr 的值 (num 的地址): %p, ptr 指向的值: %d\n", (void *)&ptr, (void *)ptr, *ptr);
    *ptr = 10;  // 修改 ptr 所指向的变量的值
    printf("在 modifyValue 中修改之后: ptr 的地址: %p, ptr 的值 (num 的地址): %p, ptr 指向的值: %d\n", (void *)&ptr, (void *)ptr, *ptr);
}

int main() {
    int num = 5;
    int *p = &num;

    printf("在 modifyValue 之前: num 的地址: %p, num 的值: %d\n", (void *)&num, num);
    modifyValue(&num);  // 传递 num 的地址
    printf("在 modifyValue 之后: num 的地址: %p, num 的值: %d\n", (void *)&num, num);

    printf("\n在 modifyPointer 之前: p 的地址: %p, p 的值: %p\n", (void *)&p, (void *)p);
    modifyPointer(&p);  // 传递指向指针的指针
    printf("在 modifyPointer 之后: p 的地址: %p, p 的值 (分配的内存地址): %p, 新地址的值: %d\n", (void *)&p, (void *)p, *p);

    free(p);  // 释放分配的内存
    return 0;
}
