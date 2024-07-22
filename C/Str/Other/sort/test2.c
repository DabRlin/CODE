#include <stdio.h>
#include <stdlib.h>

// 结构体定义
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 函数声明
Node *createNode(int data);
void insertNode(Node **head, int data);
Node *search(Node *head, int value);
void deleteNode(Node **head, int data);
void printNode(Node *head);
void quickSort(Node **head);
void bubbleSort(Node **head);
void selectSort(Node **head);
void insertSort(Node **head);
void shellSort(Node **head);
void radixSort(Node **head);
void mergeSort(Node **head);
void bucketSort(Node **head);

// 主函数
int main()
{
    return 0;
}

// 函数实现

// 创建节点
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 插入节点
void insertNode(Node **head, int data)
{
    Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 删除节点
void deleteNode(Node **head, int data)
{
    if (*head == NULL)
    {
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (prev = NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
}

// 打印节点
void printNode(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 查找节点
Node *search(Node *head, int value)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// 冒泡排序
void bubbleSort(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    int swap;
    Node *temp;
    Node *stop = NULL;
    while (swap)
    {
        swap = 0;
        temp = *head;
        while (temp->next != stop)
        {
            if (temp->data > temp->next->data)
            {
                int data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = data;
                swap = 1;
            }
            temp = temp->next;
        }

        stop = temp;
    }
}

// 选择排序
void selectSort(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    Node *temp = *head;
    while (temp)
    {
        Node *min = temp;
        Node *current = temp->next;
        while (current->next != NULL)
        {
            if (min->data < current->data)
            {
                min = current;
            }
            current = current->next;
        }
        int data = temp->data;
        temp->data = min->data;
        min->data = data;
        temp = temp->next;
    }
}

// 插入排序
void insertSort(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    Node *sorted;
    Node *current = *head;
    while (current != NULL)
    {
        Node *next = current->next;
        if (sorted->data >= current->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next != NULL && temp->data < current->data)
            {

                temp = temp->next;
            }
            current->next = temp;
            temp = current;
        }
        current = next;
    }
    return sorted;
}

// 快速排序
Node *partition(Node *low, Node *high, Node **newLow, Node **newHigh)
{
    int pivot = high->data;
    Node *prev = NULL;
    Node *curr = low;
    Node *tail = high;

    while (curr != high)
    {
        if (curr->data < pivot)
        {
            if ((*newLow) == NULL)
            {
                (*newLow) = curr;
            }
            prev = curr;
            curr = curr->next;
        }
        else
        {
            if (prev)
            {
                prev->next = curr->next;
            }
            Node *next = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = next;
        }
    }
    if ((*newLow) == NULL)
    {
        (*newLow) = high;
    }
    (*newHigh) = tail;
    return high;
}
Node *getTail(Node *cur)
{
    while (cur != NULL && cur->next != NULL)
    {
        cur = cur->next;
    }
    return cur;
}
Node *quickSortRecur(Node *low, Node *high)
{
    if (!low || low == high)
    {
        return low;
    }
    Node *newLow = NULL;
    Node *newHigh = NULL;
    Node *pivot = partition(low, high, newLow, newHigh);

    if (newLow != pivot)
    {
        Node *temp = newLow;
        while (temp->next != pivot)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        newLow = quickSortRecur(newLow, temp);
        temp = getTail(newLow);
        temp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newHigh);
    return newLow;
}

void quickSort(Node **head)
{
    (*head) = quickSortRecur(*head, getTail(*head));
}

// 基数排序
void countingSortForRadix(Node **head, int exp)
{
    Node *temp = *head;
    int num = 0;
    while (temp != NULL)
    {
        num++;
        temp = temp->next;
    }

    Node *output[num];
    int count[10] = {0};
    temp = *head;
    while (temp != NULL)
    {
        count[(temp->data / exp) % 10]++;
        temp = temp->next;
    }
    for (int i = 0; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    temp = *head;
    while (temp != NULL)
    {
        output[count[(temp->data) / exp % 10] - 1] = temp;
        count[(temp->data / exp) % 10]--;
        temp = temp->next;
    }
    for (int i = 0; i < num; i++)
    {
        temp = output[i];
        if (i == 0)
        {
            *head = temp;
        }
        else
        {
            output[i - 1]->next = temp;
        }
    }
}
void radixSort(Node **head)
{
    int max;
    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }

        temp = temp->next;
    }
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSortForRadix(head, exp);
    }
}

// 归并排序
Node *sortedMerge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    Node *result = NULL;
    if ((a->data > b->data))
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}
void frontBackSplit(Node *source, Node **frontRef, Node **backRef)
{
    Node *fast;
    Node *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}
void mergeSort(Node **head)
{
    if ((*head == NULL) || ((*head)->data == NULL))
    {
        return;
    }
    Node *temp = head;
    Node *a;
    Node *b;
    frontBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *head = sortedMerge(a, b);
}

// 希尔排序
void shellSort(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    int n = 0;
    Node *temp = *head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            Node *current = *head;
            for (int j = 0; j < i; j++)
            {
                current = current->next;
            }

            int data = current->data;
            Node *prev = current;
            for (int j = i; j >= gap; j -= gap)
            {
                Node *tempNode = *head;
                for (int k = 0; k < j - gap; k++)
                {
                    tempNode = tempNode->next;
                }
                if (tempNode->data > data)
                {
                    prev->data = tempNode->data;
                    prev = tempNode;
                }
                else
                {
                    break;
                }
            }
            prev->data = data;
        }
    }
}

// 桶排序
typedef struct Bucket
{
    int count;
    float *values;
} Bucket;

void insertBucket(float arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(Node **head)
{
    if (head == NULL)
    {
        return;
    }
    int num;
    Node *temp = *head;
    while (temp != NULL)
    {
        num++;
        temp = temp->next;
    }

    int bucketCount = 10;
    Bucket *buckets = (Bucket *)malloc(bucketCount * sizeof(Bucket));
    for (int i = 0; i < bucketCount; i++)
    {
        buckets[i].count = 0;
        buckets[i].values = (float *)malloc(num * sizeof(float));
    }
    temp = *head;
    while (temp != NULL)
    {
        int bucketIndex = (temp->data - 1) % 10;
        buckets[bucketIndex].values[buckets[bucketIndex].count++] = temp->data;
        temp = temp->next;
    }
    for (int i = 0; i < bucketCount; i++)
    {
        insertBucket(buckets[i].values, buckets[i].count);
    }

    Node *current = *head;
    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 0; i < buckets[i].count; i++)
        {
            current->data = buckets[i].values[j];
            current = current->next;
        }
    }
    for (int i = 0; i < bucketCount; i++)
    {
        free(buckets[i].values);
    }
    free(buckets);
}