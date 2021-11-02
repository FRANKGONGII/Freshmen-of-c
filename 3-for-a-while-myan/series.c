#include<stdio.h>
#include<math.h>
int main()
{
    double n , x;
    double sum = 0;
    scanf("%lf%lf",&n,&x);
    for(int i = 0;i<=n;i++)
    {
        double sum1 = 1;
        if(i == 0)
        {
            sum = 1;
        }
        else if(i>=1)
        {
            for(int j = 1;j<=i;j++)
            {
                sum1 = j * sum1;//calculate i!
            }
            double sum2 = 1;
            sum2 = pow(x,i);//calculate x^i
            sum = sum + sum2/sum1;
        }
        
    }
    printf("%.3lf",sum);
    return 0;
}