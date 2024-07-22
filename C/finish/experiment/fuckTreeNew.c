#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
typedef struct node
{
	char info;
	struct node* lchild;
	struct node* rchild;
}tree;
typedef struct stack_1
{
	tree* a[MAX];
	int tag[MAX];
	int top;
}stack;
void push(stack* st, tree* t)
{
	st->a[st->top] = t;
	st->top++;
}
tree* pop(stack* st)
{
	if (st->top != 0)
	{
		st->top--;
		return st->a[st->top];
	}
	else
		return NULL;
}
tree* top(stack* st)
{
	if (st->top != 0)
	{
		return st->a[st->top - 1];
	}
	else
	{
		return NULL;
	}
}
tree *create()
{
	stack A;
	stack *st;
	st = &A;
	tree *root;
	tree *p1, *p2;
	int i = 0;
	char ch[MAX];
	scanf_s("%s", ch, MAX);
	st->top = 0;
	while (ch[i] != '\0')
	{
		if (i == 0)
		{
			root = (tree*)malloc(sizeof(tree));
			root->info = ch[i];
			root->lchild = NULL;
			root->rchild = NULL;
			p1 = root;
			push(st, p1);
			st->tag[st->top - 1] = 0;
			

		}
		else
		{
			if (ch[i] != '#'&&st->tag[st->top - 1] == 0)
			{
				p2 = (tree*)malloc(sizeof(tree));
				p2->info = ch[i];
				p2->lchild = NULL;
				p2->rchild = NULL;
				push(st, p2);
				p1->lchild = p2;
				p1 = p2;
				st->tag[st->top - 1] = 0;
			}
			else if (ch[i] == '#'&&st->tag[st->top - 1] == 0)
			{
				p1->lchild = NULL;
				st->tag[st->top - 1] = 1;
			}
			else if (ch[i] == '#'&&st->tag[st->top - 1] == 1)
			{
				p1->rchild = NULL;
				st->tag[st->top - 1] = 2;
			}
			else if (ch[i] != '#'&&st->tag[st->top - 1] == 1)
			{
				p2 = (tree*)malloc(sizeof(tree));
				p2->info = ch[i];
				p2->lchild = NULL;
				p2->rchild = NULL;
				push(st, p2);
				p1->rchild = p2;
				p1 = p2;
				st->tag[st->top - 1] = 0;
			}
			while (st->tag[st->top - 1] == 2)
			{
				st->tag[st->top - 1] = 0;
				p1 = pop(st);
				
				if (st->top != 0)
					p1 = top(st);
				else
					break;
				if (st->tag[st->top - 1] == 1)
				{
					st->tag[st->top - 1] = 2;
				}
			}
			if (p1->lchild != NULL || st->tag[st->top - 1] ==1)
			{
				st->tag[st->top - 1] = 1;
			}
			
		}
		i++;
	}
	return root;

}
void preprint(tree* t)
{
	tree* p1;
	p1 = t;
	if (!p1)
		return;
	else
	{
		printf("%c->", p1->info);
		preprint(p1->lchild);
		preprint(p1->rchild);

	}
}
void inorprint(tree* t)
{
	tree* p1;
	p1 = t;
	if (!p1)
		return;
	else
	{
		inorprint(p1->lchild);
		printf("%c->", p1->info);
		inorprint(p1->rchild);

	}
}

void iterativePreorder(tree* root) {
    if (root == NULL) return;

    stack st;
    st.top = 0;
    tree* current = root;

    while (current != NULL || st.top != 0) {
        while (current != NULL) {
            printf("%c->", current->info);
            push(&st, current);
            current = current->lchild;
        }

        if (st.top != 0) {
            current = pop(&st);
            current = current->rchild;
        }
    }
}
//中序遍历
void iterativeInorder(tree* root) {
    if (root == NULL) return;

    stack st;
    st.top = 0;
    tree* current = root;

    while (current != NULL || st.top != 0) {
        while (current != NULL) {
            push(&st, current);
            current = current->lchild;
        }

        current = pop(&st);
        printf("%c->", current->info);
        current = current->rchild;
    }
}
//后序遍历
void iterativePostorder(tree* root) {
    if (root == NULL) return;

    stack st;
    st.top = 0;
    tree* current = root;
    tree* lastVisited = NULL;

    while (current != NULL || st.top != 0) {
        while (current != NULL) {
            push(&st, current);
            current = current->lchild;
        }

        current = top(&st);

        if (current->rchild == NULL || current->rchild == lastVisited) {
            printf("%c->", current->info); 
            pop(&st);
            lastVisited = current;
            current = NULL;
        } else {
            current = current->rchild;
        }
    }
}

int main() {
    tree* root;
    printf("输入一组数据(以#分隔):\n");
    root = create();
    
    printf("先序遍历：");
    iterativePreorder(root);
    printf("\n");

    printf("中序遍历：");
    iterativeInorder(root);
    printf("\n");

    printf("后序遍历：");
    iterativePostorder(root);
    printf("\n");

    return 0;
}

