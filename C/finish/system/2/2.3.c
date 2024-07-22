#include <stdio.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <sys/time.h>

struct msgform
{
    long mtype;
    char mtext[1024];
} m;

int isQuit(char *p)
{
    return (p[0] == &apos; q & apos; &&p[1] == &apos; u & apos; &&p[2] == &apos; i & apos; &&p[3] == &apos; t & apos;);
}

int main(void)
{
    m.mtype = 1;
    int qid = msgget(12345, IPC_CREAT | 400);

    // 记录开始时间
    struct timeval start, end;
    gettimeofday(&start, NULL);

    while (1)
    {
        printf("Lucy: ");
        fgets(m.mtext, sizeof(m.mtext), stdin);

        if (isQuit(m.mtext))
        {
            printf("\n聊天结束。\n");
            break;
        }

        msgsnd(qid, &m, sizeof(m.mtext), 0);
        msgrcv(qid, &m, sizeof(m.mtext), 2, 0);
        printf("Peter: %s\n", m.mtext);
        m.mtype = 1;
    }

    // 记录结束时间
    gettimeofday(&end, NULL);

    // 计算时间差
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long elapsed = seconds * 1000000 + microseconds;

    printf("传输时间：%ld 微秒\n", elapsed);

    // 在实际应用中，需要正确地关闭和删除消息队列
    msgctl(qid, IPC_RMID, 0);

    return 0;
}
