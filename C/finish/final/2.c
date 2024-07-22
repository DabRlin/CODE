#include <stdio.h>
#include <stdlib.h>

// 树的双亲表示法结构
typedef struct TreeNode {
    char data; // 将数据类型改为字符型
    int parent; // 双亲结点下标
} TreeNode;

// 二叉树结点
typedef struct BinaryTreeNode {
    char data; // 将数据类型改为字符型
    int child_count; // 孩子数
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

// 创建树
void createTree(TreeNode **tree, int n) {
    *tree = (TreeNode *)malloc(sizeof(TreeNode) * (n + 1)); // 调整数组大小为 n+1
    printf("输入树的结点值：\n");
    for (int i = 1; i <= n; ++i) { // 节点下标从1开始
        printf("第 %d 个结点的值：", i);
        scanf(" %c", &((*tree)[i].data)); // 修改为字符型输入格式
        (*tree)[i].parent = -1; // 初始化所有结点的双亲为-1，表示无父节点
    }
    // 设置每个结点的父节点
    printf("输入每个结点的父节点下标（1表示根节点）：\n");
    for (int i = 2; i <= n; ++i) { // 节点下标从2开始
        int parentIdx;
        printf("第 %d 个结点的父节点下标：", i);
        scanf("%d", &parentIdx);
        (*tree)[i].parent = parentIdx;
    }
}

// 将树转换为二叉树
BinaryTreeNode* convertToBinaryTree(TreeNode *tree, int n) {
    BinaryTreeNode *binaryTree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode) * (n + 1)); // 调整数组大小为 n+1
    // 初始化二叉树结点
    for (int i = 1; i <= n; ++i) { // 节点下标从1开始
        binaryTree[i].data = tree[i].data;
        binaryTree[i].child_count = 0;
        binaryTree[i].left = NULL;
        binaryTree[i].right = NULL;
    }

    for (int i = 1; i <= n; ++i) { // 节点下标从1开始
        int parentIdx = tree[i].parent;
        // 将树的结点转换为二叉树结点
        if (parentIdx != -1) {
            if (binaryTree[parentIdx].child_count == 0) {
                binaryTree[parentIdx].left = &binaryTree[i];
            } else {
                BinaryTreeNode *temp = binaryTree[parentIdx].left;
                while (temp->right != NULL) {
                    temp = temp->right;
                }
                temp->right = &binaryTree[i];
            }
            binaryTree[parentIdx].child_count++;
        }
    }
    return &binaryTree[1]; // 返回二叉树的根结点，节点下标从1开始
}

// 先序遍历二叉树
void preOrder(BinaryTreeNode *root) {
    if (root != NULL) {
        printf("%c ", root->data); // 修改为字符型输出格式
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 中序遍历二叉树
void inOrder(BinaryTreeNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%c ", root->data); // 修改为字符型输出格式
        inOrder(root->right);
    }
}

// 统计每个结点在树中的孩子数
void countChildren(TreeNode *tree, int n) {
    printf("\n每个结点在树中的孩子数统计:\n");
    for (int i = 1; i <= n; ++i) { // 节点下标从1开始
        int childCount = 0;
        for (int j = 1; j <= n; ++j) { // 节点下标从1开始
            if (tree[j].parent == i) {
                childCount++;
            }
        }
        printf("结点 %d: %d\n", i, childCount);
    }
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

    createTree(&tree, numNodes);
    BinaryTreeNode *binaryTreeRoot = convertToBinaryTree(tree, numNodes);

    printf("\n二叉树的先序遍历结果：");
    preOrder(binaryTreeRoot);

    printf("\n二叉树的中序遍历结果：");
    inOrder(binaryTreeRoot);

    countChildren(tree, numNodes);

    free(tree); // 释放动态分配的内存

    return 0;
}
