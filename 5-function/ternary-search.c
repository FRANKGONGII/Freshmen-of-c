#include<stdio.h>
#include<math.h>
double getValue(double p,int n,int* number)
{
    double val = 0;
    for(int i = n;i>=0;i--)
    {
        val += number[n-i] * pow(p,i);
    }
    return val;
}
int main()
{
    int n;
    scanf("%d",&n);
    int number[21] = {0};
    for(int i = 0;i<21;i++)
    {
        number[i] = -100;
    }
    for(int i = 0;i<=n;i++)
    {
        scanf("%d",&number[i]);
    }
    double l,r;
    scanf("%lf %lf",&l,&r);
    while(r-l>=10e-8)
    {
        
        double p1 = (r-l)/3 + l;
        double p2 = l + 2*(r-l)/3;
        if(getValue(p1,n,number)>=getValue(p2,n,number))
        {
            r = p2;
        }
        else
        {
            l = p1;
        }
    }
    printf("%lf",l);
    return 0;
}