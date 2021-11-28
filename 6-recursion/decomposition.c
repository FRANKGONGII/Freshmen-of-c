#include<stdio.h>
#include<stdlib.h>
void Print(int count,int* dec)
{
    for(int i = 0;i<=count;i++)
    {
        printf("%d ",dec[i]);
    }
    printf("\n");
}
void Sep(int n,int i,int* dec,int count,int time)
{
    int j;
    if(n==1)
    {
        count++;
        dec[count] = n;
        Print(count,dec);
        return;
    }
    if(n>=i&&n<2*i&&(n!=2||i!=1))
    {
        count++;
        dec[count] = n;
        Print(count,dec);
        return;
    }
    if(n>1)
    {
        for(j = 1;j<=(n/2);j++)
        {
            if(j>=i)
            {
                if(time!=0)
                {
                    count--;
                }
                //一时奇妙的想法，主要是为了解决4的分解又把count加了一次的问题，这是一个计数器，用了衡量第几次来到这一步，如果不是第一次（刚刚已经分解了一次，而且count现在已经是加一状态），那么就要把count--，保证新的数在正确的位子上。
                count++;
                dec[count] = j;
                time++;
                Sep(n-j,j,dec,count,0);
            }
        }
        if(j>(n/2))
        {
            if(j>=i)
            {
                dec[count] = n;
                Print(count,dec);
                return;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int* dec;
    dec = (int*)malloc(n*sizeof(int));
    int i;
    int count = 0;
    int time = 0;
    for(i = 1;i<=(n/2);i++)
    {
        dec[count] = i;
        Sep(n-i,i,dec,count,time);
    }
    if(i>(n/2))
    {
        printf("%d",n);
    }
    return 0;
}