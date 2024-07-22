#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 创建新节点
struct TreeNode *createNode(int value) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 栈结构体定义
struct Stack {
    int top;
    int capacity;
    struct TreeNode **array;
};

// 创建栈
struct Stack *createStack(int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct TreeNode **)malloc(stack->capacity * sizeof(struct TreeNode *));
    return stack;
}

// 判断栈是否为空
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// 入栈操作
void push(struct Stack *stack, struct TreeNode *item) {
    stack->array[++stack->top] = item;
}

// 出栈操作
struct TreeNode *pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return NULL;
}

// 非递归先序遍历建立二叉树
struct TreeNode *buildTree() {
    struct TreeNode *root = NULL;
    struct Stack *stack = createStack(100);

    int value;
    printf("输入先序遍历顺序（以-1结束输入）：\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }

        struct TreeNode *newNode = createNode(value);

        if (root == NULL) {
            root = newNode;
        } else {
            struct TreeNode *temp = NULL;
            while (!isEmpty(stack) && stack->array[stack->top]->data < newNode->data) {
                temp = pop(stack);
            }
            if (temp != NULL) {
                temp->right = newNode;
            } else {
                stack->array[stack->top]->left = newNode;
            }
        }
        push(stack, newNode);
    }

    free(stack->array);
    free(stack);
    return root;
}

// 打印二叉树（先序遍历）
void preOrder(struct TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
//中序遍历
void inOrder(struct TreeNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// 后序遍历
void postOrder(struct TreeNode *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct TreeNode *root = buildTree();

    printf("先序遍历结果：\n");
    preOrder(root);
    printf("\n");

    printf("中序遍历结果：\n");
    inOrder(root);
    printf("\n");

    printf("后序遍历结果：\n");
    postOrder(root);
    printf("\n");

    return 0;
}
