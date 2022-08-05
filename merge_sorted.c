#include <stdio.h>

int main()
{
    int arr1[100],arr2[100],mer[100],n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array 1 elements space seperated: ");
    for (int i = 0; i < n; ++i)
    scanf("%d", &arr1[i]);
    printf("Enter array 2 elements space seperated: ");
    for (int i = 0; i < n; ++i)
    scanf("%d", &arr2[i]);
    int i=0,j=0,k=0;
    while(k<(2*n))
    {
        if(i==n)
        mer[k++] = arr2[j++];
        else if (j==n)
        mer[k++] = arr1[i++];
        else if(arr1[i]>arr2[j])
        mer[k++] = arr2[j++];
        else if(arr1[i]<=arr2[j])
        mer[k++] = arr1[i++];
    }
    printf("The merged and sorted list is: ");
    for(int h=0;h<(2*n);h++)
    printf("%d ",mer[h]);
    printf("\n");
    return 0;
}