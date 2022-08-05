#include <stdio.h>
#include <stdlib.h>

typedef struct Bnode
{
    struct Bnode *lchild;
    int data;
    struct Bnode *rchild;
}Bnode;

typedef struct Qnode
{
    Bnode *address;
    struct Qnode *next;
}Qnode;

Qnode *front=NULL,*rear=NULL;

void enque(Bnode *b)
{
    Qnode *t;
    t = (Qnode *)malloc(sizeof(Qnode));
    t->address = b;
    t->next = NULL;
    if(front==NULL)
    {
        front=rear=t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
}

Bnode *deque()
{
    Bnode *x=NULL;
    Qnode *t;
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x = front->address;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

int isempty()
{
    if(front==NULL)
    return 0;
    else
    return 1;
}

Bnode *root = NULL;

void create()
{
    int x;
    Bnode *p,*t;
    root = (Bnode *)malloc(sizeof(Bnode));
    printf("Enter the root value: ");
    scanf("%d",&root->data);
    root->lchild=root->rchild=NULL;
    enque(root);
    while(isempty())
    {
        p = deque();
        printf("Enter left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t = (Bnode *)malloc(sizeof(Bnode));
            t->data = x;
            t->lchild=t->rchild=NULL;
            p->lchild = t;
            enque(t);
        }
        printf("Enter right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t = (Bnode *)malloc(sizeof(Bnode));
            t->data = x;
            t->lchild=t->rchild=NULL;
            p->rchild = t;
            enque(t);
        }
    }
}

void preorder(Bnode *b)
{
    if(b)
    {
        printf("%d ",b->data);
        preorder(b->lchild);
        preorder(b->rchild);
    }
}

void inorder(Bnode *b)
{
    if(b)
    {
        inorder(b->lchild);
        printf("%d ",b->data);
        inorder(b->rchild);
    }
}

void postorder(Bnode *b)
{
    if(b)
    {
        postorder(b->lchild);
        postorder(b->rchild);
        printf("%d ",b->data);
    }
}


int main()
{
    create();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}