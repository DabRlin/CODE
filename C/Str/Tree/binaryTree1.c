#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 512

// 结构体定义

// 树的定义
typedef struct Tree
{
    int data[MAX_SIZE];
    int size;
} Tree;

// 函数声明
void initTree(Tree *tree);
void insertNode(Tree *tree, int value);
int searchNode(Tree *tree, int value);
void deleteNode(Tree *tree, int value);
void preorderTraversal(Tree *tree, int pos);
void inorderTraversal(Tree *tree, int pos);
void postorderTraversal(Tree *tree, int pos);

// 主函数
int main()
{
    Tree tree;
    initTree(&tree);

    insertNode(&tree, 50);
    insertNode(&tree, 30);
    insertNode(&tree, 70);
    insertNode(&tree, 20);
    insertNode(&tree, 40);
    insertNode(&tree, 60);
    insertNode(&tree, 80);

    printf("前序遍历: ");
    preorderTraversal(&tree, 1);
    printf("\n");

    printf("中序遍历: ");
    inorderTraversal(&tree, 1);
    printf("\n");

    printf("后序遍历: ");
    postorderTraversal(&tree, 1);
    printf("\n");

    deleteNode(&tree, 70);
    printf("删除节点 70 后的中序遍历: ");
    inorderTraversal(&tree, 1);
    printf("\n");

    return 0;
}

// 函数实现

// 初始化树
void initTree(Tree *tree)
{
    if (tree != NULL)
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            tree->data[i] = -1;
        }
        tree->size = 0;
    }
    else
    {
        printf("树不存在\n");
        return;
    }
}

// 插入节点
void insertNode(Tree *tree, int value)
{
    if (tree == NULL)
    {
        printf("树不存在\n");
        return;
    }
    if (tree->size == MAX_SIZE)
    {
        printf("树已满\n");
        return;
    }
    int pos = 1;
    while (pos < MAX_SIZE && tree->data[pos] != -1)
    {
        if (tree->data[pos] > value)
        {
            pos = pos * 2;
        }
        else
        {
            pos = pos * 2 + 1;
        }
    }
    if (pos < MAX_SIZE)
    {
        tree->data[pos] = value;
        tree->size++;
    }
}

// 查找结点
int searchNode(Tree *tree, int value)
{
    if (tree != NULL)
    {
        int pos = 1;
        while (pos < MAX_SIZE && tree->data[pos] != -1)
        {
            if (tree->data[pos] == value)
            {
                return pos;
            }
            else if (tree->data[pos] > value)
            {
                pos = 2 * pos;
            }
            else
            {
                pos = pos * 2 + 1;
            }
        }
        return -1;
    }
    else
    {
        printf("树不存在\n");
        return -1;
    }
}

// 删除节点
void deleteNode(Tree *tree, int value)
{
    if (tree == NULL)
    {
        printf("树为空\n");
        return;
    }

    int pos = searchNode(tree, value);
    if (pos == -1)
    {
        printf("树中无此节点\n");
        return;
    }
    tree->data[pos] = -1;
    tree->size--;
}

// 前序遍历
void preorderTraversal(Tree *tree, int pos)
{
    if (pos < MAX_SIZE && tree->data[pos] != -1)
    {
        printf("%d-", tree->data[pos]);
        preorderTraversal(tree, pos * 2);
        preorderTraversal(tree, pos * 2 + 1);
    }
}

// 中序遍历
void inorderTraversal(Tree *tree, int pos)
{
    if (pos < MAX_SIZE && tree->data[pos] != -1)
    {
        inorderTraversal(tree, pos * 2);
        printf("%d-", tree->data[pos]);
        inorderTraversal(tree, pos * 2 + 1);
    }
}

// 后序遍历
void postorderTraversal(Tree *tree, int pos)
{
    if (pos < MAX_SIZE && tree->data[pos] != -1)
    {
        postorderTraversal(tree, pos * 2);
        postorderTraversal(tree, pos * 2 + 1);
        printf("%d-", tree->data[pos]);
    }
}