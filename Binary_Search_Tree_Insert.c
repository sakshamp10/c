#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}Node;

Node *root = NULL;

void Insert(int key)
{
    Node *t = root;
    Node *p,*r;
    if(!root)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while(t)
    {
        r = t;
        if(key<t->data)
        {
            t = t->lchild;
        }
        else if(key>t->data)
        {
            t = t->rchild;
        }
        else if(key = t->data)
        {
            return;
        }
    }
    p = (Node *)malloc(sizeof(Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(key<r->data) r->lchild = p;
    else r->rchild = p;
}

Node *Search(int key)
{
    Node *t=root;
    while(t)
    {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t = t->lchild;
        else if(key>t->data)
            t = t->rchild;
    }
    return NULL;
}

Node *RInsert(Node *p, int key)
{
    Node *t=NULL;
    if(!p)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild,key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild,key);

    return p;
}

int Height(Node *p)
{
    if(!p)
        return 0;
    int x = Height(p->lchild);
    int y = Height(p->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

Node *InPre(Node *p)
{
    while(p && p->rchild)
        p = p->rchild;
    return p;
}

Node *InSuc(Node *p)
{
    while(p && p->lchild)
        p = p->lchild;
    return p;
}

Node *Delete(Node *p, int key)
{
    Node *q;
    if(!p)
        return NULL;
    if(!p->lchild && !p->rchild)
    {
        if(p==root)
            root = NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSuc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

void inorder(Node *b)
{
    if(b)
    {
        inorder(b->lchild);
        printf("%d ",b->data);
        inorder(b->rchild);
    }
}

int main()
{
    struct Node *temp;
    root = RInsert(root,10);
    RInsert(root,5);
    RInsert(root,20);
    RInsert(root,8);
    RInsert(root,22);
    RInsert(root,30);
    Delete(root,20);
    inorder(root);
    printf("\n");
    temp = Search(20);
    if(temp)
        printf("Element %d found\n",temp->data);
    else
        printf("Element not found\n");
    return 0;
}
