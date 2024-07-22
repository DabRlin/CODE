#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 15 // 假设最长单词长度为15

int main() {
    int c, state, word_length;
    int word_lengths[MAX_WORD_LENGTH + 1]; // 存储不同长度单词的个数

    state = OUT;
    word_length = 0;

    // 初始化数组
    for (int i = 0; i <= MAX_WORD_LENGTH; ++i)
        word_lengths[i] = 0;

    // 统计单词长度
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (word_length <= MAX_WORD_LENGTH)
                    ++word_lengths[word_length];
                else
                    ++word_lengths[MAX_WORD_LENGTH];
            }
            state = OUT;
            word_length = 0;
        } else {
            state = IN;
            ++word_length;
        }
    }

    // 寻找最大长度
    int max_length = 0;
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
        if (word_lengths[i] > max_length)
            max_length = word_lengths[i];
    }
    if (word_lengths[MAX_WORD_LENGTH] > max_length)
        max_length = word_lengths[MAX_WORD_LENGTH];

    // 打印垂直方向的直方图
    printf("Vertical Word Length Histogram:\n");
    for (int i = max_length; i > 0; --i) {
        for (int j = 1; j <= MAX_WORD_LENGTH; ++j) {
            if (word_lengths[j] >= i)
                printf(" * ");
            else
                printf("   ");
        }
        if (word_lengths[MAX_WORD_LENGTH] >= i)
            printf(" > ");
        else
            printf("   ");
        printf("\n");
    }
    // 打印底部标签
    for (int i = 1; i <= MAX_WORD_LENGTH; ++i)
        printf("%2d ", i);
    printf(">15\n");

    return 0;
}
