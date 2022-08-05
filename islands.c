#include  <stdio.h>
#include <stdlib.h>

int grid[10000][10000];

void dfs(int grid[][10000],int x, int y, int n, int m)
{
    if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=1)
        return;
    grid[x][y] = 2;
    dfs(grid,x+1,y,n,m);
    dfs(grid,x,y+1,n,m);
    dfs(grid,x-1,y,n,m);
    dfs(grid,x,y-1,n,m);
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }
    int islands = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                islands++;
                dfs(grid,i,j,n,m);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",islands);
    return 0;
}