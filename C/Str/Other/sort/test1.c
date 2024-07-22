#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 函数声明
int compare(const void *a, const void *b);
void bubbleSort(int array[], int size);
void insertSort(int array[], int size);
void selectSort(int array[], int size);
void quickSort(int array[], int low, int high);
int getMax(int arrat[], int size);
void radixSort(int arrary[], int size, int exp);
void shellSort(int array[], int size);
void mergeSort(int array[], int left, int right);
void bucketSort(int array[], int size);

// 主函数
int main()
{
    int arr[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = MAX_SIZE - i;
    }
    qsort(arr, MAX_SIZE, sizeof(int), compare);
    printf("排序后的数组:\n");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}

// 函数实现
// qsort比较函数
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// 冒泡排序
void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (array[j] > array[i])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// 插入排序
void insertSort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// 选择排序
void selectSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

// 快速排序
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int *pivot = array[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// 获取最大值
int getMax(int array[], int size)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

// 对数组特定位进行计数排序
void countingSortForRadix(int array[], int size, int exp)
{
    int *output = (int *)malloc(size * sizeof(int));
    int count[10] = {0};
    for (int i = 0; i < size; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 0; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i++)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
    free(output);
}

// 基数排序
void radixSort(int arrary[], int size, int exp)
{
    int max = getMax(arrary, size);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSortForRadix(arrary, size, exp);
    }
}

// 希尔排序
void shellSort(int array[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

// 归并函数
void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k++] = L[i++];
        }
        else
        {
            array[k++] = R[j++];
        }
    }
    while (i < n1)
    {
        array[k++] = L[i++];
    }
    while (j < n1)
    {
        array[k++] = R[j++];
    }
    free(L);
    free(R);
}

// 归并排序
void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

// 桶排序
void bucketSort(int array[], int size)
{
    typedef struct Bucket
    {
        int count;
        float *values;
    } Bucket;
    int bucketCount = 10;
    Bucket *buckets = (Bucket *)malloc(bucketCount * sizeof(Bucket));

    for (int i = 0; i < bucketCount; i++)
    {
        buckets[i].count = 0;
        buckets[i].values = (float *)malloc(sizeof(float));
    }
    for (int i = 0; i < size; i++)
    {
        int bucketIndex = (array[i] - 1) / 10;
        buckets[bucketIndex].values[buckets[bucketIndex].count++] = array[i];
    }
    for (int i = 0; i < bucketCount; i++)
    {
        insertSort(buckets[i].values, buckets[i].values);
    }
    int index = 0;
    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 0; i < buckets[i].count; j++)
        {
            array[index++] = buckets[i].values[j];
        }
    }
    for (int i = 0; i < bucketCount; i++)
    {
        free(buckets[i].values);
    }
    free(buckets);
}