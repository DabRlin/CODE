#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 创建新节点
struct TreeNode *createNode(char value) {
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

    char value;
    printf("输入先序遍历顺序（以 * 结束输入，使用 # 表示空节点）：\n");
    while (1) {
        scanf(" %c", &value);
        if (value == '*') {
            break;
        }

        struct TreeNode *newNode = createNode(value);

        if (root == NULL) {
            root = newNode;
        } else {
            struct TreeNode *temp = NULL;
            if (stack->top != -1) {
                temp = stack->array[stack->top];
            }
            if (temp != NULL) {
                if (temp->left == NULL) {
                    temp->left = newNode;
                } else if(temp->right == NULL){
                    temp->right = newNode;
                }
            }
        }
        push(stack, newNode);
    }

    free(stack->array);
    free(stack);
    return root;
}

// 先序遍历，跳过空节点
void preOrderSkipEmpty(struct TreeNode *root) {
    if (root != NULL) {
        if (root->data != '#') {
            printf("%c ", root->data);
        }
        preOrderSkipEmpty(root->left);
        preOrderSkipEmpty(root->right);
    }
}

// 中序遍历，跳过空节点
void inOrderSkipEmpty(struct TreeNode *root) {
    if (root != NULL) {
        inOrderSkipEmpty(root->left);
        if (root->data != '#') {
            printf("%c ", root->data);
        }
        inOrderSkipEmpty(root->right);
    }
}

// 后序遍历，跳过空节点
void postOrderSkipEmpty(struct TreeNode *root) {
    if (root != NULL) {
        postOrderSkipEmpty(root->left);
        postOrderSkipEmpty(root->right);
        if (root->data != '#') {
            printf("%c ", root->data);
        }
    }
}


//非递归先序遍历
void iterativePreorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Stack {
        int top;
        int capacity;
        struct TreeNode **array;
    };

    struct Stack *stack = createStack(100);
    push(stack, root);

    while (!isEmpty(stack)) {
        struct TreeNode* node = pop(stack);
        if (node->data != '#') {
            printf("%c ", node->data);
        }

        if (node->right != NULL) push(stack, node->right);
        if (node->left != NULL) push(stack, node->left);
    }
    free(stack->array);
    free(stack);
}



//非递归中序遍历
void iterativeInorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Stack {
        int top;
        int capacity;
        struct TreeNode **array;
    };

    struct Stack *stack = createStack(100);
    struct TreeNode* curr = root;

    while (curr != NULL || !isEmpty(stack)) {
        while (curr != NULL) {
            if (curr->data != '#') {
                push(stack, curr);
            }
            curr = curr->left;
        }

        if (!isEmpty(stack)) {
            curr = pop(stack);
            printf("%c ", curr->data);
            curr = curr->right;
        }
    }
    free(stack->array);
    free(stack);
}


//非递归后序遍历
void iterativePostorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct Stack {
        int top;
        int capacity;
        struct TreeNode **array;
    };

    struct Stack *stack = createStack(100);
    struct Stack *output = createStack(100);
    push(stack, root);

    while (!isEmpty(stack)) {
        struct TreeNode* node = pop(stack);
        push(output, node);

        if (node->left != NULL) push(stack, node->left);
        if (node->right != NULL) push(stack, node->right);
    }

    while (!isEmpty(output)) {
        struct TreeNode* node = pop(output);
        if (node->data != '#') {
            printf("%c ", node->data);
        }
    }
    free(stack->array);
    free(stack);
    free(output->array);
    free(output);
}


int main() {
    struct TreeNode *root = buildTree();

    printf("先序遍历结果：\n");
    preOrderSkipEmpty(root);
    printf("先序遍历结果（非递归）：\n");
    iterativePreorder(root);
    printf("\n");

    printf("中序遍历结果（跳过空节点）：\n");
    inOrderSkipEmpty(root);
    printf("中序遍历结果（非递归）：\n");
    iterativeInorder(root);
    printf("\n");

    printf("后序遍历结果（跳过空节点）：\n");
    postOrderSkipEmpty(root);
    printf("后序遍历结果（非递归）：\n");
    iterativePostorder(root);
    printf("\n");

    return 0;
}
