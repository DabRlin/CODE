#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// 队列结构定义
typedef struct queue
{
    int data[MAX];
    int front;
    int rear;
    int size;
} Queue;

// 函数声明
void initQueue(Queue *q);
void enQueue(Queue *q, int value);
int deQueue(Queue *q);
int getFront(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
int getSize(Queue *q);
void printQueue(Queue *q);

// 主函数
int main()
{
    Queue q;
    initQueue(&q);

    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    printQueue(&q);

    if (deQueue(&q) != -1)
    {
        printf("Dequeued: %d\n", deQueue(&q));
    }

    if (getFront(&q))
    {
        printf("Front element: %d\n", getFront(&q));
    }

    printf("Queue size: %d\n", getSize(&q));

    return 0;
}

// 函数实现

// 初始化队列
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

// 入队
void enQueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("队列已满\n");
        return;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX;
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
    int num = q->front;
    q->front = (q->front + 1) % MAX;
    q->size--;
    return q->data[num];
}

int getFront(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空\n");
        return -1;
    }
    return q->data[q->front];
}

// 判断队列是否为空
int isEmpty(Queue *q)
{
    return q->size == 0;
}

// 判断队列是否为满
int isFull(Queue *q)
{
    return q->size == MAX;
}

// 返回队列长度
int getSize(Queue *q)
{
    if (q != NULL)
    {
        return q->size;
    }
    return -1;
}

// 打印全队列
void printQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空\n");
        return;
    }
    for (int i = 0; i < q->size; i++)
    {
        printf("%d - ", q->data[(q->front + i) % MAX]);
    }
    printf("\n");
}
