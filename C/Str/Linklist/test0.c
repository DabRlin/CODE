#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;

} Node;

void printLinklist(Node *i);
void insertNode(Node **i, int value);

int main()
{
    Node *head = NULL;
}

void printLinklist(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
}

void insertNode(Node **head, int value)
{
    Node *current = *head;
    Node *newNode = NULL;
    while (current->next != NULL)
    {
        current = current->next;
    }
    newNode = current->next;
    newNode->next = NULL;
    newNode->data = value;
}