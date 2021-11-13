#include<stdio.h>
#include<math.h>
int addSum (int i,int t)
{
   double number = 0;
   for(int j = 1;j<=i;j++)
   {
       number += pow(10.0,j-1)*t;
       printf("%lf\n",number);
   }
   return (int)number;
}
int main()
{
    int n,t;
    scanf("%d %d",&n,&t);
    int sum = 0;
    for(int i = 1;i<=n;i++)
    {
        sum += addSum(i,t);
    }
    printf("%d",sum);
    return 0;
}
