#include<stdio.h>

int size=0,numcomponents=0;
int iden[1000],sz[1000];

void CreateUnionFind(int n)
{
    if(n==0)
        return;
    size = numcomponents = n;
    for(int i=0;i<size;i++)
    {
        iden[i] = i;
        sz[i] = 1;
    }
}

int Find(int p)
{
    int root=p;
    while(iden[root]!=root)
    {
        root = iden[root];
    }
    int temp;
    while(p!=root)
    {
        temp = iden[p];
        iden[p] = root;
        p = temp;
    }
    return root;
}

void Union(int p, int q)
{
    int root1 = find(p);
    int root2 = find(q);
    if(root1==root2)
        return;
    if(sz[root1]>sz[root2])
    {
        sz[root1]+=sz[root2];
        iden[root2] = root1;
        sz[root2] = 0;
    }
    else
    {
        sz[root2]+=sz[root1];
        iden[root1] = root2;
        sz[root1] = 0;
    }
    numcomponents--;
}