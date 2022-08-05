#include <stdio.h>

int checkin(int a[],int n,int val)
{
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        if(a[i]==val)
        count ++;
    }
    return count;
}

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
    int uni[100];
    int ind = 0;
    for(int i=0;i<2*n;i++)
    {
        int x = checkin(mer,2*n,mer[i]);
        if(x==1)
        {
            uni[ind] = mer[i];
            ind++;
        }
        else
        {
            int y = checkin(uni,ind+1,mer[i]);
            if(y==0)
            {
                uni[ind] = mer[i];
                ind++;
            }
        }
    }
    printf("The union list is: ");
    for(int h=0;h<ind;h++)
    printf("%d ",uni[h]);
    printf("\n");
    return 0;
}