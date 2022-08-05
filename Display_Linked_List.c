#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *first;

void create(int A[], int n)
{
    Node *t,*last;
    first = (Node *)malloc(sizeof(Node));
    first->data=A[0];
    first->next=NULL;
    last = first;
    for(int i=1;i<n;i++)
    {
        t=(Node *)malloc(sizeof(Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void RDisplay(Node *p)
{
    if(p)
    {
        RDisplay(p->next);
        printf("%d ",p->data);
    }
}

int main()
{
    int arr[]={2,6,4,23,5,1,9};
    create(arr,7);
    RDisplay(first);
    return 0;
}