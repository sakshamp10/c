#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}Node;

Node *root = NULL;

int NodeHeight(Node *p)
{
    int hl,hr;
    hl= p && p->lchild?p->lchild->height:0;
    hr= p && p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(Node *p)
{
    int hl,hr;
    hl= p && p->lchild?p->lchild->height:0;
    hr= p && p->rchild?p->rchild->height:0;
    return hl-hr;
}

Node *LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    if(p==root)
        root = pl;
    return pl;
}

Node *RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    if(p==root)
        root = pr;
    return pr;
}

Node *LRRotation(Node *p)
{
    p->lchild = RRRotation(p->lchild);
    p = LLRotation(p);
    return p;
}

Node *RLRotation(Node *p)
{
    p->rchild = LLRotation(p->rchild);
    p = RRRotation(p);
    return p;
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
        if(NodeHeight(p->lchild) > NodeHeight(p->rchild))
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
    p->height = NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0)
        return LLRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==0)
        return RRRotation(p);
    return p;
}

Node *Insert(Node *p,int key)
{
    Node *t=NULL;
    if(!p)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key<p->data)
        p->lchild=Insert(p->lchild,key);
    else if(key>p->data)
        p->rchild=Insert(p->rchild,key);
    p->height = NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
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

void preorder(Node *b)
{
    if(b)
    {
        printf("%d ",b->data);
        preorder(b->lchild);
        preorder(b->rchild);
    }
}

void postorder(Node *b)
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
    root = Insert(root,50);
    Insert(root,10);
    Insert(root,20);
    Insert(root,22);
    Insert(root,12);
    Delete(root,10);
    Insert(root,34);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}