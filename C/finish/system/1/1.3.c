// 进程调度的程序，若无法应用头文件<bits/stdc++.h>，则安装g++，当作C++程序来使用就能正确应用头文件了。
#include <bits/stdc++.h> //
using namespace std;
#define MAXSIZE 30
typedef struct PCB
{
    char name[20];        // 进程名称(输入)
    int arrivetime;       // 到达时间 (输入)
    int running_time;     // 服务时间
    int priority;         // 优先级
    int start_time;       // 开始时间
    int done_time;        // 结束时间
    int copyRunning_time; // 用于时间片轮转
    float zztime;         // 记录该进程的周转时间（后期复制用）
    float dqzztime;       // 记录该进程的带权周转时间（后期复制用）
    PCB *next;
} Program;
typedef struct PCBQueue
{
    PCB *firstProg;
    PCB *LastProg;
    int size;
} PCBQueue;

// 函数声明
void print(PCB pro[], int num); // 输出每个进程的到达时间

void inputProgram(PCB pro[], int num); // 输入所有进程的具体信息

void PrintRunningprogram(PCB *pro); // 输出正在运行的进程的信息

void PrintReadyqueue(PCBQueue *ready_queue); // 输出就绪队列中的所有进程的信息

void PrintSortOfRunningprogram(PCB pro1[], int num); // 输出进程的运行顺序

void CopyProgram(PCB *pro1, PCB *pro2); // 将进程pro2的信息复制到进程pro1中

void Queueinit(PCBQueue *queue); // 初始化就绪队列

void EnterQueue(PCBQueue *queue, PCB *pro); // 将一个进程插入到就绪队列中

PCB *poll(PCBQueue *queue); // 将一个进程从就绪队列中删除

void sortWithEnterTime(PCB pro[], int num); // 将所有进程按到达时间升序排序

void EnterQueueOfRuntime(PCBQueue *ready_queue, PCB *program); // 将一个进程按运行时间长短插入就绪队列

void EnterQueueOfPriority(PCBQueue *ready_queue, PCB *program); // 将一个进程按优先级插入就绪队列

void FCFS(PCB pro[], int num); // 先来先服务调度算法

void SJF(PCB pro[], int num); // 短作业优先调度算法

void HPF(PCB pro[], int num); // 高优先级调度算法

void RR(PCB pro[], int num); // 时间片轮转调度算法

// 具体函数实现
void print(PCB pro[], int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        printf("%d ", pro[i].arrivetime);
    }
}

void inputProgram(PCB pro[], int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        PCB prog;
        printf("\t\t\t\t\t请输入第%d个进程的名字，到达时间，服务时间，优先级\n\t\t\t\t\t", i + 1);
        scanf("%s", prog.name);
        scanf("%d", &prog.arrivetime);
        scanf("%d", &prog.running_time);
        prog.copyRunning_time = prog.running_time;
        scanf("%d", &prog.priority);
        pro[i] = prog;
    }
}

void PrintRunningprogram(PCB *pro)
{
    printf("\t正在执行》》》进程%s\n", pro->name);
    printf("\t————————————————————————————————————————————————\n");
    printf("\t进程名字  到达时间  服务时间  优先级  开始时间  结束时间  周转时间  带权周转时间\n");
    printf("\t%s\t\t%d\t%d\t%d", pro->name, pro->arrivetime, pro->running_time, pro->priority);
    printf("\t%d\t%d\t   %5.2f\t%5.2f\n", pro->start_time, pro->done_time, pro->zztime, pro->dqzztime);
    printf("\t————————————————————————————————————————————————\n\n");
}

void PrintReadyqueue(PCBQueue *ready_queue)
{
    PCB *p;

    p = ready_queue->firstProg->next;
    if (!p)
    {
        printf("\t无进程处于就绪状态！\n");
        printf("\t————————————————————————————————————————————————\n\n\n");
        return;
    }
    printf("\t就绪队列：\n");
    printf("\t————————————————————————————————————————————————\n");
    printf("\t进程名字  到达时间  服务时间  优先级\n");
    while (p)
    {
        printf("\t%s\t\t%d\t%d\t%d\n", p->name, p->arrivetime, p->running_time, p->priority);
        p = p->next;
    }
    printf("\t————————————————————————————————————————————————\n");
    printf("\n\n\n");
}

void PrintSortOfRunningprogram(PCB pro1[], int num)
{
    int i;

    printf("\t进程运行顺序如下：\n");
    printf("\t————————————————————————————————————————————————\n");
    printf("\t进程名字  到达时间  服务时间  优先级  开始时间  结束时间  周转时间  带权周转时间\n");
    for (i = 0; i < num; i++)
    {
        printf("\t%s\t\t%d\t%d\t%d", pro1[i].name, pro1[i].arrivetime, pro1[i].running_time, pro1[i].priority);
        printf("\t%d\t%d\t   %5.2f\t%5.2f\n", pro1[i].start_time, pro1[i].done_time, pro1[i].zztime, pro1[i].dqzztime);
    }
    printf("\t————————————————————————————————————————————————\n\n\n");
}

void CopyProgram(PCB *pro1, PCB *pro2)
{
    memcpy(pro1->name, pro2->name, sizeof(pro2->name));
    pro1->arrivetime = pro2->arrivetime;
    pro1->running_time = pro2->running_time;
    pro1->priority = pro2->priority;
    pro1->start_time = pro2->start_time;
    pro1->done_time = pro2->done_time;
    pro1->zztime = pro2->zztime;
    pro1->dqzztime = pro2->dqzztime;
}

void Queueinit(PCBQueue *queue)
{
    if (queue == NULL)
    {
        return;
    }
    queue->size = 0;
    queue->LastProg = (PCB *)malloc(sizeof(PCB));
    queue->LastProg->next = NULL; // 注意加了此句
    queue->firstProg = queue->LastProg;
}

void EnterQueue(PCBQueue *queue, PCB *pro)
{
    // 加入进程队列
    queue->LastProg->next = (PCB *)malloc(sizeof(PCB));
    queue->LastProg = queue->LastProg->next;
    queue->LastProg->arrivetime = pro->arrivetime;
    memcpy(queue->LastProg->name, pro->name, sizeof(pro->name));
    queue->LastProg->priority = pro->priority;
    queue->LastProg->running_time = pro->running_time;
    queue->LastProg->copyRunning_time = pro->copyRunning_time;
    queue->LastProg->start_time = pro->start_time;
    queue->LastProg->next = NULL; // 注意加了此句
    queue->size++;
}

PCB *poll(PCBQueue *queue)
{
    PCB *temp;

    temp = queue->firstProg->next;
    if (temp == queue->LastProg)
    {
        queue->LastProg = queue->firstProg;
        queue->LastProg->next = NULL; // 注意加了此句
        queue->size--;
        return temp;
    }
    queue->firstProg->next = queue->firstProg->next->next;
    queue->size--;

    return temp;
}

void sortWithEnterTime(PCB pro[], int num)
{ // 将进程按到达时间（arrivetime）全部排序
    int i, j;
    PCB temp;

    for (i = 1; i < num; i++)
    {
        for (j = 0; j < num - i; j++)
        {
            if (pro[j].arrivetime > pro[j + 1].arrivetime)
            {
                temp = pro[j];
                pro[j] = pro[j + 1];
                pro[j + 1] = temp;
            }
        }
    }
}

void EnterQueueOfRuntime(PCBQueue *ready_queue, PCB *program)
{ // 按进程的运行时间，找到就绪队列中的相应位置并插入进去
    PCB *p, *q;
    p = ready_queue->firstProg->next;
    q = ready_queue->firstProg;

    while (p)
    {
        if (p->running_time > program->running_time)
        {
            program->next = p;
            q->next = program;
            break;
        }
        q = p;
        p = p->next;
    }
    if (!p)
    { // 如果就绪队列为空或该进程的运行时间最长，则将其插入到队尾
        ready_queue->LastProg->next = program;
        ready_queue->LastProg = program;
        program->next = NULL;
    }
    ready_queue->size++;
}

void EnterQueueOfPriority(PCBQueue *ready_queue, PCB *program)
{
    PCB *p, *q;
    p = ready_queue->firstProg->next;
    q = ready_queue->firstProg;

    while (p)
    {
        if (p->priority < program->priority)
        { // 优先级大的先执行
            program->next = p;
            q->next = program;
            break;
        }
        q = p;
        p = p->next;
    }
    if (!p)
    {
        ready_queue->LastProg->next = program;
        ready_queue->LastProg = program;
        program->next = NULL;
    }
    ready_queue->size++;
}

void FCFS(PCB pro[], int num)
{
    int time, done_time;
    int i, count, tt, pronum;
    float sum_T_time, sum_QT_time;
    PCB *curpro, *temp_PCB;

    printf("\n\t\t\t\t\t先来先服务算法进程调度模拟\n\n");
    printf("\t————————————————————————————————————————————————\n");
    count = 0;
    PCB pro2[100];
    sortWithEnterTime(pro, num);                            // 按照进入到达时间顺序排序
    PCBQueue *queue = (PCBQueue *)malloc(sizeof(PCBQueue)); // 定义就绪队列
    Queueinit(queue);                                       // 就绪队列初始化
    EnterQueue(queue, &pro[0]);                             // 将第一个进程送入就绪队列中
    time = pro[0].arrivetime;                               // 记录第一个进程的到达时间
    pronum = 1;                                             // 记录当前的进程数量
    sum_T_time = 0, sum_QT_time = 0;                        // sum_T_time记录总的周转时间，sum_QT_time 记录总的加权周转时间
    while (queue->size > 0)
    {
        curpro = poll(queue); // 从进程队列中取出一个进程
        if (time < curpro->arrivetime)
        {
            time = curpro->arrivetime;
        }
        done_time = time + curpro->running_time; // done_time为该进程的结束时间（开始时间+CPU运行时间）
        curpro->start_time = time;
        curpro->done_time = done_time;
        curpro->zztime = done_time - curpro->arrivetime;          // 周转时间
        curpro->dqzztime = curpro->zztime / curpro->running_time; // 带权周转时间
        sum_T_time += curpro->zztime;                             // sum_T_time总的周转时间更新
        sum_QT_time += curpro->dqzztime;                          // sum_T_time总的带权周转时间更新
        for (tt = time; tt <= done_time && pronum < num; tt++)
        { // 模拟进程的执行过程
            if (tt >= pro[pronum].arrivetime)
            {
                EnterQueue(queue, &pro[pronum]);
                pronum++;
            }
        }
        CopyProgram(&pro2[count], curpro);
        PrintRunningprogram(&pro2[count]);
        count++;
        if (queue->size != 0)
        {
            printf("\t就绪队列：\n");
            printf("\t————————————————————————————————————————————————\n");
            printf("\t进程 到达时间  服务时间 优先级\n");
            temp_PCB = queue->firstProg->next;
            for (i = queue->size; i > 0; i--)
            {
                printf("\t%s\t%d\t%d\t%d\n", temp_PCB->name, temp_PCB->arrivetime, temp_PCB->running_time, temp_PCB->priority);
                temp_PCB = temp_PCB->next;
            }
            printf("\t————————————————————————————————————————————————\n");
            printf("\n\n\n");
        }
        else
        {
            printf("\t无进程处于就绪状态!\n");
            printf("\t————————————————————————————————————————————————\n\n\n");
        }
        time += curpro->running_time;
        if (queue->size == 0 && pronum < num)
        {
            // 防止出现前一个进程执行完到下一个进程到达之间无进程进入
            EnterQueue(queue, &pro[pronum]);
            pronum++;
        }
    }
    PrintSortOfRunningprogram(pro2, count);
    // Print(pro2,count);
    printf("\t平均周转时间为:%.2f\n", sum_T_time / num);
    printf("\t平均带权周转时间为:%.2f\n", sum_QT_time / num);
}

void SJF(PCB pro[], int num)
{
    int time, done_time;
    float sum_T_time, sum_QT_time;
    int i, pronum;
    PCBQueue *ready_queue;
    PCB *curpro, pro1[MAXSIZE];

    printf("\n\t\t\t\t\t短作业优先算法进程调度模拟\n\n");
    printf("\t————————————————————————————————————————————————\n");
    sortWithEnterTime(pro, num);
    ready_queue = (PCBQueue *)malloc(sizeof(PCBQueue));
    if (!ready_queue)
    {
        printf("分配就绪队列头结点空间失败！");
        exit(1);
    }
    Queueinit(ready_queue);
    EnterQueueOfRuntime(ready_queue, &pro[0]);
    time = pro[0].arrivetime;
    pronum = 1; // 记录当前的进程
    sum_T_time = 0, sum_QT_time = 0;
    i = 0;
    while (ready_queue->size > 0)
    {
        curpro = poll(ready_queue); // 就绪队列中的队头进程进入CPU中运行
        if (time < curpro->arrivetime)
        { // 如果该进程与上一次运行的进程结束时间之间有间隔，则将CPU运行时间变为该进程到达时间
            time = curpro->arrivetime;
        }
        done_time = time + curpro->running_time;
        curpro->start_time = time;
        curpro->done_time = done_time;
        curpro->zztime = done_time - curpro->arrivetime;          // 周转时间
        curpro->dqzztime = curpro->zztime / curpro->running_time; // 带权周转时间
        // 打印正在运行的进程
        PrintRunningprogram(curpro);
        // 将curpro的信息复制到pro1[i]中
        CopyProgram(&pro1[i], curpro);
        i++;
        sum_T_time += curpro->zztime;
        sum_QT_time += curpro->dqzztime;
        while (pronum < num)
        { // 将在CPU中的进程运行的时间内到达的进程放入就绪队列
            if (pro[pronum].arrivetime <= done_time)
            {
                EnterQueueOfRuntime(ready_queue, &pro[pronum]);
                pronum++;
            }
            else
            {
                break;
            }
        }
        // 打印就绪队列
        PrintReadyqueue(ready_queue);
        time = done_time;
        if (ready_queue->size == 0 && pronum < num)
        { // 防止出现前一个进程执行完到下一个进程到达之间无进程进入
            EnterQueueOfRuntime(ready_queue, &pro[pronum]);
            pronum++;
        }
    }
    PrintSortOfRunningprogram(pro1, num);
    printf("\t平均周转时间为:%.2f\n", sum_T_time / num);
    printf("\t平均带权周转时间为:%.2f\n", sum_QT_time / num);
}

void HPF(PCB pro[], int num)
{
    int time, done_time;
    float sum_T_time, sum_QT_time;
    int i, pronum;
    PCBQueue *ready_queue;
    PCB *curpro, pro1[MAXSIZE];

    printf("\n\t\t\t\t\t高优先级算法进程调度模拟\n\n");
    printf("\t————————————————————————————————————————————————\n");
    sortWithEnterTime(pro, num);
    ready_queue = (PCBQueue *)malloc(sizeof(PCBQueue));
    if (!ready_queue)
    {
        printf("分配就绪队列头结点内存失败！");
        exit(1);
    }
    Queueinit(ready_queue);
    EnterQueueOfPriority(ready_queue, &pro[0]);
    time = pro[0].arrivetime;
    pronum = 1; // 记录当前的进程
    sum_T_time = 0, sum_QT_time = 0;
    i = 0;
    while (ready_queue->size > 0)
    {
        curpro = poll(ready_queue); // 就绪队列中的队头进程进入CPU中运行
        if (time < curpro->arrivetime)
        { // 如果该进程与上一次运行的进程结束时间之间有间隔，则将CPU运行时间变为该进程到达时间
            time = curpro->arrivetime;
        }
        done_time = time + curpro->running_time;
        curpro->start_time = time;
        curpro->done_time = done_time;
        curpro->zztime = done_time - curpro->arrivetime;                  // 周转时间
        curpro->dqzztime = curpro->zztime / (curpro->running_time + 0.0); // 带权周转时间
        // 打印正在运行的进程
        PrintRunningprogram(curpro);
        // 将curpro的信息复制到pro1[i]中
        CopyProgram(&pro1[i], curpro);
        i++;
        sum_T_time += curpro->zztime;
        sum_QT_time += curpro->dqzztime;
        while (pronum < num)
        { // 将在CPU中的进程运行的时间内到达的进程放入就绪队列
            if (pro[pronum].arrivetime <= done_time)
            {
                EnterQueueOfPriority(ready_queue, &pro[pronum]);
                pronum++;
            }
            else
            {
                break;
            }
        }
        // 打印就绪队列
        PrintReadyqueue(ready_queue);
        time = done_time;
        if (ready_queue->size == 0 && pronum < num)
        { // 防止出现前一个进程执行完到下一个进程到达之间无进程进入
            EnterQueueOfPriority(ready_queue, &pro[pronum]);
            pronum++;
        }
    }
    PrintSortOfRunningprogram(pro1, num);
    printf("\t平均周转时间为:%.2f\n", sum_T_time / num);
    printf("\t平均带权周转时间为:%.2f\n", sum_QT_time / num);
}
void RR(PCB pro[], int num)
{ // 时间片轮转算法
    int time, done_time, T_time;
    int i, count, tt, timeslice, pronum;
    float QT_time, sum_T_time, sum_QT_time;
    PCB *curpro, *temp_PCB;

    printf("\n\t\t\t\t\t时间片轮转算法进程调度模拟\n\n");
    printf("\t————————————————————————————————————————————————\n");
    count = 0;
    PCB pro2[100];
    printf("\t请输入时间片大小:");
    scanf("%d", &timeslice);
    sortWithEnterTime(pro, num);
    PCBQueue *queue = (PCBQueue *)malloc(sizeof(PCBQueue));
    Queueinit(queue);
    pro[0].start_time = pro[0].arrivetime;
    EnterQueue(queue, &pro[0]);
    time = 0;
    pronum = 1;
    sum_T_time = 0, sum_QT_time = 0;
    while (queue->size > 0)
    {
        curpro = poll(queue); // 从就绪队列中取出一个进程
        if (time < curpro->arrivetime)
        {
            time = curpro->arrivetime; // 计算开始运行时间
        }
        if (timeslice >= curpro->running_time)
        { // 如果剩余时间小于时间片，则此任务完成
            for (tt = time; tt <= time + curpro->running_time && pronum < num; tt++)
            { // 模拟进程的执行过程
                if (tt >= pro[pronum].arrivetime)
                { // 统计从此任务开始到结束之间有几个进程到达
                    pro[pronum].start_time = tt;
                    EnterQueue(queue, &pro[pronum]);
                    pronum++;
                }
            }
            time += curpro->running_time;
            curpro->running_time = 0;
            curpro->done_time = time;
            T_time = curpro->done_time - curpro->start_time;
            QT_time = T_time / (curpro->copyRunning_time + 0.0);
            sum_T_time += T_time;
            sum_QT_time += QT_time;

            strcpy(pro2[count].name, curpro->name);
            pro2[count].arrivetime = curpro->arrivetime;
            pro2[count].running_time = curpro->copyRunning_time;
            pro2[count].priority = curpro->priority;
            pro2[count].start_time = curpro->start_time;
            pro2[count].done_time = curpro->done_time;
            pro2[count].zztime = T_time;
            pro2[count].dqzztime = QT_time;
            count++;

            printf("\n\t执行完成》》》进程%s！\n", curpro->name);
            printf("\t————————————————————————————————————————————————\n");
            if (queue->size != 0)
            {
                printf("\t就绪队列：\n");
                printf("\t————————————————————————————————————————————————\n");
                printf("\t进程 到达时间  服务时间  优先级\n");
                PCB *temp_PCB = queue->firstProg->next;
                for (i = queue->size; i > 0; i--)
                {
                    printf("\t%s\t%d\t%d\t   %d\n", temp_PCB->name, temp_PCB->arrivetime, temp_PCB->running_time, temp_PCB->priority);
                    temp_PCB = temp_PCB->next;
                }
                printf("\t————————————————————————————————————————————————\n\n\n");
            }
            else
            {
                printf("\t 无进程处于就绪状态！\n");
                printf("\t————————————————————————————————————————————————\n\n\n");
            }

            if (queue->size == 0 && pronum < num)
            { // 防止出现前一个进程执行完到下一个进程到达之间无进程进入
                pro[pronum].start_time = pro[pronum].arrivetime;
                EnterQueue(queue, &pro[pronum]);
                pronum++;
            }
            continue;
        }
        for (tt = time; tt <= time + timeslice && pronum < num; tt++)
        { // 模拟进程的执行过程
            if (tt >= pro[pronum].arrivetime)
            { // 统计从此任务开始到结束之间有几个进程到达
                pro[pronum].start_time = tt;
                EnterQueue(queue, &pro[pronum]);
                pronum++;
            }
        }

        printf("\n\t正在执行》》》进程%s\n", curpro->name);
        printf("\t————————————————————————————————————————————————\n");
        if (queue->size != 0)
        {
            printf("\t就绪队列：\n");
            printf("\t————————————————————————————————————————————————\n");
            printf("\t进程 到达时间  服务时间  优先级\n");
            temp_PCB = queue->firstProg->next;
            for (i = queue->size; i > 0; i--)
            {
                printf("\t%s\t%d\t%d\t%d\n", temp_PCB->name, temp_PCB->arrivetime, temp_PCB->running_time, temp_PCB->priority);
                temp_PCB = temp_PCB->next;
            }
            printf("\t————————————————————————————————————————————————\n\n\n");
        }
        else
        {
            printf("\t 无进程处于就绪状态！\n");
            printf("\t————————————————————————————————————————————————\n\n\n");
        }

        time += timeslice;
        curpro->running_time -= timeslice;
        EnterQueue(queue, curpro); // 当前程序未完成  继续添加到队列中

        if (queue->size == 0 && pronum < num)
        { // 防止出现前一个进程执行完到下一个进程到达之间无进程进入
            pro[pronum].start_time = pro[pronum].arrivetime;
            EnterQueue(queue, &pro[pronum]);
            pronum++;
        }
    }
    PrintSortOfRunningprogram(pro2, count);
    printf("\t平均周转时间为:%.2f\n", sum_T_time / num);
    printf("\t平均带权周转时间为:%.2f\n", sum_QT_time / num);
}

void menu()
{
    printf("\t\t\t\t\t<<-------------操作系统进程调度算法模拟程序----------——>>\n");
    printf("\t\t\t\t\t1.先来先服务算法\n");
    printf("\t\t\t\t\t2.短进程优先算法\n");
    printf("\t\t\t\t\t3.高优先级算法\n");
    printf("\t\t\t\t\t4.时间片轮转算法\n");
    printf("\t\t\t\t\t5.退出\n");
    printf("\t\t\t\t\t请选择进程调度算法:");
}

int main()
{
    int n, t = 1;
    int proNum, choice;
    PCB pro[MAXSIZE], temp_pro[MAXSIZE];

    printf("\n\n\t\t\t\t\t<<-------------进程初始化----------——>>\n");
    printf("\t\t\t\t\t请输入进程的个数：");
    scanf("%d", &proNum);
    inputProgram(pro, proNum);
    while (t)
    {
        menu();
        memcpy(temp_pro, pro, (sizeof(pro) / sizeof(pro[0])) * sizeof(PCB));
        scanf("%d", &n);
        while (n <= 0 || n > 5)
        {
            printf("\t\t\t指令不正确，请重新输入指令： ");
            scanf("%d", &n);
        }
        system("cls");
        switch (n)
        {
        case 1:
        {
            FCFS(temp_pro, proNum);
            break;
        }
        case 2:
        {

            SJF(temp_pro, proNum);
            break;
        }
        case 3:
        {
            HPF(temp_pro, proNum);
            break;
        }
        case 4:
        {
            RR(temp_pro, proNum);
            break;
        }
        case 5:
        {
            t = 0;
            break;
        }
        }
        getchar();
        printf("\n\t按任意键继续.......");
        getchar();
        system("cls");
    }
    system("cls");
    printf("\n\n\t\t\t\t\t您已成功退出系统！！！\n");

    return 0;
}
