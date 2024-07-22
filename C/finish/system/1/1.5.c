#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t mutex;   // 互斥锁
pthread_cond_t empty;    // 为空的条件变量
pthread_cond_t notempty; // 非空的条件变量

int buf[20];
int temp = 0;
void *producer(void *arg)
{
    int i;
    for (i = 0; i < 20; i++)
    {
        printf("producer is running!\n");
        pthread_mutex_lock(&mutex); // 申请互斥锁
        while (temp == 1)
        {
            pthread_cond_wait(&empty, &mutex); // 等待缓存区为空
        }
        temp = 1;
        memcpy(&buf[i], &i, 4); // 写入数据
        printf("已写入数据:%d\n", i);
        pthread_cond_signal(&notempty); // 唤醒消费者
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *arg)
{
    int i;
    for (i = 0; i < 20; i++)
    {
        printf("consume is running!\n");
        pthread_mutex_lock(&mutex);
        while (temp == 0)
        {
            pthread_cond_wait(&notempty, &mutex); // 等待缓冲区不为空
        }
        temp = 0;
        sleep(2);
        printf("读出数据：%d  \n", buf[i]);
        printf("已清除数据:%d\n", buf[i]);
        memset(&buf[i], 0, 4);
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t pt, ct;
    pthread_mutex_init(&mutex, NULL);   // 初始化互斥锁
    pthread_cond_init(&empty, NULL);    // 初始化为空时的条件变量
    pthread_cond_init(&notempty, NULL); // 初始化不为空的条件变量

    pthread_create(&pt, NULL, producer, NULL);
    pthread_create(&ct, NULL, consumer, NULL);
    sleep(1);

    pthread_cond_signal(&empty); // 唤醒生产者

    pthread_join(pt, NULL);
    pthread_join(ct, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&empty);
    pthread_cond_destroy(&notempty);

    return 0;
}
