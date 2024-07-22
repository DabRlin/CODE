#include <stdio.h>
#include <stdlib.h>

// 结构体定义
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// 函数声明
Node *createNode(int value);
void insertNode(Node *node, int value);
Node *searchNode(Node *root, int value);
void deleteNode(Node *root, int value);
void preorderTraversal(Node *root);
void inorderTraversal(Node *root);
void postorderTraversal(Node *root);

// 主函数
int main()
{
    Node *root = createNode(1);
    insertNode(root, 2);
    insertNode(root, 3);
    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
    deleteNode(root, 2);
    inorderTraversal(root);
    printf("\n");
    Node *srcNode = searchNode(root, 3);
    printf("%d", srcNode->data);
    return 0;
}

// 函数实现

// 创建节点
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入节点
void insertNode(Node *node, int value)
{
    if (node == NULL)
    {
        printf("该节点为空\n");
        return;
    }
    Node *newNode = createNode(value);

    if (node->left == NULL)
    {
        node->left = newNode;
    }
    else if (node->right == NULL)
    {
        node->right = newNode;
    }
    else
    {
        printf("该节点已满\n");
        return;
    }
}

// 查找结点
Node *searchNode(Node *root, int value)
{
    if (root != NULL)
    {
        Node *search = NULL;
        if (root->data == value)
        {
            return root;
        }
        else
        {
            search = searchNode(root->left, value);
        }
        if (search == NULL)
        {
            search = searchNode(root->right, value);
        }
        return search;
    }
    return NULL;
}

Node *searchParent(Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return NULL;
    }
    Node *search = NULL;
    if (root->left->data == value || root->right->data == value)
    {
        return root;
    }
    else
    {
        search = searchParent(root->left, value);
    }
    if (search == NULL)
    {
        search = searchParent(root->right, value);
    }
    return search;
}

// 级联删除节点
void deleteNodeWithChild(Node *Node)
{
    if (Node == NULL)
    {
        return;
    }
    deleteNodeWithChild(Node->left);
    deleteNodeWithChild(Node->right);
    free(Node);
}

// 删除节点
void deleteNode(Node *root, int value)
{
    if (root == NULL)
    {
        printf("树为空\n");
        return;
    }
    Node *delNode = searchNode(root, value);
    if (delNode == NULL)
    {
        printf("树中不存在该节点\n");
        return;
    }
    Node *delNodeParent = searchParent(root, value);
    if (delNodeParent != NULL)
    {
        if (delNodeParent->left == delNode)
        {
            delNodeParent->left = NULL;
        }
        else
        {
            delNodeParent->right = NULL;
        }
    }

    deleteNodeWithChild(delNode);
}

// 先序遍历
void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d-", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 中序遍历
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d-", root->data);
    inorderTraversal(root->right);
}

// 后序遍历
void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d-", root->data);
}
