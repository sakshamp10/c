#include <stdio.h>
#include <stdlib.h>

int s[2];
int dr[4] = {0,1,-1,0};
int dc[4] = {1,0,0,-1};

typedef struct Node
{
    int x;
    int y;
    struct Node *next;
}Node;

Node *front=NULL, *rear = NULL;

void enque(int x,int y)
{
    Node *t;
    t = (Node *)malloc(sizeof(Node));
    if(front)
    {
        t->x = x;
        t->y = y;
        t->next = NULL;
        rear->next = t;
        rear = t;
    }
    else
    {
        t->x = x;
        t->y = y;
        t->next = NULL;
        front = rear = t;
    }
}

int *deque()
{
    Node *p;
    if(front)
    {
        p = front;
        front = front->next;
        s[0] = p->x;
        s[1] = p->y;
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

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int grid[n][m];
    int visited[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&grid[i][j]);
            visited[i][j] = 0;
        }
    }
    int sr,sc,color;
    scanf("%d %d %d",&sr,&sc,&color);
    visited[sr][sc] = 1;
    enque(sr,sc);
    int r,c;
    int *arr;
    while(isEmpty())
    {
        arr = deque();
        r = arr[0];
        c = arr[1];
        int rr,cc;
        for(int i=0;i<4;i++)
        {
            rr = r + dr[i];
            cc = c + dc[i];
            if(rr>=n || cc>= m)
                continue;
            if(rr<0 || cc<0)
                continue;
            if(grid[rr][cc]!=grid[r][c])
                continue;
            if(visited[rr][cc])
                continue;
            visited[rr][cc] = 1;
            enque(rr,cc);
        }
        grid[r][c] = color;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}