#include<stdio.h>
#include<math.h>
int main(void)
{
    int n = 0;
    scanf("%d",&n);
    int count = 0;
    for(int i = 1;i <= n;i + 2)
    {
        int j = 2;
        for(j = 2;j <=(int)sqrt(i); j++)
        {
            if(i==1)
            {
                break;
            }
            if(i%j == 0)
            {
                break;
            }  
        }
        if(i == j)
        {
            count++;
        }
    }
    printf("%d",count);
}