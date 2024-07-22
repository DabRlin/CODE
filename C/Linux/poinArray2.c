#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // 数组名作为指针
    int(*p)[4] = arr;
    printf("Using array name as pointer: %d\n", p[1][2]); // 输出 7

    // 指向二维数组元素的指针
    int *q = &arr[0][0];
    printf("Using pointer to elements: %d\n", *(q + 6)); // 输出 7

    // 指针数组
    int *ptrArr[3];
    for (int i = 0; i < 3; i++)
    {
        ptrArr[i] = (int *)malloc(4 * sizeof(int));
        for (int j = 0; j < 4; j++)
        {
            ptrArr[i][j] = arr[i][j];
        }
    }
    printf("Using pointer array: %d\n", ptrArr[2][3]); // 输出 12

    // 释放动态分配的内存
    for (int i = 0; i < 3; i++)
    {
        free(ptrArr[i]);
    }

    // 二维数组
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    printf("二维数组:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // 使用 int ** 的动态分配数组
    int **ptrArr = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        ptrArr[i] = (int *)malloc(4 * sizeof(int));
    }

    // 初始化
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ptrArr[i][j] = arr[i][j];
        }
    }

    printf("\n动态分配的数组 (int **):\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", ptrArr[i][j]);
        }
        printf("\n");
    }

    // 释放动态分配的内存
    for (int i = 0; i < 3; i++)
    {
        free(ptrArr[i]);
    }
    free(ptrArr);

    return 0;
}
