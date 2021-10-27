#include<stdio.h>
#include<math.h>
int main()
{
    int n = 0;
    unsigned int m = 0;
    scanf("%d",&n);
    if(n>0)
    {
        for(int i = 31;i>=0;i--)
        {
            if(((n>>i)&1)==1)
            {
                printf("1");
            }
            else if(((n>>i)&1)==0)
            {
                printf("0");
            }
            
        }
    }
    else if(n ==0)
    {
        for(int i = 31;i>=0;i--)
        {
            printf("0");
        }
    }
    else if(n<0)
    {
        m = n;
        for(int i = 31;i>=0;i--)
        {
            if(((m>>i)&1)==1)
            {
                printf("1");
            }
            else if(((m>>i)&1)==0)
            {
                printf("0");
            }
        }
    }
    return 0;
}