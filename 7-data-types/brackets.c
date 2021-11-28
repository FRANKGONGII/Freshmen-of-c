#include<stdio.h>
#include<string.h>
void Check(int len,char* str)
{
    int tag[200000] = {0};
    int index = 0;
    int i;
    for(i = 0;i<len;i++)
    {
        if(str[i]=='(')
        {
            tag[index] = 1;
            index++;
        }
        else if(str[i]=='[')
        {
            tag[index] = 2;
            index++;
        }
        else if(str[i]=='{')
        {
            tag[index] = 3;
            index++;
        }
        else if(str[i]==')')
        {
            if(tag[index]==1)
            {
                index--;
            }
            else
            {
                printf("False");
                return;
            }
        }
        else if(str[i]==']')
        {
            if(tag[index]==2)
            {
                index--;
            }
            else
            {
                printf("False");
                return;
            }
        }
        else if(str[i]=='}')
        {
            if(tag[index]==3)
            {
                index--;
            }
            else
            {
                printf("False");
                return;
            }
        }
    }
    if(i==len)
    {
        printf("True");
        return;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    char str[200000];
    for(int i = 0;i<n;i++)
    {
        scanf("%s",str);
        int len = strlen(str);
        Check(len,str);
    }
    return 0;
}