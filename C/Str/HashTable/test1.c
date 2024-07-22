#include <stdio.h>
#include <stdlib.h>

#define INITAL_SIZE 16
#define LOAD_FACTOR 0.75

// 结构体定义

// 表节点定义
typedef struct Node
{
    int data;
    int key;
    struct Node *next;
} Node;

// 哈希表定义
typedef struct HashTable
{
    Node **table;
    int size;
    int count;
} HashTable;

// 函数声明
HashTable *createHashTable();
Node *createNode(int data, int key);
int hashFunction(int key, int size);
void insertNode(HashTable *table, int key, int value);
void deleteNode(HashTable *table, int key);
int searchNode(HashTable *table, int key);
void resizeHashTable(HashTable *table);
void freeHashTable(HashTable *table);

// 主函数
int main()
{
    HashTable *table = createHashTable();

    // 插入一些值
    insertNode(table, 1, 100);
    insertNode(table, 2, 200);
    insertNode(table, 3, 300);

    // 查找值
    printf("键 2 的值: %d\n", searchNode(table, 2));

    // 删除值
    deleteNode(table, 2);

    // 查找已删除的值
    printf("键 2 的值: %d\n", searchNode(table, 2));

    // 释放哈希表
    freeHashTable(table);

    return 0;
}

// 函数实现

// 创建哈希表
HashTable *createHashTable()
{
    HashTable *newTable = (HashTable *)malloc(sizeof(HashTable));
    if (!newTable)
    {
        printf("内存分配失败");
        return NULL;
    }
    newTable->size = INITAL_SIZE;
    newTable->count = 0;
    newTable->table = (Node **)malloc(INITAL_SIZE * sizeof(Node *));
    for (int i = 0; i < newTable->size; i++)
    {
        newTable->table[i] = NULL;
    }
    if (!newTable->table)
    {
        printf("内存分配失败");
        return NULL;
    }
    return newTable;
}

// 创建节点
Node *createNode(int data, int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("内存分配失败");
        return NULL;
    }

    newNode->data = data;
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// 哈希函数
int hashFunction(int key, int size)
{
    return key % size;
}

// 插入节点
void insertNode(HashTable *table, int key, int value)
{
    if ((float)table->count / table->size > LOAD_FACTOR)
    {
        resizeHashTable(table);
    }
    int index = hashFunction(key, table->size);
    Node *newNode = createNode(value, key);
    newNode->next = table->table[index];
    table->table[index] = newNode;
    table->count++;
}

// 删除节点
void deleteNode(HashTable *table, int key)
{
    if (table == NULL)
    {
        return;
    }

    int index = hashFunction(key, table->size);
    Node *current = table->table[index];
    Node *prev = NULL;
    while (current->key != key && current != NULL)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        return;
    }
    if (prev != NULL)
    {
        prev->next = current->next;
    }
    else
    {
        table->table[index] = current->next;
    }
    free(current);
    table->count--;
}

// 查找结点
int searchNode(HashTable *table, int key)
{
    if (table == NULL)
    {
        return -1;
    }

    int index = hashFunction(key, table->size);
    Node *current = table->table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->data;
        }
        current = current->next;
    }
    return -1;
}

// 调整哈希表大小
void resizeHashTable(HashTable *table)
{
    Node **oldTable = table->table;
    int newSize = table->size * 2;
    Node **newTable = (Node **)malloc(newSize * sizeof(Node *));
    if (!newTable)
    {
        printf("内存分配失败");
        return;
    }
    for (int i = 0; i < newSize; i++)
    {
        newTable[i] = NULL;
    }
    for (int i = 0; i < table->size; i++)
    {
        Node *current = table->table[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            int newIndex = hashFunction(temp->key, newSize);
            current->next = newTable[newIndex];
            newTable[newIndex] = temp;
        }
    }
    free(oldTable);
    table->table = newTable;
    table->size = newSize;
}

// 释放哈希表
void freeHashTable(HashTable *table)
{
    if (table == NULL)
    {
        return;
    }

    for (int i = 0; i < table->size; i++)
    {
        Node *current = table->table[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table->table);
    free(table);
}