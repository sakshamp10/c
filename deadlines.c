#include <stdio.h>
int min(unsigned long long int arr[],int n)
{
    unsigned long long int minimum = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<minimum && arr[i]!=0)
        minimum = arr[i];
    }
    return minimum;
}

static unsigned long long int day = 0;
void days(unsigned long long int arr[],int n)
{
    if(n==0)
    return;
    unsigned long long int x = min(arr,n);
    day+=x;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        arr[i] -= x;
    }
    int i;
    for(i=0;i<n;i++)
    {
        unsigned long long int dumarr[1000] ={0};
        int count = 0;
        while(arr[i]!=0)
        {
            dumarr[count] = arr[i];
            i++;
            count++;
        }
        days(dumarr,count);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    static unsigned long long int a[1000];
    for(int i=0;i<n;i++)
        scanf("%llu",&a[i]);
    days(a,n);
    printf("%llu",day);
    return 0;
}