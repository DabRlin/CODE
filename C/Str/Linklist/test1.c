#include<stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node* next;

}Node;

void printLinklist(Node* i);
void insertNode(Node* i, int value );
void deleteNode(int value);
void inssertNode(Node *i, int value){
    Node* newNode = (Node *)malloc(sizeof(Node));
    

}


int main(){
    Node* head = NULL;


} 

void insertNode(Node* i, int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    i->next=newNode;
}
void printLinklist(Node* head){
    Node* current = head;
    while (current !=NULL)
    {
        printf("%d -> ",current->data);
        current = current->next;
    }
    

}
