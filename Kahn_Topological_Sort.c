#include <stdio.h>
#include <stdlib.h>
#define maxnode 100000
#define ll long long int
 
typedef struct Node
{
    int  id;
    struct Node *next;
}Node;
 
typedef struct List
{
    Node *head;
}List;
 
List *adjlist[maxnode];
List *inlist[maxnode];
int indegreee[maxnode] = {0};
int topsort[maxnode] = {0};

typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;

QNode *front=NULL, *rear = NULL;

void enque(int x)
{
    QNode *t;
    t = (QNode *)malloc(sizeof(QNode));
    if(front)
    {
        t->data = x;
        t->next = NULL;
        rear->next = t;
        rear = t;
    }
    else
    {
        t->data = x;
        t->next = NULL;
        front = rear = t;
    }
}

int deque()
{
    QNode *p;
    int s;
    if(front)
    {
        p = front;
        front = front->next;
        s = p->data;
        free(p);
    }
    return s;
}

int isEmpty()
{
    if(front)
        return 1;
    else 
        return 0;
}

void addnode(int x, int y)
{
    Node *temp,*dest;
    dest = (Node *)malloc(sizeof(Node));
    dest->id = y;
    dest->next = NULL;
    temp = adjlist[x]->head;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = dest;
}

void addnode2(int x, int y)
{
    Node *temp,*dest;
    dest = (Node *)malloc(sizeof(Node));
    dest->id = y;
    dest->next = NULL;
    temp = inlist[x]->head;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = dest;
}

int indegree(int id)
{
    Node *start = inlist[id]->head;
    int count=0;
    while(start->next)
    {
        count++;
        start = start->next;
    }
    return count;
}

int main()
{
    Node *src;
    int n;
    ll m;
    scanf("%d",&n);
    scanf("%lld",&m);
    for(int i=0;i<n;i++)
    {
        adjlist[i] = (List*)malloc(sizeof(List));
        adjlist[i]->head = NULL;
        src = (Node *)malloc(sizeof(Node));
        src->id = i;
        src->next = NULL;
        adjlist[i]->head = src;
        inlist[i] = (List*)malloc(sizeof(List));
        inlist[i]->head = NULL;
        src = (Node *)malloc(sizeof(Node));
        src->id = i;
        src->next = NULL;
        inlist[i]->head = src;
    }
    int x,y;
    while(m--)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        addnode(x-1,y-1);
        addnode2(y-1,x-1);
    }
    for(int i=0;i<n;i++)
        indegreee[i] = indegree(i);
    for(int i=0;i<n;i++)
    {
        if(indegreee[i]==0)
            enque(i);
    }
    int index = 0,de,xx;
    Node *temp;
    while(isEmpty())
    {
        de = deque();
        topsort[index++] = de;
        temp = adjlist[de]->head;
        while(temp->next)
        {
            temp = temp->next;
            xx = temp->id;
            indegreee[xx]--;
            if(indegreee[xx]==0)
                enque(xx);
        }
    }
    for(int i=0;i<index;i++)
        printf("%d ",topsort[i]+1);
    printf("\n");
    return 0;
}