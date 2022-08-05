#include <stdio.h>

int main()
{
    int arr[100],n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements space seperated: ");
    for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
    int max = arr[0],min = arr[0];
    for(int i=1;i<n;i++)
    {
        if(min>arr[i])
        min = arr[i];
        if(max<arr[i])
        max = arr[i];
    }
    printf("Minimum: %d\n",min);
    printf("Maximum: %d\n",max);
    return 0;
}