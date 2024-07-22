#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
int a, b;

void thread_fun1(void *arg)
{
    int sum;
    sum = a + b;
    printf("add:%d\n", sum);
    sleep(1);
}

void thread_fun2(void *arg)
{
    int sub;
    sub = a - b;
    printf("sub:%d\n", sub);
    sleep(1);
}

int main()
{
    pthread_t id1, id2;
    int err;
    scanf("%d%d", &a, &b);
    err = pthread_create(&id1, NULL, (void *)thread_fun1, NULL);
    if (err)
    {
        printf("create pthread error!\n");
        return 1;
    }
    err = pthread_create(&id2, NULL, (void *)thread_fun2, NULL);
    if (err)
    {
        printf("create pthread error!\n");
        return 1;
    }
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    exit(0);
}
