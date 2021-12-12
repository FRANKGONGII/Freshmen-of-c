#include<stdio.h>
#include<string.h>
char Div(char* num1,char* num2,int i,int len1,int len2)
{
    if(num1[i]=='1')
    {
        for(int j = i+1;j<=i+len2-1;j++)
        {
            if(num1[j] == num2[j-i])
            {
                num1[j] = '0';
            }
            else
            {
                num1[j] = '1';
            }
        }
        return '1';
    }
    else
    {
        for(int j = i+1;j<=i+len2-1;j++)
        {
            if(num1[j]=='0')
            {
                num1[j] = '0';
            }
            else if(num1[j] == '1')
            {
                num1[j] = '1';
            }
        }
        return '0';
    }
}
int main()
{
    char num1[100];
    char num2[100];
    char num3[200];
    char res[100];
    char res2[100];
    scanf("%s%s",num1,num2);
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    for(int i = len1;i<=len1+len2-2;i++)
    {
        num1[i] = '0';
    }
    for(int i = 0;i<len1;i++)
    {
        num3[i] = num1[i];
    }
    for(int i = 0;i<=len1-1;i++)
    {
       res[i] = Div(num1,num2,i,len1,len2);
    }
    for(int i = len1;i<=len1+len2-2;i++)
    {
        num3[i] = num1[i];
    }
    for(int i = 0;i<=len1+len2-2;i++)
    {
        printf("%c",num3[i]);
    }
    for(int i =0;i<=len1+len2-2;i++)
    {
        res2[i] = Div(num3,num2,i,len1,len2);
    }
    printf("\n");
    for(int i = len1;i<=len1+len2-2;i++)
    {
        printf("%c",num3[i]);
    }
    return 0;
}