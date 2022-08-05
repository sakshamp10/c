#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}Node;

Node *first;

void create(int n)
{
    Node *t,*last;
    first = (Node *)malloc(sizeof(Node));
    scanf("%d",&first->data);
    first->prev = NULL;
    first->next = NULL;
    last = first;
    for(int i=0;i<n-1;i++)
    {
        t = (Node *)malloc(sizeof(Node));
        scanf("%d",&t->data);
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display()
{
    Node *p = first;
    while(p)
    {
        printf("%d",p->data);
        p = p->next;
    }
    printf("\n");
}

void delete(int pos)
{
    if(pos==1)
    {
        first = first->next;
        first->prev = NULL;
    }
    else
    {
        Node *p,*q;
        p = first;
        for(int i=0;i<pos-1;i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    create(n);
    display();
    delete(3);
    display();
    return 0;
}