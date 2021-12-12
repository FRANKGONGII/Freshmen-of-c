#include<stdio.h>
#include<string.h>
#include<math.h>
void Print(int i,char* ipv6)
{
    if(ipv6[4*i]=='0')
    {
        if(ipv6[4*i+1]=='0')
        {
            if(ipv6[4*i+2]=='0')
            {
                printf("%c",ipv6[4*i+3]);
            }
            else
            {
                for(int j = 4*i+2;j<=4*i+3;j++)
                {
                    printf("%c",ipv6[j]);
                }
            }
        }
        else 
        { 
            for(int j = 4*i+1;j<=4*i+3;j++)
            {
                printf("%c",ipv6[j]);
            }
        }
    }
    else
    {
        for(int j = 4*i;j<=4*i+3;j++)
        {
            printf("%c",ipv6[j]);
        }
    }
}
int main()
{
    char ipv6[50];
    char nums[129];
    scanf("%s",nums);
    for(int i = 0;i<32;i++)
    {
        int num = (nums[4*i]-48)*8+(nums[4*i+1]-48)*4+(nums[4*i+2]-48)*2+(nums[4*i+3]-48);
        if(num>=0&&num<=9)
        {
            ipv6[i] = num+48;//we can store int in a char array, but can not printf it with %c, so we need to change the int
        }
        else if(num>9)
        {
            ipv6[i] = num+87;
        }
    }
    int tag[8] = {0};
    for(int i = 0;i<8;i++)
    {
        if(ipv6[4*i]=='0'&&ipv6[4*i+1]=='0'&&ipv6[4*i+2]=='0'&&ipv6[4*i+3]=='0')
        {
            tag[i] = 1;
        }
    }
    int len  = 0;
    int lenmax = 0;
    int index = 0;
    for(int i = 0;i<8;i++)
    {
        if(tag[i] == 1)
        {
            len++;
            {
                if(len>lenmax)
                {
                    lenmax = len;
                    index = i;
                }
            }
        }
        else if(tag[i]==0)
        {
            len = 0;
        }
    }
    //找到有多少连着的0000可以一起省略
    for(int i = 0;i<8;i++)
    {
        if(i>=index-lenmax+1&&i<=index)
        {
            if(i==index-lenmax+1)
            {
                printf(":");
            }
        }
        else 
        {
            Print(i,ipv6);
            if(i!=7)
            {
                printf(":");
            }
        }
    }
    return 0;
}