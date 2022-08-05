#include <stdio.h>
#include <stdlib.h>
typedef long long int ll;
 
typedef struct Node
{
    ll id;
    ll weight;
    struct Node *next;
}Node;
 
void addnode(Node **graph, ll x, ll y, ll z)
{
    Node *dest, *temp;
    dest = (Node*)malloc(sizeof(Node));
    dest->id = y;
    dest->weight = z;
    dest->next = NULL;
    temp = graph[x];
    while(temp->next)
        temp = temp->next;
    temp->next = dest;
}
 
void swap(Node **graph, ll i, ll j)
{
    Node *temp = graph[i];
    graph[i] = graph[j];
    graph[j] = temp;
}
 
ll size = 0;
 
void enque(Node **pq, Node *p)
{
    if(size==0)
    {
        pq[size++] = p;
        return;
    }
    pq[size++] = p;
    ll i = size-1;
    while(i>0 && p->weight<pq[(i-1)/2]->weight)
    {
        pq[i] = pq[(i-1)/2];
        i = (i-1)/2;
    }
    pq[i] = p;
}
 
Node *deque(Node **pq)
{
    Node *ret = pq[0];
    size--;
    pq[0] = pq[size];
    ll i = 0;
    ll j = 2*i + 1;
    while(j<size)
    {
        if(pq[j]->weight > pq[j+1]->weight)
            j++;
        if(pq[i]->weight > pq[j]->weight)
        {
            swap(pq,i,j);
            i = j;
            j = 2*j + 1;
        }
        else
            break;
    }
    return ret;
}
 
int main()
{
    ll n,m;
    scanf("%lld %lld",&n,&m);
    // scanf("%lld",&m);
    Node** graph = (Node**)malloc(n*sizeof(Node));
    Node *t;
    for(ll i=0;i<n;i++)
    {
        t = (Node*)malloc(sizeof(Node));
        t->id = i;
        t->weight = 0;
        t->next = NULL;
        graph[i] = t;
    }
    ll x,y,z;
    for(ll i=0;i<m;i++)
    {
        scanf("%lld %lld %lld",&x,&y,&z);
        addnode(graph,x-1,y-1,z);
    }
    Node **pq;
    ll dist[n],vis[n];
    dist[0] = 0;vis[0] = 0;
    for(ll i=1;i<n;i++)
    {
        dist[i] = 1000000000;
        vis[i] = 0;
    }
    pq = (Node**)malloc(m*sizeof(Node));
    enque(pq,graph[0]);
    Node *t1,*t2;
    ll index, minval, newdist;
    while(size)
    {
        t1 = deque(pq);
        index = t1->id;
        minval = t1->weight;
        vis[index] = 1;
        if(dist[index]<minval)
            continue;
        t2 = graph[index];
        while(t2->next)
        {
            t2 = t2->next;
            if(vis[t2->id])
               continue;
            newdist = dist[index] + t2->weight;
            if(newdist < dist[t2->id])
            {
                dist[t2->id] = newdist;
                t2->weight = newdist;
                enque(pq,t2);
            }
        }
    }
    for(ll i=0;i<n;i++)
        printf("%lld ",dist[i]);
    return 0;
}