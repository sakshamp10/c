#include <stdio.h>

int main()
{
    int arr[100],n,k;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements space seperated: ");
    for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
    printf("Enter sum of pair: ");
    scanf("%d",&k);
    int count;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j] == k)
            {
                count++;
                printf("Pair %d: %d and %d\n",count,arr[i],arr[j]);
            }
        }
    }
}