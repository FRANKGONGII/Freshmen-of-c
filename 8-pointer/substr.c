#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char* str_big;
    str_big = (char*)malloc(100000*sizeof(char));
    char* str_small;
    str_small = (char*)malloc(100000*sizeof(char));
    scanf("%s%s",str_big,str_small);
    int len1 = strlen(str_big);
    int len2 = strlen(str_small);
    for(int i = 0;i<len1;i++)
    {
        if(*(str_big+i)==*str_small)
        {
            int tag = 0;
            for(int j = 0;j<len2;j++)
            {
                if(*(str_big+i+j)==*(str_small+j))
                {
                    ;
                }
                else
                {
                    tag = 1;
                    break;
                }
            }
            if(tag == 0)
            {
                printf("%d ",i);
            }
        }
    }
    return 0;
}