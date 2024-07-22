#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

/* 定义读写锁 */
pthread_rwlock_t rwlock;

/* 定义共享资源变量 */
int g_nNum = 0;

/* 读操作 其他线程允许读操作 不允许写操作 */
void *fun1(void *arg)
{
    while (1)
    {
        pthread_rwlock_rdlock(&rwlock);
        {
            printf("read thread 1 == %d\n", g_nNum);
        }
        pthread_rwlock_unlock(&rwlock);

        sleep(1);
    }
}

/* 读操作，其他线程允许读操作，不允许写操作 */
void *fun2(void *arg)
{
    while (1)
    {
        pthread_rwlock_rdlock(&rwlock);
        {
            printf("read thread 2 == %d\n", g_nNum);
        }
        pthread_rwlock_unlock(&rwlock);

        sleep(1);
    }
}

/* 写操作，其它线程都不允许读或写操作 */
void *fun3(void *arg)
{
    while (1)
    {
        pthread_rwlock_wrlock(&rwlock);
        {
            g_nNum++;
            printf("write thread 1\n");
        }
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
}
/* 写操作，其它线程都不允许读或写操作 */
void *fun4(void *arg)
{
    while (1)
    {
        pthread_rwlock_wrlock(&rwlock);
        {
            g_nNum++;
            printf("write thread 2\n");
        }
        pthread_rwlock_unlock(&rwlock);

        sleep(1);
    }
}

int main(int arc, char *argv[])
{
    pthread_t ThrId1, ThrId2, ThrId3, ThrId4;

    pthread_rwlock_init(&rwlock, NULL); // 初始化一个读写锁

    /* 创建测试线程 */
    pthread_create(&ThrId1, NULL, fun1, NULL);
    pthread_create(&ThrId2, NULL, fun2, NULL);
    pthread_create(&ThrId3, NULL, fun3, NULL);
    pthread_create(&ThrId4, NULL, fun4, NULL);

    /* 等待线程结束，回收其资源 */
    pthread_join(ThrId1, NULL);
    pthread_join(ThrId2, NULL);
    pthread_join(ThrId3, NULL);
    pthread_join(ThrId4, NULL);

    pthread_rwlock_destroy(&rwlock); // 销毁读写锁

    return 0;
}
