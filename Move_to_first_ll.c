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
    last=first;
    for(int i=1;i<n;i++)
    {
        t = (Node *)malloc(sizeof(Node));
        scanf("%d",&t->data);
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
    printf("\n");
}

void Move(Node *p, int e)
{
    Node *q;
    if(p->data==e)
    return;
    q=p->next;
    while(q)
    {
        if(q->data==e)
        {
            p->next=q->next;
            q->next=first;
            first=q;
            return;
        }
        q=q->next;
        p=p->next;
    }
}

int main()
{
    int n;
    printf("Enter the size of linked list: ");
    scanf("%d",&n);
    printf("Enter the elements of the linked list space seperated: ");
    create(n);
    printf("The elements of the linked list are: ");
    Display(first);
    int e;
    printf("\nEnter the element to be moved to first: ");
    scanf("%d",&e);
    Move(first,e);
    Display(first);
    return 0;
}