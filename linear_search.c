#include <stdio.h>

int linear_search(int a[],int n, int value)
{
    for(int i=0;i<n;i++)
    {
        if(value == a[i])
        return i+1;
    }
    return -1;
}

int main()
{
    int arr[100],n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements space seperated: ");
    for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
    int val;
    printf("Enter the value to be searched: ");
    scanf("%d",&val);
    int res = linear_search(arr,n,val);
    if(res != -1)
    printf("The value %d is at %dth position\n",val,res);
    else
    printf("The value is not in given array\n");
    return 0;
}    