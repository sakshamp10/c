#include <stdio.h>
#include <stdlib.h>

#define N 9

int safe(int row, int col,int board[9][9],int val)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==val)
            return 0;
        if(board[i][col]==val)
            return 0;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
            return 0;
    }
    return 1;
}

int solve(int board[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==0)
            {
                for(int k = 1;k<=9;k++)
                {
                    if(safe(i,j,board,k))
                    {
                        board[i][j] = k;
                        int x = solve(board);
                        if(x)
                            return 1;
                        else
                            board[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    char x;
    int board[9][9];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(i==8 && j==8)
            {
                scanf("%c",&x);
                if(x=='.')
                board[i][j] = 0;
                if(x=='1')
                    board[i][j] = 1;
                if(x=='2')
                    board[i][j] = 2;
                if(x=='3')
                    board[i][j] = 3;
                if(x=='4')
                    board[i][j] = 4;
                if(x=='5')
                    board[i][j] = 5;
                if(x=='6')
                    board[i][j] = 6;
                if(x=='7')
                    board[i][j] = 7;
                if(x=='8')
                    board[i][j] = 8;
                if(x=='9')
                    board[i][j] = 9;
            }
            else
            {
                scanf("%c ",&x);
                if(x=='.')
                    board[i][j] = 0;
                if(x=='1')
                    board[i][j] = 1;
                if(x=='2')
                    board[i][j] = 2;
                if(x=='3')
                    board[i][j] = 3;
                if(x=='4')
                    board[i][j] = 4;
                if(x=='5')
                    board[i][j] = 5;
                if(x=='6')
                    board[i][j] = 6;
                if(x=='7')
                    board[i][j] = 7;
                if(x=='8')
                    board[i][j] = 8;
                if(x=='9')
                    board[i][j] = 9;
            }
        }
    }
    solve(board);
    for (int i = 0; i < 9; i++)
      {
         for (int j = 0; j < 9; j++)
            printf("%d ",board[i][j]);
         printf("\n");
       }
    return 0;
}