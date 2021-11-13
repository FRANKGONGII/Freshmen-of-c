#include<stdio.h>
#include<math.h>
int primeJudge(int i)
{
    int flag = 1;
        for(int j = 2;j<=sqrt(i+0.5);j++)
        {
            if(i%j==0)
            {
                flag = 0;
            }
        }
    return flag;    
}
int main()
{
    int n;
    scanf("%d",&n);
    int primenum[4] = {0};
    int count = 0;
    for(int i = 2;i <= n;i++)
    {
        if(primeJudge(i))
        {
            int num1 = i;
            int p = 3;
            while(num1!=0)
            {
                primenum[p] = (num1)%10;
                num1 /= 10;
                p--;
            }
            int num2 = 0;
            for(int i = 3;i>=0;i--)
            {
                num2 += (pow(10.0,2-p+(i-3))*primenum[i]);
            }
            if(primeJudge(num2))
            {
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}