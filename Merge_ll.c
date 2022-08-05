#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *first,*second,*third;

Node *create(int n)
{
    Node *t,*last;
    first = (Node *)malloc(sizeof(Node));
    scanf("%d",&first->data);
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t = (Node *)malloc(sizeof(Node));
        scanf("%d",&t->data);
        t->next=NULL;
        last->next=t;
        last=t;
    }
    return first;
}

void Merge(struct Node *p,struct Node *q)
{
 struct Node *last;
 if(p->data < q->data)
 {
 third=last=p;
 p=p->next;
 third->next=NULL;
 }
 else
 {
 third=last=q;
 q=q->next;
 third->next=NULL;
 }
 while(p && q)
 {
 if(p->data < q->data)
 {
 last->next=p;
 last=p;
 p=p->next;
 last->next=NULL;

 }
 else
 {
 last->next=q;
 last=q;
 q=q->next;
 last->next=NULL;

 }
 }
 if(p)last->next=p;
 if(q)last->next=q;

}

void Display(Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    first = create(n);
    Display(first);
    second = create(n);
    Display(second);
    Merge(first,second);
    Display(third);
    return 0;
}