#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define true 1
// 生产者ID
int product_id = 0;
// 消费者ID
int consumer_id = 0;
// 缓冲区大小
int N;
// 生产者数目
int producerNum;
// 消费者数目
int consumerNum;
// 类型定义 int型 信号
typedef int semaphore;
// 类型定义 int型 商品
typedef int item;
// 定义 商品类型的缓冲数组
item *buffer;
// 头索引，输入索引，头指针，用于标识生产者的输入位置
int in = 0;
// 尾索引，输出索引，尾指针，用于标识消费者的输出位置
int out = 0;
// 产品数目
int proCount = 0;
// mutex 互斥变量，empty 缓冲区空白大小，full 缓冲区非空白大小，proCmutex 生产者互斥变量
semaphore mutex = 1, empty, full = 0, proCmutex = 1;
// pthread_create函数创建进程时，需要一个指针类型的函数作为参数，所以定义为指针类型。
// producer与consumer作为线程的执行体。
void *producer(void *a)
{
    int id = ++product_id;
    while (true)
    {
        int flag = 0;
        // 如果缓冲区已满报错
        while (empty <= 0)
        {
            printf("生产者%d：缓冲区已满！阻塞中……\n", id);
            flag = 1;
            sleep(1);
        }
        if (flag == 1)
            printf("生产者%d因缓冲区有空位唤醒！\n", id);
        // 如果有其他生产者占用进程则互斥，检查有没有其他生产者生产产品
        flag = 0;
        while (proCmutex <= 0)
        {
            printf("生产者%d生产阻塞中……\n", id);
            flag = 1;
            sleep(1);
        };
        // 将互斥变量置0，代表已占用
        proCmutex--;
        if (flag == 1)
            printf("生产者%d生产唤醒！\n", id);
        // 产品号+1
        proCount++;
        printf("生产者%d：生产一个产品ID%d!\n", id, proCount);

        // 总互斥变量，检查有没有其他进程修改缓冲区数据
        flag = 0;
        while (mutex <= 0)
        {
            printf("生产者%d装入阻塞中……\n", id);
            sleep(1);
            flag = 1;
        };
        // 占用进程
        mutex--;

        if (flag == 1)
            printf("生产者%d装入唤醒，装入产品ID%d，缓冲区位置为%d！\n", id, proCount, in);
        else
            printf("生产者%d装入产品ID%d，缓冲区位置为%d！\n", id, proCount, in);
        // 否则缓冲区空白大小-1
        empty--;
        // 缓冲区头指针放入产品
        buffer[in] = proCount;
        // 头指针+1
        in = (in + 1) % N;

        // 缓冲区非空白大小+1
        full++;
        // 解除占用
        mutex++;
        // 解除生产占用
        proCmutex++;
        // 睡一觉
        sleep(1);
    }
}

void *consumer(void *b)
{
    int id = ++consumer_id;
    while (true)
    {
        int flag = 0;
        while (full <= 0)
        {
            printf("\t\t\t\t消费者%d：缓冲区为空！阻塞中……\n", id);
            flag = 1;
            sleep(1);
        }
        full--;
        if (flag == 1)
            printf("\t\t\t\t消费者%d因缓冲区有产品唤醒！\n", id);
        flag = 0;

        while (mutex <= 0)
        {
            printf("\t\t\t\t消费者%d消费阻塞中……\n", id);
            sleep(1);
        };
        mutex--;
        if (flag == 1)
            printf("\t\t\t\t消费者%d消费唤醒！\n", id);
        int nextc = buffer[out];
        buffer[out] = 0; // 消费完将缓冲区设置为0
        empty++;
        printf("\t\t\t\t消费者%d：消费一个产品ID%d,缓冲区位置为%d\n", id, nextc, out);
        out = (out + 1) % N;
        mutex++;
        sleep(1);
    }
}

int main()
{
    int tempnum;
    // 输入生产者数目
    printf("请输入生产者数目:\n");
    scanf("%d", &tempnum);
    producerNum = tempnum;
    // 输入消费者数目
    printf("请输入消费者数目:\n");
    scanf("%d", &tempnum);
    consumerNum = tempnum;
    // 输入缓冲区大小
    printf("请输入缓冲区大小:\n");
    scanf("%d", &tempnum);
    N = tempnum;
    empty = N;
    buffer = (item *)malloc(N * sizeof(item));
    for (int i = 0; i < N; i++)
    {
        buffer[i] = 0;
    }
    // pthread_t是线程结构，用来保存线程相关数据，可以理解为线程类型，声明线程对象（这里声明的时线程对象数组）
    pthread_t threadPool[producerNum + consumerNum]; // 声明了线程数组作为线程池
    int i;
    for (i = 0; i < producerNum; i++)
    {
        pthread_t temp;
        // if语句中，第一个参数是线程指针，第二个是线程属性指针，第三个是函数指针，即线程要执行的代码
        // 函数通过producer函数指针创建对象，赋值给temp作为线程执行
        if (pthread_create(&temp, NULL, producer, NULL) == -1)
        {
            printf("ERROR, fail to create producer%d\n", i);
            exit(1);
        }
        // 将temp作为能够执行的线程放入了进程池
        threadPool[i] = temp;
    } // 创建生产者进程放入线程池

    // 对于消费者进程也同样创建进程
    for (i = 0; i < consumerNum; i++)
    {
        pthread_t temp;
        if (pthread_create(&temp, NULL, consumer, NULL) == -1)
        {
            printf("ERROR, fail to create consumer%d\n", i);
            exit(1);
        }
        threadPool[i + producerNum] = temp;
    } // 创建消费者进程放入线程池

    void *result;
    for (i = 0; i < producerNum + consumerNum; i++)
    {
        // pthread_join函数用与等待线程的结束
        // 等待的是子进程的结束，因为如果主进程不等待子进程而直接结束，子进程将没有执行就被杀死。
        if (pthread_join(threadPool[i], &result) == -1)
        {
            printf("fail to recollect\n");
            exit(1);
        }
    } // 运行线程池
    return 0;
}
