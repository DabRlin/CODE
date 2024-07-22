#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

void InitSeqList(SeqList *list) {
    list->length = 0;
}

void Insert(SeqList *list, int value) {
    if (list->length >= MAX_SIZE) {
        printf("顺序表已满，无法插入！\n");
        return;
    }
    list->data[list->length++] = value;
}

void ReverseSeqList(SeqList *list) {
    int i, j;
    int temp;
    
    for (i = 0, j = list->length - 1; i < j; i++, j--) {
        temp = list->data[i];
        list->data[i] = list->data[j];
        list->data[j] = temp;
    }
}

void PrintSeqList(SeqList *list) {
    printf("顺序表元素：");
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList list;
    int n, value;

    InitSeqList(&list);

    printf("请输入顺序表的长度：");
    scanf("%d", &n);

    printf("请输入顺序表的元素：\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        Insert(&list, value);
    }

    printf("逆置前：\n");
    PrintSeqList(&list);

    ReverseSeqList(&list);

    printf("逆置后：\n");
    PrintSeqList(&list);

    return 0;
}
