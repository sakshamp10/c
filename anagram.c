#include <stdio.h>

int main()
{
    char str1[] = "decimal";
    char str2[] = "medical";
    int len1 = sizeof(str1) - 1;
    int len2 = sizeof(str2) - 1;
    int count = 0;
    if(len1==len2)
    {
        for(int i=0;str1[i]!='\0';i++)
        {
            for(int j=0;str2[j]!='\0';j++)
            {
                if(str1[i]==str2[j])
                {
                    count++;
                    break;
                }
            }
        }
    }
    if(count==len1)
    printf("The strings are anagram\n");
    return 0;
}