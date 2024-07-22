// #include <stdio.h>
// #include <stdlib.h>

// // 定义二叉树节点结构
// typedef struct TreeNode {
//     int data;
//     struct TreeNode *left;
//     struct TreeNode *right;
// } TreeNode;

// // 创建新节点
// TreeNode* createNode(int data) {
//     TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
//     if (!newNode) {
//         printf("内存分配失败\n");
//         return NULL;
//     }
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// // 插入节点
// TreeNode* insertNode(TreeNode *root, int data) {
//     if (root == NULL) {
//         root = createNode(data);
//         return root;
//     }
    
//     if (data < root->data) {
//         root->left = insertNode(root->left, data);
//     } else {
//         root->right = insertNode(root->right, data);
//     }
    
//     return root;
// }

// // 查找节点
// TreeNode* searchNode(TreeNode *root, int data) {
//     if (root == NULL || root->data == data) {
//         return root;
//     }
    
//     if (data < root->data) {
//         return searchNode(root->left, data);
//     } else {
//         return searchNode(root->right, data);
//     }
// }

// // 找到树中最小值节点
// TreeNode* findMinNode(TreeNode *root) {
//     while (root && root->left != NULL) {
//         root = root->left;
//     }
//     return root;
// }

// // 删除节点
// TreeNode* deleteNode(TreeNode *root, int data) {
//     if (root == NULL) {
//         return root;
//     }
    
//     if (data < root->data) {
//         root->left = deleteNode(root->left, data);
//     } else if (data > root->data) {
//         root->right = deleteNode(root->right, data);
//     } else {
//         // 节点只有一个子节点或无子节点
//         if (root->left == NULL) {
//             TreeNode *temp = root->right;
//             free(root);
//             return temp;
//         } else if (root->right == NULL) {
//             TreeNode *temp = root->left;
//             free(root);
//             return temp;
//         }
        
//         // 节点有两个子节点
//         TreeNode *temp = findMinNode(root->right);
//         root->data = temp->data;
//         root->right = deleteNode(root->right, temp->data);
//     }
//     return root;
// }

// // 前序遍历
// void preorderTraversal(TreeNode *root) {
//     if (root == NULL) {
//         return;
//     }
//     printf("%d ", root->data);
//     preorderTraversal(root->left);
//     preorderTraversal(root->right);
// }

// // 中序遍历
// void inorderTraversal(TreeNode *root) {
//     if (root == NULL) {
//         return;
//     }
//     inorderTraversal(root->left);
//     printf("%d ", root->data);
//     inorderTraversal(root->right);
// }

// // 后序遍历
// void postorderTraversal(TreeNode *root) {
//     if (root == NULL) {
//         return;
//     }
//     postorderTraversal(root->left);
//     postorderTraversal(root->right);
//     printf("%d ", root->data);
// }

// // 销毁树
// void destroyTree(TreeNode *root) {
//     if (root == NULL) {
//         return;
//     }
//     destroyTree(root->left);
//     destroyTree(root->right);
//     free(root);
// }

// // 主函数
// int main() {
//     TreeNode *root = NULL;
//     root = insertNode(root, 50);
//     root = insertNode(root, 30);
//     root = insertNode(root, 70);
//     root = insertNode(root, 20);
//     root = insertNode(root, 40);
//     root = insertNode(root, 60);
//     root = insertNode(root, 80);

//     printf("前序遍历: ");
//     preorderTraversal(root);
//     printf("\n");

//     printf("中序遍历: ");
//     inorderTraversal(root);
//     printf("\n");

//     printf("后序遍历: ");
//     postorderTraversal(root);
//     printf("\n");

//     printf("删除节点 20\n");
//     root = deleteNode(root, 20);
//     printf("中序遍历: ");
//     inorderTraversal(root);
//     printf("\n");

//     printf("删除节点 30\n");
//     root = deleteNode(root, 30);
//     printf("中序遍历: ");
//     inorderTraversal(root);
//     printf("\n");

//     printf("删除节点 50\n");
//     root = deleteNode(root, 50);
//     printf("中序遍历: ");
//     inorderTraversal(root);
//     printf("\n");

//     destroyTree(root);
//     return 0;
// }
