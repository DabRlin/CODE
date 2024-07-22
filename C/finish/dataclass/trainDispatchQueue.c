#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义队列结构
typedef struct {
    char data[MAX_SIZE];
    int front, rear;
} Queue;

// 初始化队列
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

// 入队操作
void enqueue(Queue *q, char car) {
    if (q->rear == MAX_SIZE - 1) {
        printf("队列已满\n");
        exit(1);
    }
    q->data[++q->rear] = car;
}

// 出队操作
char dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("队列为空\n");
        exit(1);
    }
    return q->data[++q->front];
}

// 火车调度函数
void trainDispatch(char *sequence) {
//创建两个队列用于存储S和H
    Queue s, h;
    initQueue(&s);
    initQueue(&h);

    for (int i = 0; sequence[i] != '\0'; i++) {
        if (sequence[i] == 'S') {
            enqueue(&s, 'S');
        } else if (sequence[i] == 'H') {
            enqueue(&h, 'H');
        }
    }

    printf("调度结果：");
    while (s.front != s.rear) {
        printf("%c", dequeue(&s));
    }
    while (h.front != h.rear) {
        printf("%c", dequeue(&h));
    }
    printf("\n");
}

int main() {
    char sequence[MAX_SIZE];
    printf("请输入车厢序列（如HSHSHSSSH）: ");
    scanf("%s", sequence);
    trainDispatch(sequence);
    return 0;
}
