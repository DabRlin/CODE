#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20

struct TreeNode
{
    int data;
    int parent; // 父节点的索引（如果是根节点则为-1）
};

struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    int childCount; // 记录树中孩子的数量
};

struct TreeNode readTreeNode()
{
    struct TreeNode node;
    printf("请输入节点的数据和父节点的索引（如果是根节点则为-1）：\n");
    scanf("%d %d", &node.data, &node.parent);
    return node;
}

struct BinaryTreeNode *createBinaryNode(int data)
{
    struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->childCount = 0;
    return newNode;
}

struct BinaryTreeNode *convertToBinary(struct TreeNode tree[], int n)
{
    struct BinaryTreeNode *binaryRoot = NULL;
    struct BinaryTreeNode *binaryNodes[MAX_NODES];

    // 创建二叉树节点
    for (int i = 0; i < n; ++i)
    {
        binaryNodes[i] = createBinaryNode(tree[i].data);
    }

    // 找到根节点
    int rootIndex = -1;
    for (int i = 0; i < n; ++i)
    {
        if (tree[i].parent == -1)
        {
            rootIndex = i;
            break;
        }
    }

    if (rootIndex == -1)
    {
        printf("未找到根节点\n");
        return NULL;
    }

    binaryRoot = binaryNodes[rootIndex];

    // 将树转换为二叉树
    for (int i = 0; i < n; ++i)
    {
        int parentIndex = tree[i].parent;
        if (parentIndex != -1)
        {
            struct BinaryTreeNode *parentNode = binaryNodes[parentIndex];
            if (parentNode->left == NULL)
            {
                parentNode->left = binaryNodes[i];
            }
            else
            {
                struct BinaryTreeNode *temp = parentNode->left;
                while (temp->right != NULL)
                {
                    temp = temp->right;
                }
                temp->right = binaryNodes[i];
            }
            parentNode->childCount++;
        }
    }

    return binaryRoot;
}

void countChildren(struct BinaryTreeNode *binaryRoot)
{
    if (binaryRoot == NULL)
    {
        return;
    }

    printf("节点 %d: %d 个孩子\n", binaryRoot->data, binaryRoot->childCount);

    countChildren(binaryRoot->left);
    countChildren(binaryRoot->right);
}

int main()
{
    int nodeCount;
    printf("请输入节点的数量：\n");
    scanf("%d", &nodeCount);

    struct TreeNode treeNodes[MAX_NODES];

    for (int i = 0; i < nodeCount; ++i)
    {
        treeNodes[i] = readTreeNode();
    }

    // 将树转换为二叉树
    struct BinaryTreeNode *binaryRoot = convertToBinary(treeNodes, nodeCount);

    // 统计二叉树中的孩子数
    countChildren(binaryRoot);

    return 0;
}
