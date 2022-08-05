#include <stdio.h>

int main()
{
    int arr[100],n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements space seperated: ");
    for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
    int flag = 1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1])
        flag = -1;
    }
    if(flag==1)
    printf("The array is sorted\n");
    else
    printf("The array is unsorted\n");
    return 0;
}