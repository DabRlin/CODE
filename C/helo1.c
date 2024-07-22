#include <stdio.h>
#include <stdlib.h>

// 树节点定义
typedef struct Node
{
    int data;
    struct Node *nextBrother;
    struct Node *firstChild;
} Node;

// 函数声明
Node *createNode(int value);
void insertNode(Node *parent, int value);
Node *findNode(Node *root, int value);
void traverseTree(Node *node);
void deleteNode(Node *node, int value);
void deleteNodeRecusively1(Node *node);
Node *deleteNodeRecusively2(Node *node);
Node *findParent(Node *root, int value);

// 主函数
int main()
{
    return 0;
}

// 函数实现

// 创建节点
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->firstChild = NULL;
    newNode->nextBrother = NULL;
    return newNode;
}

// 插入节点
void insertNode(Node *parent, int value)
{
    if (parent != NULL)
    {
        Node *newNode = createNode(value);
        if (parent->firstChild == NULL)
        {
            parent->firstChild = newNode;
        }
        else
        {
            Node *temp = parent->firstChild;
            while (temp->nextBrother != NULL)
            {
                temp = temp->nextBrother;
            }
            temp->nextBrother = newNode;
        }
    }
    else
    {
        printf("该节点为空");
        return;
    }
}

// 查找结点
Node *findNode(Node *root, int value)
{
    if (root != NULL)
    {
        if (root->data == value)
        {
            return root;
        }
        else
        {
            Node *result = findNode(root->firstChild, value);
            if (result != NULL)
            {
                return result;
            }
            return findNode(root->nextBrother, value);
        }
    }
    else
    {
        printf("该树为空");
        return NULL;
    }
}

// 遍历节点
void traverseTree(Node *node)
{
    if (node != NULL)
    {
        printf("%d- ", node->data);
        traverseTree(node->firstChild);
        traverseTree(node->nextBrother);
    }
    else
    {
        return;
    }
}

// 递归删除子节点
void deleteNodeRecursively1(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    deleteNodeRecursively1(node->firstChild);
    deleteNodeRecursively1(node->nextBrother);
    free(node);
}

Node *deleteNodeRecursively2(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    deleteNodeRecursively1(node->firstChild);
    Node *next = node->nextBrother;
    free(node);
    return next;
}

// 找到父节点
Node *findParent(Node *root, int value)
{
    if (root != NULL && root->data != value)
    {
        if (root->firstChild->data == value && root->nextBrother->data == value)
        {
            return root;
        }
        else
        {
            Node *result = findParent(root->firstChild, value);
            if (result != NULL)
            {
                return result;
            }
            return findParent(root->nextBrother, value);
        }
    }
    else
    {
        return NULL;
    }
}

// 删除节点
void deleteNode(Node *root, int value)
{
    if (root == NULL)
    {
        printf("该树为空");
        return;
    }
    if (root->data == value)
    {
        deleteNodeRecursively1(root);
    }
    else
    {
        Node *deleteNode = findNode(root, value);
        if (deleteNode == NULL)
        {
            printf("节点不存在");
            return;
        }
        Node *parent = findParent(root, value);
        if (parent->firstChild == deleteNode)
        {
            parent->firstChild = NULL;
            deleteNodeRecursively1(deleteNode);
        }
        else
        {
            if (parent->nextBrother->nextBrother == NULL)
            {
                parent->nextBrother == NULL;
            }
            else
            {
                parent->nextBrother = deleteNodeRecursively2(deleteNode);
            }
        }
    }
}