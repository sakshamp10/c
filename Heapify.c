#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Heapify(int A[], int n, int i)
{
    int parent = i/2;
    if(A[parent]>0)
    {
        if(A[i]>A[parent])
        {
            swap(&A[i],&A[parent]);
            Heapify(A,n,parent);
        }
    }
}

void NewNode(int A[], int *n, int key)
{
    *n = *n+1;
    A[*n-1] = key;
    int k = *n;
    Heapify(A,k,k-1);
}

int main()
{
    int arr[100] = {10,5,3,1,4,2};
    int n = 6;
    NewNode(arr,&n,15);
    NewNode(arr,&n,20);
    NewNode(arr,&n,8);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}