#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char* str;
    str = (char*)malloc(5000*sizeof(char));
    fgets(str,5000,stdin);
    char* p = str;
    if(*p>=65&&*p<=90)
    {
        printf("%c",*p);
    }
    else if(*p>=97&&*p<=122)
    {
        printf("%c",*p-32);
    }    
    p++;
    for(;;)
    {
        if(*(p-1)==' ')
        {
            if(*p>=65&&*p<=90)
            {
                printf("%c",*p);
            }
            else if(*p == '\0')
            {
                break;
            }
            else
            {
                printf("%c",*p);
            }
            p++;
        }
        else
        {
            if(*p>=65&&*p<=90)
            {
                printf("%c",*p+32);
            }
            else if(*p == '\0')
            {
                break;
            }
            else
            {
                printf("%c",*p);
            }
            p++;
        }
    }
    return 0;
}
