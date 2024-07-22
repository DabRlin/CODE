#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;       // 结点的数据
    int parent;      // 父节点索引
    int index;       // 节点的索引属性
} TreeNode;

typedef struct BinaryTreeNode {
    char data;               // 数据
    struct BinaryTreeNode *left;    // 左孩子
    struct BinaryTreeNode *right;   // 右孩子
} BinaryTreeNode;

// 创建树的函数，基于用户输入
void createTree(TreeNode **tree, int n) {
    *tree = (TreeNode *)malloc(sizeof(TreeNode) * (n + 1));
    printf("输入树的结点值：\n");
    for (int i = 1; i <= n; ++i) {
        printf("第 %d 个结点的值：", i);
        scanf(" %c", &((*tree)[i].data));
        (*tree)[i].parent = -1;
        (*tree)[i].index = i; // 设置结点索引
    }
    printf("输入每个结点的父节点下标(1表示根节点)：\n");
    for (int i = 2; i <= n; ++i) {
        int parentIdx;
        printf("第 %d 个结点的父节点下标：", i);
        scanf("%d", &parentIdx);
        (*tree)[i].parent = parentIdx;
    }
}

// 将TreeNode树转换为BinaryTreeNode树的函数
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
    return &binaryTree[1]; // 返回二叉树的根节点
}

// 二叉树的先序遍历
void preOrder(BinaryTreeNode *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 二叉树的中序遍历
void inOrder(BinaryTreeNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%c ", root->data);
        inOrder(root->right);
    }
}

// 计算二叉树每个节点的孩子数
void countChildren(BinaryTreeNode *root, int *childCount, int *indexArray) {
    if (root == NULL) {
        return;
    }

    int index = indexArray[root->data - 'a']; // 使用索引数组来获取节点的索引

    int count = 0;
    if (root->left != NULL) {
        count++;
    }
    if (root->right != NULL) {
        count++;
    }

    childCount[index] = count; // 存储节点的孩子数

    countChildren(root->left, childCount, indexArray);
    countChildren(root->right, childCount, indexArray);
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

    // 输出二叉树的先序遍历结果
    printf("\n二叉树的先序遍历结果：");
    preOrder(binaryTreeRoot);

    // 输出二叉树的中序遍历结果
    printf("\n二叉树的中序遍历结果：");
    inOrder(binaryTreeRoot);
    
    int *childCount = (int *)malloc(sizeof(int) * (numNodes + 1));
    int *indexArray = (int *)malloc(sizeof(int) * ('z' - 'a' + 1)); // 为索引数组分配内存

    for (int i = 0; i <= 'z' - 'a'; ++i) {
        indexArray[i] = -1; // 初始化索引数组
    }

    for (int i = 1; i <= numNodes; ++i) {
        indexArray[tree[i].data - 'a'] = tree[i].index; // 为索引数组赋值
        childCount[i] = 0;
    }

    countChildren(binaryTreeRoot, childCount, indexArray);

    printf("\n转换后二叉树每个节点的孩子数目：\n");
    for (int i = 1; i <= numNodes; ++i) {
        printf("节点 [%c] 的孩子数目：%d\n", tree[i].data, childCount[i]);
    }

    free(tree);
    free(childCount);
    free(indexArray);

    return 0;
}
