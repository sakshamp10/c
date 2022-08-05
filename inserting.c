#include <stdio.h>

int main()
{
    int arr[100],n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements space seperated: ");
    for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
    int value,pos;
    printf("Enter value and position to insert it on: ");
    scanf("%d",&value);
    scanf("%d",&pos);
    for(int i=n;i>pos-1;i--)
    arr[i] = arr[i-1];
    arr[pos-1] = value;
    printf("New array is: ");
    for(int i=0; i<n+1;i++)
    printf("%d ",arr[i]);
    printf("\n");
    return 0;
}