#include <stdio.h>
#include <stdlib.h>

// 节点定义
typedef struct Node
{
    int data;
    struct Node *next;
    int index;

} Node;

// 函数声明
void printLinklist(Node *head);
void insertLinklist(Node **head, int data, int index);
Node *createNode(int data, int index);
void freeLinklist(Node *head);
void updateLinklist(Node **head, int data, int index);
void searchLinklist(Node *head, int data);
int getLinklist(Node *head, int index);
void deleteLinklist(Node **head, int index);

// 主函数
int main()
{
    Node *head = NULL;
    insertLinklist(&head, 10, 0);
    insertLinklist(&head, 20, 1);
    insertLinklist(&head, 30, 2);

    printLinklist(head);
    insertLinklist(&head, 40, 0);
    insertLinklist(&head, 50, 2);

    printLinklist(head);
    freeLinklist(head);
    return 0;
}

// 打印链表
void printLinklist(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 插入节点
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
// 更新节点
void updateLinklist(Node **head, int data, int index)
{
    if (*head == NULL || index < 0)
    {
        return;
    }

    Node *temp = *head;
    int currentIndex = 0;
    while (currentIndex < index)
    {
        temp = temp->next;
        currentIndex++;
    }
    if (temp == NULL)
    {
        return;
    }
    else
    {
        temp->data = data;
    }
}

// 删除节点
void deleteLinklist(Node **head, int index)
{
    if (*head == NULL || index < 0)
    {
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    if (index == 0)
    {
        *head = temp->next;
        free(temp);
        temp = *head;
        while (temp != NULL)
        {
            temp->index--;
            temp = temp->next;
        }
        return;
    }
    int currentIndex = 0;
    while (currentIndex < index && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        currentIndex++;
    }
    if (temp == NULL)
    {
        return;
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        while (prev->next != 0)
        {
            prev = prev->next;
            prev->index--;
        }
    }
}

// 创造节点
Node *createNode(int data, int index)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->index = index;
    return newNode;
}

// 释放链表
void freeLinklist(Node *head)
{
    Node *current = head, *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

// 查找节点
void searchLinklist(Node *head, int data)
{
    Node *temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("数值%d在链表第%d个节点被发现\n", data, index);
            break;
        }
        temp = temp->next;
        index++;
    }
    if (temp == NULL)
    {
        printf("输入值%d不在链表中\n", data);
    }
}

// 返回节点值
int getLinklist(Node *head, int index)
{
    if (head == NULL || index < 0)
    {
        printf("输入越界\n");
        return -1;
    }

    int currentIndex = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (currentIndex == index)
        {
            return temp->data;
        }

        temp = temp->next;
        currentIndex++;
    }
    printf("输入值越界\n");
    return -1;
}