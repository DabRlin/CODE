#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <time.h>
#include <sys/wait.h>

#define NUM_PHILOSOPHERS 5 // 信号量数组，分别用于维护每一位哲学家左手和右手的筷子，避免发生死锁
#define NUM_chopstick 5    // 筷子数量

/*哲学家当前状态的定义*/
#define THINKING 0 // 思考中
#define HUNGRY 1   // 饥饿中
#define EATING 2   // 吃饭中

int state[NUM_PHILOSOPHERS]; // 数组，存储哲学家当前的状态
int sem_id;                  // 用于存储信号量集的标识符

/*打印当前在思考中的哲学家*/
void think(int philosopher)
{
    printf("Philosopher %d is thinking.\n", philosopher);
    sleep(rand() % 5); // 模拟思考的过程，思考需要时间
}

/*打印当前在拿筷子的哲学家*/
void take_chopstick(int philosopher)
{
    state[philosopher] = HUNGRY;
    printf("Philosopher %d is hungry.\n", philosopher);

    // wait for left chopstick
    struct sembuf sops;         // 定义sembuf结构体变量sops，它包含三个成员变量sem_num、sem_op、sem_flg
    sops.sem_num = philosopher; // sem_num表示信号量在信号量集中的编号
    sops.sem_op = -1;           // sem_op表示信号量要进入的状态，操作数option为 -1，即为P操作
    sops.sem_flg = 0;           // sem_flg控制信号量操作的行为，通常为0，表示操作完成后立即返回
    semop(sem_id, &sops, 1);
    printf("Philosopher %d is putting up left chopstick.\n", philosopher);

    // wait for right chopstick
    sops.sem_num = (philosopher + 1) % NUM_chopstick;
    semop(sem_id, &sops, 1);
    printf("Philosopher %d is putting up right chopstick.\n", philosopher);
}

void put_chopstick(int philosopher)
{
    state[philosopher] = THINKING;

    /*放下左筷子*/
    struct sembuf sops;
    sops.sem_num = philosopher;
    sops.sem_op = 1; // 操作数option为1，即为V操作
    sops.sem_flg = 0;
    semop(sem_id, &sops, 1);
    printf("Philosopher %d is putting down left chopstick.\n", philosopher);

    /*放下右筷子*/
    sops.sem_num = (philosopher + 1) % NUM_chopstick;
    semop(sem_id, &sops, 1);
    printf("Philosopher %d is putting down right chopstick.\n", philosopher);
}
/*打印正在吃饭的哲学家*/
void eat(int philosopher)
{
    state[philosopher] = EATING;
    printf("Philosopher %d is eating.\n", philosopher);
    sleep(rand() % 5); // 模拟哲学家吃饭，吃饭需要花费一段时间
}

int main()
{
    srand(time(NULL));                                 // 为随机数生成器提供种子
    sem_id = semget(IPC_PRIVATE, NUM_chopstick, 0600); // 用初始值创建信号量集
    if (sem_id < 0)
    {
        perror("semget failed");
        exit(1); // 返回非0，表示运行有错，异常终止
    }

    for (int i = 0; i < NUM_chopstick; i++)
    {
        semctl(sem_id, i, SETALL, 1);
    }

    /*创建哲学家进程*/
    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        if (fork() == 0)
        {
            // 哲学家的进程
            while (1)
            {
                think(i);
                take_chopstick(i);
                eat(i);
                put_chopstick(i);
            }
        }
    }

    while (wait(NULL) > 0)
        ;                        // 等待所有子程序结束
    semctl(sem_id, 0, IPC_RMID); // 删除信号量集
    return 0;
}
