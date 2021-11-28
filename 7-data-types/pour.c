#include<stdio.h>
int Min(int V,int a,int b)
{
    if(V>a+b)
    {
        return a+b;
    }
    else
    {
        return V;
    }
}
int Pour(int Va,int Vb,int Vc,int a,int b,int c,int A,int B,int C,int k)
{
    if(k>0)
    {
        if(a!=A||b!=B||c!=C)
        {
            return 
            Pour(Va,Vb,Vc,0,Min(Vb,a,b),c,A,B,C,k-1)//a to b
            +Pour(Va,Vb,Vc,Min(Va,a,b),0,c,A,B,C,k-1)//b to a
            +Pour(Va,Vb,Vc,0,b,Min(Vc,a,c),A,B,C,k-1)//a to c
            +Pour(Va,Vb,Vc,Min(Va,a,c),b,0,A,B,C,k-1)//c to a
            +Pour(Va,Vb,Vc,a,0,Min(Vc,b,c),A,B,C,k-1)//b to c
            +Pour(Va,Vb,Vc,a,Min(Vb,b,c),0,A,B,C,k-1);//c to b
        }
        else if(a==A&&b==B&&c==C)
        {
            return 1;
        }
    }
    else if(k==0)
    {
        if(a==A&&b==B&&c==C)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    int k,Va,Vb,Vc,a,b,c,A,B,C;
    scanf("%d%d%d%d%d%d%d%d%d%d",&k,&Va,&Vb,&Vc,&a,&b,&c,&A,&B,&C);
    int ret = Pour(Va,Vb,Vc,a,b,c,A,B,C,k);
    if(ret!=0)
    {
        printf("Yes");
    }
    else if(ret==0)
    {
        printf("No");
    }
    return 0;
}