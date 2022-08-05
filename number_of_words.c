#include<stdio.h>

int main()
{
    char A[] = "Yo bruv how you doin";
    int count = 0;
    for(int i=1;A[i]!='\0';i++)
    {
        if(A[i]==' ' && A[i-1] !=' ')
        count++;
    }
    printf("Number of words are: %d\n",count+1);
    return 0;
}