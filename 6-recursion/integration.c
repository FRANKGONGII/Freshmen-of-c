#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double Fx(double x,int p,int n,int*num)
{
    double sum = 0;
    for(int i = 0;i<=n;i++)
    {
        sum+=num[i]*pow(x,i);
    }
    return pow(sum,p);
}
double Cal(double a,double b,int n,int p,int* num)
{
    return ((b-a)*(4*Fx((a+b)/2,p,n,num)+Fx(a,p,n,num)+Fx(b,p,n,num)))/6;
}
double Com(double a,double b,int n,int p,int* num)
{
    double sum1 = Cal(a,b,n,p,num);
    double sum2 = Cal(a,(a+b)/2,n,p,num);
    double sum3 = Cal((a+b)/2,b,n,p,num);
    if(fabs(sum2+sum3-sum1)>=1.5e-5)
    {
        return Com(a,(a+b)/2,n,p,num)+Com((a+b)/2,b,n,p,num);
    }
    return(sum2+sum3)+((sum2+sum3-sum1)/15);
}

int main()
{
    int n,p;
    double a,b;
    double sum1 =0;
    double sum2 =0;
    double sum3 =0;
    scanf("%d%d",&n,&p);
    int*num;
    num = (int*)malloc((n+1)*sizeof(int));
    for(int i = 0;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    scanf("%lf%lf",&a,&b);
    printf("%lf",Com(a,b,n,p,num));
}