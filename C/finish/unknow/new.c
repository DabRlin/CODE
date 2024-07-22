#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopher_id = *(int*)arg;
    int left_chopstick = philosopher_id;
    int right_chopstick = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // 奇数号哲学家先拿左边的筷子，偶数号哲学家先拿右边的筷子
        if (philosopher_id % 2 == 0) {
            pthread_mutex_lock(&chopsticks[left_chopstick]);
            pthread_mutex_lock(&chopsticks[right_chopstick]);
        } else {
            pthread_mutex_lock(&chopsticks[right_chopstick]);
            pthread_mutex_lock(&chopsticks[left_chopstick]);
        }

        printf("哲学家 %d 正在进餐\n", philosopher_id);
        sleep(2);

        printf("哲学家 %d 进餐完毕\n", philosopher_id);

        // 释放筷子
        pthread_mutex_unlock(&chopsticks[left_chopstick]);
        pthread_mutex_unlock(&chopsticks[right_chopstick]);

        // 休息一会儿再继续
        usleep(rand() % 1000000);
    }
    return NULL;
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];

    // 初始化筷子
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    // 创建哲学家线程
    int philosopher_ids[NUM_PHILOSOPHERS];
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }

    // 等待一段时间后结束程序
    sleep(10);

    // 停止哲学家线程
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_cancel(philosophers[i]);
    }

    // 销毁筷子
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_mutex_destroy(&chopsticks[i]);
    }

    printf("哲学家们停止进餐\n");

    return 0;
}
