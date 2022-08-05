#include <stdio.h>

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int arr[100],n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements space seperated: ");
    for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
    for(int i=n-1,j=0;j<i;i--,j++)
    swap(&arr[j],&arr[i]);
    printf("Reversed array is: ");
    for(int i=0; i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
    return 0;
}