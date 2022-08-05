#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *first;

void create(int n)
{
    Node *t,*last;
    first = (Node *)malloc(sizeof(Node));
    scanf("%d",&first->data);
    first->next=NULL;
    last = first;
    for(int i=1;i<n;i++)
    {
        t=(Node *)malloc(sizeof(Node));
        scanf("%d",&t->data);
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display()
{
    Node *p;
    p=first;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void Reverse()
{
    Node *p=first,*q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void RReverse(Node *q,Node *p)
{
    if(p)
    {
        RReverse(p,p->next);
        p->next=q;
    }
    else
    {
        first=q;
        return;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    create(n);
    RReverse(NULL,first);
    Display();
    return 0;
}