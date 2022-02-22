#include<stdio.h>
#include<string.h>
int main()
{
    char str[200];
    scanf("%[^\n]",str);
    int len = strlen(str);
    int tag = 1;
    for(int i = 0;i<len;i++)
    {
        if(str[i]==str[len-i-1])
        {
            ;
        }
        else if(str[i]!=str[len-1-i])
        {
            tag = 0;
            break;
        }
    }
    if(tag == 1)
    {
        for(int i = 0;i<=(len-1)/2;i++)
        {
            printf("%c",str[i]);
        }
    }
    else
    {
        for(int i = 0;i<len;i++)
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}