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
int visited[maxnode] = {0};
int topsort[maxnode] = {0};
 
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
 
int dfs(int i, int id)
{
    Node *start = adjlist[id]->head;
    visited[id] = 1;
    while(start)
    {
        int x = start->id;
        if(visited[x]==0)
            i = dfs(i,x);
        start = start->next;
    }
    topsort[i] = id;
    return i-1;
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
    }
    int x,y;
    while(m--)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        addnode(x-1,y-1);
    }
    int xx = n-1;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            xx = dfs(xx,i);
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",topsort[i]+1);
    printf("\n");
    return 0;
}