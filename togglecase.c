#include <stdio.h>

int main()
{
    char A[] = "wElCOme";
    int i;
    for(i=0;A[i]!='\0';i++)
    {
        if(A[i]>=65 && A[i]<=90)
        A[i] += 32;
        else if(A[i]>='a' && A[i]<=122)
        A[i] -= 32;
    }
    printf("%s\n",A);
    return 0;
}