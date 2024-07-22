#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILDREN 10
#define MAX_SIZE 100

// 定义节点
typedef struct Node
{
    int data;
    struct Node *child[MAX_CHILDREN];
    int child_count;
} Node;

// 定义树结构
typedef struct tree
{
    Node *nodes[MAX_SIZE];
    int size;
} Tree;

// 函数声明
void initTree(Tree *t);
Node *createNode(int value);
void insertNode(Tree *t, int index, int value);
int findNode(Tree *t, int value);
void traverseTree(Tree *tree);
void traverseTreeNode(Node *node);
void deleteNode(Tree *t, int value);
void deleteNodeRecursively(Node *node);
void removeChildReference(Node *parent, Node *child);

// 主函数
int main()
{
    Tree tree;
    initTree(&tree);

    // 创建根节点
    Node *root = createNode(1);
    tree.nodes[tree.size++] = root;

    // 插入子节点
    insertNode(&tree, 0, 2); // 插入2为1的子节点
    insertNode(&tree, 0, 3); // 插入3为1的子节点
    insertNode(&tree, 1, 4); // 插入4为2的子节点
    insertNode(&tree, 1, 5); // 插入5为2的子节点
    insertNode(&tree, 2, 6); // 插入6为3的子节点

    // 遍历树
    printf("Tree traversal:\n");
    traverseTree(&tree);
    printf("\n");

    // 删除节点
    printf("Deleting node 2 and its children:\n");
    deleteNode(&tree, 2);
    traverseTree(&tree);
    printf("\n");

    return 0;
}

// 函数实现

// 初始化树
void initTree(Tree *t)
{
    t->size = 0;
}

// 创建节点
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->child_count = 0;
    newNode->data = value;
    return newNode;
}

// 插入节点
void insertNode(Tree *t, int index, int value)
{
    if (index <= MAX_SIZE)
    {
        if (t->nodes[index]->child_count < MAX_CHILDREN)
        {
            Node *newNode = createNode(value);
            t->nodes[index]->child[t->nodes[index]->child_count++] = newNode;
            t->nodes[t->size++] = newNode;
        }
        else
        {
            printf("该节点已满");
            return;
        }
    }
    else
    {
        printf("树已满\n");
    }
}

// 查找结点
int findNode(Tree *t, int value)
{
    for (int i = 0; i < t->size; i++)
    {
        if (t->nodes[i]->data == value)
        {
            return i;
        }
    }
    printf("该树中并无该值\n");
    return -1;
}

// 遍历树节点
void traverseTreeNode(Node *node)
{
    if (node)
    {
        printf("根:%d\n", node->data);
        printf("子节点：\n");
        for (int i = 0; i < node->child_count; i++)
        {
            printf("%d -", node->child[i]->data);
        }
        printf("\n");
    }
    else
    {
        return;
    }
}

// 遍历树
void traverseTree(Tree *tree)
{
    if (tree->size != 0)
    {
        for (int i = 0; i < tree->size; i++)
        {
            traverseTreeNode(tree->nodes[i]);
        }
    }
    return;
}

// 递归删除节点及其子节点
void deleteNodeRecursively(Node *node)
{
    if (node)
    {
        for (int i = 0; i < node->child_count; i++)
        {
            deleteNodeRecursively(node->child[i]);
        }
        free(node);
    }
}

// 删除父节点中对子节点的引用
void removeChildReference(Node *parent, Node *child)
{
    int i;
    for (i = 0; i < parent->child_count; i++)
    {
        if (parent->child[i] == child)
        {
            break;
        }
    }
    for (; i < parent->child_count; i++)
    {
        parent->child[i] = parent->child[i + 1];
    }
    parent->child_count--;
};

// 删除节点并调整节点位置
void deleteNode(Tree *t, int value)
{
    int index = findNode(t, value);
    if (index != -1)
    {
        Node *delNode = t->nodes[index];
        for (int i = 0; i < t->size; i++)
        {
            for (int j = 0; j < t->nodes[i]->child_count; j++)
            {
                if (t->nodes[i]->child[j] == delNode)
                {
                    removeChildReference(t->nodes[i], delNode);
                    break;
                }
            }
        }

        deleteNodeRecursively(delNode);
        for (int i = index; i < t->size - 1; i++)
        {
            t->nodes[i] = t->nodes[i + 1];
        }
        t->nodes[t->size - 1] = NULL;
        t->size--;
    }
    else
    {
        printf("该节点不存在\n");
        return;
    }
}