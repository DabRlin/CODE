#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int pid1, pid2; // 存储两个子进程的PID号；
int main()
{
    int fd[2];                      // 打开文件的文件描述符
    char OutPipe[100], InPipe[100]; // 存储要写入管道的字符串
    pipe(fd);                       // 创建无名管道
    while ((pid1 = fork()) == -1)
        ; // 用fork函数创建子进程
    if (pid1 == 0)
    {
        //	sleep(1);
        read(fd[0], InPipe, 50); // 将字符串从管道中读出到inpipe
        printf("i am the first child. %s\n", InPipe);
        exit(0); // 安全退出
    }
    else
    {
        while ((pid2 = fork()) == -1)
            ;
        if (pid2 == 0)
        {
            //	sleep(1);
            read(fd[0], InPipe, 50);                      // 将字符串从管道中读出到inpipe
            printf("i am the second child.%s\n", InPipe); // 打印inpipe内数据
            exit(0);
        }
        else
        { // 父进程
            sprintf(OutPipe, "father is sending a message to Child process 1!");
            write(fd[1], OutPipe, 50);
            sprintf(OutPipe, "father is sending a message to Child process 2!");
            write(fd[1], OutPipe, 50);
            wait(0);
            wait(0);
            exit(0);
        }
    }
    return 0;
}
