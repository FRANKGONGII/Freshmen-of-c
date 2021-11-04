#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    char* str;
    str = (char*)malloc(n*sizeof(char));
    scanf("%s",str);
    for(int i = 0;i<(n/2);i++)
    {
        if(str[i]=='?')
        {
            str[i] = str[n-1-i];
        }
    }
    for(int i = 0;i<n;i++)
    {
        printf("%c",str[i]);
    }
    return 0;
}