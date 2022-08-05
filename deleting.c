#include <stdio.h>

int main()
{
    int arr[100],n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements space seperated: ");
    for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
    int pos;
    printf("Enter the index of element to be deleted: ");
    scanf("%d",&pos);
    n--;
    for(int i=pos-1;i<n;i++)
    arr[i] = arr[i+1];
    printf("New array is: ");
    for(int i=0; i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
    return 0;
}    