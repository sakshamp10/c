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

void insert(int i, int pos)
{
    Node *t,*p;
    t=(Node *)malloc(sizeof(Node));
    t->data=i;
    t->next=NULL;
    p=first;
    if(pos==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
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
    printf("Enter the number to be inserted and position after which it should be inserted: ");
    int i,pos;
    scanf("%d %d",&i,&pos);
    insert(i,pos);
    Display(first);
    return 0;
}