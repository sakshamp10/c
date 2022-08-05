#include<stdio.h>

int bser(int a[],int beg,int end,int val)
{
    int mid;
    if(end>beg)
    {
        mid = (end+beg)/2;
        if(a[mid]==val)
        return mid;
        else if(val>a[mid])
        return bser(a,mid+1,end,val);
        else if(val<a[mid])
        return bser(a,beg,mid-1,val);
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
    int res = bser(arr,0,n-1,val);
    if(res != -1)
    printf("The value %d is at %dth position\n",val,res+1);
    else
    printf("The value is not in given array\n");
    return 0;
}