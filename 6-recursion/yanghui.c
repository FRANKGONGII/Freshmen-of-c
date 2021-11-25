#include<stdio.h>
long int Cal(int a,int b)
{
    if(a-1==0||b-1==0)
    {
        return 1;
    }
    else 
    {
        return (Cal(a-1,b)+Cal(a-1,b-1));
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a-1==0||b-1==0)
    {
        printf("1");
    }
    else
    {
        printf("%ld",Cal(a,b));
    }
    return 0;
}