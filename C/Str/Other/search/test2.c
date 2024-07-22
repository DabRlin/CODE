#include <stdio.h>
#include <stdlib.h>

// 结构体定义
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 函数声明
Node *createNode(int data);
void insertNode(Node **head, int data);
Node *search(Node *head, int value);
void deleteNode(Node **head, int data);
void printNode(Node *head);

// 主函数
int main()
{
    return 0;
}

// 函数实现

// 创建节点
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 插入节点
void insertNode(Node **head, int data)
{
    Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 删除节点
void deleteNode(Node **head, int data)
{
    if (*head == NULL)
    {
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (prev = NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
}

// 打印节点
void printNode(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 查找节点
Node *search(Node *head, int value)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}