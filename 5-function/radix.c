#include<stdio.h>
#include<math.h>
int Trans(int num,int i)
{
    int trans[2] = {0};
    int s = 1;
    int num2 = 0;
    while(num!=0)
    {
        if(s>=0)
        {
            trans[s] = num%10;
            num = num / 10;
            s--;
        }
        else
        {
            break;
        }
    }
    for(int j = 1;j>=0;j--)
    {
        if(trans[j]>=i)
        {
            return -100;
        }
        num2 += pow(i,1-j)*trans[j];
    }
    return (int)num2;
}
int main()
{
    int num1,num2,sum;
    scanf("%d %d %d",&num1,&num2,&sum);
    int target = 0;
    for(int i = 2;i<=40;i++)
    {
        int ret1 = Trans(num1,i);
        int ret2 = Trans(num2,i);
        int sum2 = Trans(sum,i);
        if(ret1>0&&ret2>0&&sum2>0)
        {
            if(ret1 * ret2 == sum2)
            {
                target = i;
                break;
            }
        }
    }
    printf("%d",target);
    return 0;
}