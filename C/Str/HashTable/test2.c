#include <stdio.h>
#include <stdlib.h>

#define INITAL_SIZE 16
#define LOAD_FACTOR 0.75
#define DELETED -1

// 定义结构体

// 定义哈希表
typedef struct HashTable
{
    int *keys;
    int *values;
    int size;
    int count;
} HashTable;

// 函数声明
HashTable *createHashTable();
void freeHashTable(HashTable *ht);
int hashFunction(int key, int size);
void insert(HashTable *ht, int key, int value);
void delete(HashTable *ht, int key);
int search(HashTable *ht, int key);
void resizeHashTable(HashTable *ht);

// 主函数
int main()
{
    HashTable *ht = createHashTable();

    insert(ht, 1, 100);
    insert(ht, 2, 200);
    insert(ht, 17, 300); // This will trigger a resize

    printf("Value for key 1: %d\n", search(ht, 1));
    printf("Value for key 2: %d\n", search(ht, 2));
    printf("Value for key 17: %d\n", search(ht, 17));

    delete (ht, 1);
    printf("Value for key 1 after deletion: %d\n", search(ht, 1));

    freeHashTable(ht);
    return 0;
}

// 函数实现

// 创建哈希表
HashTable *createHashTable()
{
    HashTable *newTable = (HashTable *)malloc(sizeof(HashTable));
    if (!newTable)
    {
        return NULL;
    }

    newTable->size = INITAL_SIZE;
    newTable->count = 0;
    newTable->keys = (int *)malloc(newTable->size * sizeof(int));
    newTable->values = (int *)malloc(newTable->size * sizeof(int));
    if (!newTable->keys || !newTable->values)
    {
        freeHashTable(newTable);
        return NULL;
    }

    for (int i = 0; i < newTable->size; i++)
    {
        newTable->keys[i] = DELETED;
    }

    return newTable;
}

// 释放哈希表
void freeHashTable(HashTable *ht)
{
    if (ht == NULL)
    {
        return;
    }

    free(ht->keys);
    free(ht->values);
    free(ht);
}

// 哈希函数
int hashFunction(int key, int size)
{
    return key % size;
}

// 插入键值对
void insert(HashTable *ht, int key, int value)
{
    if ((float)ht->count / ht->size > LOAD_FACTOR)
    {
        resizeHashTable(ht);
    }
    int index = hashFunction(key, ht->size);
    while (ht->keys[index] != DELETED && ht->keys[index] != key)
    {
        index = (index + 1) % ht->size;
    }
    if (ht->keys[index] == key)
    {
        ht->values[index] = value;
        return;
    }
    ht->keys[index] = key;
    ht->values[index] = value;
    ht->count++;
}

// 删除键值对
void delete(HashTable *ht, int key)
{
    if (ht == NULL)
    {
        return;
    }

    int index = hashFunction(key, ht->size);
    while (ht->keys[index] != DELETED)
    {
        if (ht->keys[index] = key)
        {
            ht->keys[index] = DELETED;
            ht->count--;
            return;
        }
        index = (index + 1) % ht->size;
    }
}

// 根据键查询值
int search(HashTable *ht, int key)
{
    if (ht == NULL)
    {
        return -1;
    }
    int index = hashFunction(key, ht->size);
    while (ht->keys[index] != DELETED)
    {
        if (ht->keys[index] == key)
        {
            return ht->values[index];
        }
        index = (index + 1) % ht->size;
    }
    return -1;
}

// 重新分配哈希表大小
void resizeHashTable(HashTable *ht)
{
    int newSize = ht->size * 2;
    int *newKey = (int *)malloc(newSize * sizeof(int));
    int *newValue = (int *)malloc(newSize * sizeof(int));
    if (!newKey || !newValue)
    {
        return;
    }
    for (int i = 0; i < newSize; i++)
    {
        newKey[i] = DELETED;
    }
    for (int i = 0; i < ht->size; i++)
    {
        if (ht->keys[i] != DELETED)
        {
            int index = hashFunction(ht->keys[i], newSize);
            while (newKey[index] != DELETED)
            {
                index = (index + 1) % ht->size;
            }
            newKey[index] = ht->keys[i];
            newValue[index] = ht->values[i];
        }
    }
    free(ht->keys);
    free(ht->values);
    ht->keys = newKey;
    ht->values = newValue;
    ht->size = newSize;
}