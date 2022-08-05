#include <stdio.h>

int main()
{
    char A[] = "finding";
    long int x,h=0;
    for(int i=0;A[i]!='\0';i++)
    {
        x = 1;
        int dum = A[i] - 97;
        x = x << dum;
        if(x&h>0)
        printf("The character %c is duplicate\n",A[i]);
        else
        h = h | x;
    }
    return 0;
}