#include <stdio.h>
#include <stdlib.h>

// 定义节点
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 定义队列
typedef struct Queue
{
    Node *front;
    Node *rear;
    int size;
} Queue;

// 函数声明
void initQueue(Queue *q);
void enQueue(Queue *q, int value);
int deQueue(Queue *q);
void printQueue(Queue *q);
int isEmpty(Queue *q);
int getSize(Queue *q);
int getFront(Queue *q);
void freeQueue(Queue *q);

// 主函数
int main()
{
    Queue q;
    initQueue(&q);

    // 测试队列操作
    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    printQueue(&q);

    printf("队列长度: %d\n", getSize(&q));
    printf("队首元素: %d\n", getFront(&q));

    printf("出队元素: %d\n", deQueue(&q));
    printQueue(&q);

    freeQueue(&q);
    printQueue(&q); // 确认队列已被释放

    return 0;
}

// 函数实现

// 初始化队列
void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// 入队
void enQueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("节点分配内存失败\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q))
    {
        q->front = newNode;
    }
    else
    {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    q->size++;
}

// 出队
int deQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空\n");
        return -1;
    }
    int value = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    temp = NULL;
    q->size--;
    return value;
}

// 打印全队列
void printQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空\n");
        return;
    }
    Node *current = q->front;
    while (current != NULL)
    {
        printf("%d -", current->data);
        current = current->next;
    }
    printf("\n");
}

// 判断队列是否为空
int isEmpty(Queue *q)
{
    return q->size == 0;
}

// 获取队列长度
int getSize(Queue *q)
{
    return q->size;
}

// 获取队首元素
int getFront(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空\n");
        return -1;
    }
    return q->front->data;
}

// 释放队列
void freeQueue(Queue *q)
{
    while (!isEmpty(q))
    {
        deQueue(q);
    }
}