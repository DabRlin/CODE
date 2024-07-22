#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define BLOCK_SIZE 10

// 函数声明
int search(int arr[], int size, int value);
int binarySearch(int arr[], int size, int value);
int InterpolationSearch(int arr[], int size, int value);
int blockSearch(int arr[], int size, int value);

// 主函数
int main()
{
    int array[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        array[i] = i;
    }
    int target = 8;
    printf("%d的线性查找：%d\n", target, search(array, MAX_SIZE, target));
    printf("%d的二分查找：%d\n", target, binarySearch(array, MAX_SIZE, target));
    printf("%d的插值查找：%d\n", target, InterpolationSearch(array, MAX_SIZE, target));
    printf("%d的分块查找：%d\n", target, blockSearch(array, MAX_SIZE, target));
    return 0;
}

// 线性查找
int search(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

// 二分查找
int binarySearch(int arr[], int size, int value)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        if (arr[mid] > value)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// 插值查找
int InterpolationSearch(int arr[], int size, int value)
{
    int low = 0;
    int high = size - 1;
    while (low <= high && value >= arr[low] && value <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == value)
            {
                return low;
            }
            return -1;
        }
        int pos = low + (value - arr[low]) * (high - low) / (arr[high] - arr[low]);
        if (arr[pos] == value)
        {
            return pos;
        }
        if (arr[pos] > value)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }
    return -1;
}

// 分块查找
int blockSearch(int arr[], int size, int value)
{
    int blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int i;
    for (i = 0; i < blocks; i++)
    {
        int start = i * BLOCK_SIZE;
        int end = (i + 1) * BLOCK_SIZE < size ? (i + 1) * BLOCK_SIZE : size;
        if (arr[start] <= value && arr[end - 1] >= value)
        {
            break;
        }
    }
    if (i < blocks)
    {
        int start = i * BLOCK_SIZE;
        int end = (i + 1) * BLOCK_SIZE < size ? (i + 1) * BLOCK_SIZE : size;
        for (int j = start; j < end; j++)
        {
            if (arr[j] == value)
            {
                return j;
            }
        }
    }
    return -1;
}
