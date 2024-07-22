#include <unistd.h>
#include <signal.h>
#include <stdio.h>
int pid1, pid2;

main()
{
    int fd[2];
    char outpipe[100], inpipe[100];
    pipe(fd); /*父进程建立管道*/
    while ((pid1 = fork()) == -1)
        ;
    if (pid1 == 0) /*创建子进程pid1，直到成功*/
    {
        lockf(fd[1], 1, 0);                         /*对管道文件的写入端加锁，实现进程互斥。*/
        sprintf(outpipe, "child 1 is using pipe!"); /*把串放入数组outpipe中*/
        write(fd[1], outpipe, 50);                  /*向管道写长为50字节的串*/
        sleep(5);                                   /*自我阻塞5秒*/
        lockf(fd[1], 0, 0);                         /*解锁管道文件的写入端*/
        exit(0);                                    /*子进程1完成任务，终止*/
    }
    else /*父进程执行*/
    {
        while ((pid2 = fork()) == -1)
            ; /*创建子进程pid2，直到成功*/
        if (pid2 == 0)
        {
            lockf(fd[1], 1, 0); /*互斥*/
            sprintf(outpipe, "child 2 is using pipe!");
            write(fd[1], outpipe, 50);
            sleep(5);
            lockf(fd[1], 0, 0);
            exit(0); // 关闭pid2
        }
        else
        {
            wait(0);                 // 实现同步。父进程阻塞等待子进程写完后再读
            read(fd[0], inpipe, 50); // 从管道中读长为50字节的串
            printf("%s\n", inpipe);  // 输出读取的字符串
            wait(0);                 // 父进程再阻塞，等待另一个子进程写完后再读
            /*从fd[0]代表的读端读取50字节保存在buf缓冲区之后，文件的当前读写指针向后移动50字节*/
            read(fd[0], inpipe, 50);
            printf("%s\n", inpipe);
            exit(0); // 结束父进程
        }
    }
}