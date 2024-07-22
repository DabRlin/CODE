#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node
{
    int data;
    struct Node *next;  // 注意这里需要使用 struct Node
    int index;
} Node;

// 函数声明
void printLinklist(Node *head);
void insertLinklist(Node **head, int data, int index);
Node *createNode(int data, int index);
void freeLinklist(Node *head);

// 打印链表
void printLinklist(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d(index: %d) -> ", current->data, current->index);
        current = current->next;
    }
    printf("NULL\n");
}

// 插入节点到链表
void insertLinklist(Node **head, int data, int index)
{
    Node *newNode = createNode(data, index);

    if (index == 0)
    {
        if (*head == NULL)
        {
            newNode->next = NULL;
            *head = newNode;
        }
        else
        {
            newNode->next = *head;
            *head = newNode;
            Node *temp = *head;
            while (temp != NULL)
            {
                temp->index++;
                temp = temp->next;
            }
        }
    }
    else
    {
        Node *temp = *head;
        Node *prev = NULL;
        int currentIndex = 0;
        while (currentIndex < index && temp != NULL)
        {
            prev = temp;
            temp = temp->next;
            currentIndex++;
        }
        if (temp == NULL)
        {
            // 如果 temp 为 NULL，说明 index 超出了链表长度，直接插入在末尾
            if (prev != NULL)
            {
                prev->next = newNode;
            }
            else
            {
                *head = newNode;
            }
        }
        else
        {
            // 插入到中间位置
            newNode->next = prev->next;
            prev->next = newNode;
            while (temp != NULL)
            {
                temp->index++;
                temp = temp->next;
            }
        }
    }
}

// 创建新节点
Node *createNode(int data, int index)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->index = index;
    return newNode;
}

// 释放链表节点
void freeLinklist(Node *head)
{
    Node *current = head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    Node *head = NULL;  // 初始化链表头指针为 NULL

    // 插入一些节点
    insertLinklist(&head, 10, 0);
    insertLinklist(&head, 20, 1);
    insertLinklist(&head, 30, 1);  // 插入到第二个位置

    // 打印链表
    printLinklist(head);

    // 继续插入一些节点
    insertLinklist(&head, 40, 0);
    insertLinklist(&head, 50, 2);

    // 再次打印链表
    printLinklist(head);

    // 释放链表节点
    freeLinklist(head);

    return 0;
}
