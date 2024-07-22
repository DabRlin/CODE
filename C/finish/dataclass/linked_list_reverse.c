#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* InitLinkedList() {
    Node* head = (Node*)malloc(sizeof(Node));
    if (head != NULL) {
        head->data = 0;  
        head->next = NULL;
    }
    return head;
}


Node* Insert(Node *head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL; 

    if (head == NULL) {
        return newNode;
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

Node* ReverseLinkedList(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void PrintLinkedList(Node *head) {
    printf("单链表元素：");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = InitLinkedList();
    int n, value;

    printf("请输入单链表的长度：");
    scanf("%d", &n);

    printf("请输入单链表的元素：\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = Insert(head, value);
    }

    printf("逆置前：\n");
    PrintLinkedList(head);

    head = ReverseLinkedList(head);

    printf("逆置后：\n");
    PrintLinkedList(head);

    return 0;
}
