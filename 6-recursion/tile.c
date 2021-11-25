#include<stdio.h>
long long int Fra(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else 
    {
        return Fra(n-1)+Fra(n-2);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    long long num[40] = {0};
    num[0] = 1;
    num[1] = 2;
    for(int i = 2;i<n;i++)
    {
        num[i] = num[i-1] + num[i-2];
    }
    printf("%ld",num[n-1]);
    return 0;
}
