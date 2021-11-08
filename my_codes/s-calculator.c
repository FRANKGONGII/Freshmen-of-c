//a super calculator that can calculate the sum of two very big numbers

#include<stdio.h>
#include<string.h>
int Min(int len1,int len2)
{
    if(len1>len2)
    {
        return len2;
    }
    else 
    {
        return len1;
    }
}
int Max(int len1,int len2)
{
    if(len1>len2)
    {
        return len1;
    }
    else
    {
        return len2;
    }
}
void Align(char num1[],char num2[],int len1,int len2)
{
    if(len1 > len2)
    {
        for(int i = len2-1;i>=0;i--)
        {
            num2[i + len1 -len2] = num2[i];
        }
        for(int i = 0;i<len1-len2;i++)
        {
            num2[i] = '0';
        }
    }
    else if(len2 > len1)
    {
        for(int i =len1-1;i>=0;i--)
        {
            num1[i + len2-len1] = num1[i];
        }
        for(int i = 0;i<len2-len1;i++)
        {
            num1[i] = '0';
        }
    }
    else
    {
        ;
    }
}
void Backspace(char num1[],char num2[],int len1,int len2)
{
    for(int i = Max(len1,len2);i>=0;i--)
    {
        num1[i+1] = num1[i];
        num2[i+1] = num2[i];
    }  
    num1[0] = num2[0] = '0';
}
void Add(char num1[],char num2[],char sum[],int len1,int len2)
{
    int up_digi = 0;
    for(int i = Max(len1,len2);i>=0;i--)
    {
       char num1_digi = num1[i];
       char num2_digi = num2[i];
       char sum_digi = num1_digi + num2_digi + up_digi;
       if(up_digi==1)
       {
           up_digi = 0;
       }
       if(sum_digi > 105)
       {
        up_digi = 1;
        sum_digi -= 58;
        sum[i] = sum_digi;
       }
       else if(sum_digi<=105)
       {
        sum[i] = sum_digi - 48;
       }
    }
}
int main()
{
    char num1[10000];
    char num2[10000];
    char sum[10000];
    while(scanf("%s %s",&num1,&num2)!=EOF)
    {
        int len1 = strlen(num1);
        int len2 = strlen(num2);
        Align(num1,num2,len1,len2);
        Backspace(num1,num2,len1,len2);
        Add(num1,num2,sum,len1,len2);
        if(sum[0]!='0')
        {
            printf("%c",sum[0]);
        }
        for(int i = 1;i<Max(len1,len2)+1;i++)
        {
            printf("%c",sum[i]);
        }
        printf("\n");
    }
    return 0;
}