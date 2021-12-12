#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void mystract(char* str1,char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i = 0;i<len1;i++)
    {
        if(*(str1+i)==*str2)
        {
            int tag = 0;
            for(int j = 1;j<len1-i;j++)
            {
                if(*(str1+i+j)==*(str2+j))
                {
                    continue;
                }
                else
                {
                    tag = 1;
                    break;
                }
            }
            if(tag == 0)
            {
                
                for(int s = 0;s<i;s++)
                {
                    printf("%c",*(str1+s));
                }
                for(int k = 0;k<len2;k++)
                {
                    printf("%c",*(str2+k));
                }
                printf("\n");
                return;
            }
        }
    }
}
int main()
{
    int time;
    scanf("%d",&time);
    for(int i = 0;i<time;i++)
    {
        char* str1;
        str1 = (char*)malloc(2000*sizeof(char));
        char* str2;
        str2 = (char*)malloc(2000*sizeof(char));
        scanf("%s%s",str1,str2);
        mystract(str1,str2);
    }
    return 0;
}