#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    int parent;
} TreeNode;

typedef struct BinaryTreeNode {
    char data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

void createTree(TreeNode **tree, int n) {
    *tree = (TreeNode *)malloc(sizeof(TreeNode) * (n + 1));
    printf("输入树的结点值：\n");
    for (int i = 1; i <= n; ++i) {
        printf("第 %d 个结点的值：", i);
        scanf(" %c", &((*tree)[i].data));
        (*tree)[i].parent = -1;
    }
    printf("输入每个结点的父节点下标(1表示根节点)：\n");
    for (int i = 2; i <= n; ++i) {
        int parentIdx;
        printf("第 %d 个结点的父节点下标：", i);
        scanf("%d", &parentIdx);
        (*tree)[i].parent = parentIdx;
    }
}

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

void preOrder(BinaryTreeNode *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(BinaryTreeNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%c ", root->data);
        inOrder(root->right);
    }
}

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

    childCount[root->data - 'A' + 1] = count;

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

    createTree(&tree, numNodes);

    BinaryTreeNode *binaryTreeRoot = convertToBinaryTree(tree, numNodes);

    printf("\n二叉树的先序遍历结果：");
    preOrder(binaryTreeRoot);

    printf("\n二叉树的中序遍历结果：");
    inOrder(binaryTreeRoot);

    int *childCount = (int *)malloc(sizeof(int) * (numNodes + 1));
    for (int i = 1; i <= numNodes; ++i) {
        childCount[i] = 0;
    }

    countChildren(binaryTreeRoot, childCount);

    printf("\n转换后二叉树每个节点的孩子数目：\n");
    for (int i = 1; i <= numNodes; ++i) {
        printf("节点 [%c] 的孩子数目：%d\n", binaryTreeRoot[i].data, childCount[i]);
    }

    free(tree);
    free(childCount);
    free(binaryTreeRoot);

    return 0;
}
