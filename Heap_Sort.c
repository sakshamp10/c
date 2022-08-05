#include <stdio.h>

void insert(int A[],int n)
{
    int i=n;
    int temp;
    temp = A[n];
    while(i>1 && temp>A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

void Delete(int A[],int n)
{
    int i,j,val,temp;
    val = A[1];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = 2*i;
    while(j<=n-1)
    {
        if(j<(n-1) && A[j]<A[j+1])
            j = j+1;
        if(A[i]<A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = j*2;
        }
        else
            break;
    }
}

int main()
{
    int arr[100] = {0,14,65,23,43,98,33,54};
    int i;
    for(i=2;i<=7;i++)
        insert(arr,i);
    for(i=7;i>=2;i--)
        Delete(arr,i);
    for(i=1;i<=7;i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}