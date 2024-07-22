#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 75 // 定义共享区关键词

int shmid;
int *addr;

void CLIENT()
{
    int i;
    shmid = shmget(SHMKEY, 1024, 0777); // 获取共享区，长度1024，关键词SHMKEY
    addr = shmat(shmid, 0, 0);          // 共享区起始地址为addr
    for (i = 9; i >= 0; i--)
    {
        while (*addr != -1)
            ;
        printf("(client)sent\n"); // 打印（client）sent
        *addr = i;                // 把i赋给addr
    }
    exit(0);
}

void SERVER()
{
    shmid = shmget(SHMKEY, 1024, 0777 | IPC_CREAT); // 创建共享区
    addr = shmat(shmid, 0, 0);                      // 共享区起始地址为addr
    do
    {
        *addr = -1;
        while (*addr == -1)
            ;
        printf("(server)received\n"); // 服务进程使用共享区
    } while (*addr);
    shmctl(shmid, IPC_RMID, 0);
    exit(0);
}

int main()
{
    struct timeval start, end;
    long seconds, microseconds;

    gettimeofday(&start, NULL);

    if (fork())
        SERVER();
    if (fork())
        CLIENT();

    wait(0);
    wait(0);

    gettimeofday(&end, NULL);

    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    long elapsed = seconds * 1000000 + microseconds;

    printf("传输时间：%ld 微秒\n", elapsed);

    return 0;
}
