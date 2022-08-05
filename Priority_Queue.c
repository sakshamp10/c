#include<stdio.h>

int pque[10000];
int size=0;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void enque(int val)
{
    if(size==0)
    {
        pque[size++] = val;
        return;
    }
    pque[size++] = val;
    int i = size-1,p;
    while(i>0 && val<pque[(i-1)/2])
    {
        pque[i] = pque[(i-1)/2];
        i = (i-1)/2;
    }
    pque[i] = val;
}

int deque()
{
    int ret = pque[0];
    size--;
    pque[0] = pque[size];
    int i= 0; 
    int j= 2*i + 1;
    while(j<size)
    {
        if(pque[j]>pque[j+1])
            j = j+1;
        if(pque[i]>pque[j])
        {
            swap(&pque[i],&pque[j]);
            i = j;
            j = 2*j+1;
        }
        else
            break;
    }
    return ret;
}

int main()
{
    enque(2);
    enque(2);
    enque(5);
    enque(76);
    enque(100);
    for(int i=0;i<size;i++)
    {
        printf("%d ",pque[i]);
    }
    printf("%d\n",deque());
    return 0;
}