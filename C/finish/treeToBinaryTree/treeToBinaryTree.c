#include <stdio.h>
#include <stdlib.h>

// 树节点的结构体，包含数据值和父节点下标信息
typedef struct TreeNode {
    char data;
    int parent;
} TreeNode;

// 二叉树节点的结构体，包含数据值和左右孩子指针
typedef struct BinaryTreeNode {
    char data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

// 创建树的函数，根据输入构建树的结构
void createTree(TreeNode **tree, int n) {
    *tree = (TreeNode *)malloc(sizeof(TreeNode) * (n + 1));
    printf("输入树的结点值：\n");
    for (int i = 1; i <= n; ++i) {
        printf("第 %d 个结点的值：", i);
        scanf(" %c", &((*tree)[i].data));
        (*tree)[i].parent = -1;
    }
    printf("输入每个结点的父节点下标(1表示根节点):\n");
    for (int i = 2; i <= n; ++i) {
        int parentIdx;
        printf("第 %d 个结点的父节点下标：", i);
        scanf("%d", &parentIdx);
        (*tree)[i].parent = parentIdx;
    }
}

// 将树转换为二叉树的函数
BinaryTreeNode* convertToBinaryTree(TreeNode *tree, int n) {
    BinaryTreeNode *binaryTree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode) * (n + 1));
    for (int i = 1; i <= n; ++i) {
        binaryTree[i].data = tree[i].data;
        binaryTree[i].left = NULL;
        binaryTree[i].right = NULL;
    }

    for (int i = 2; i <= n; ++i) {
        int parentIdx = tree[i].parent;
        if (parentIdx != -1) {
            if (binaryTree[parentIdx].left == NULL) {
                binaryTree[parentIdx].left = &binaryTree[i];
            } else {
                BinaryTreeNode *temp = binaryTree[parentIdx].left;
                while (temp->right != NULL) {
                    temp = temp->right;
                }
                temp->right = &binaryTree[i];
            }
        }
    }
    return &binaryTree[1];
}

// 先序遍历二叉树
void preOrder(BinaryTreeNode *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 中序遍历二叉树
void inOrder(BinaryTreeNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%c ", root->data);
        inOrder(root->right);
    }
}

// 统计二叉树每个节点的孩子数目
void countChildren(BinaryTreeNode *root, int *childCount) {
    if (root == NULL) {
        return;
    }

    int count = 0;
    if (root->left != NULL) {
        count++;
    }
    if (root->right != NULL) {
        count++;
    }

    childCount[root->data - '0'] = count;

    countChildren(root->left, childCount);
    countChildren(root->right, childCount);
}

int main() {
    TreeNode *tree = NULL;
    int numNodes;

    printf("输入树中结点的个数：");
    scanf("%d", &numNodes);

    if (numNodes <= 0) {
        printf("无效的结点个数。程序退出...\n");
        return 1;
    }

    // 创建树
    createTree(&tree, numNodes);

    // 将树转换为二叉树
    BinaryTreeNode *binaryTreeRoot = convertToBinaryTree(tree, numNodes);

    // 输出二叉树的先序遍历结果
    printf("\n二叉树的先序遍历结果：");
    preOrder(binaryTreeRoot);

    // 输出二叉树的中序遍历结果
    printf("\n二叉树的中序遍历结果：");
    inOrder(binaryTreeRoot);

    // 为每个节点统计孩子数目
    int *childCount = (int *)malloc(sizeof(int) * (numNodes + 1));
    for (int i = 1; i <= numNodes; ++i) {
        childCount[i] = 0;
    }

    countChildren(binaryTreeRoot, childCount);

    // 输出转换后二叉树每个节点的孩子数目
    printf("\n转换后二叉树每个节点的孩子数目：\n");
    for (int i = 1; i <= numNodes; ++i) {
        printf("节点 [%c] 的孩子数目：%d\n", binaryTreeRoot[i-1].data, childCount[i]);
    }

    // 释放内存
    free(tree);
    free(childCount);

    return 0;
}
