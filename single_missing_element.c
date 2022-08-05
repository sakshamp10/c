#include <stdio.h>

int main()
{
    int arr[100],n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter array elements space seperated: ");
    for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
    int d;
    int x = arr[1] - arr[0];
    int y = arr[2] - arr[1];  
    int z = arr[3] - arr[2];
    if(x==y)
    d = x;
    else if(y==z)
    d = y;
    else if(x==z)
    d = z;
    for(int i =0;i<n-1;i++)
    {
        if(arr[i+1]-arr[i] == 2*d)
        {
            printf("The missing element is : %d\n",arr[i]+d);
            return 0;
        }
        
    }
    return 0;
}