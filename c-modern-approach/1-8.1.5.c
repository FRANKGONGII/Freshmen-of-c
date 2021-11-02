#include<stdio.h>
//to output a fibonacci sequence
int main()
{
    int num1 = 0;
    int num2 = 0;
    int i = 0;
    int fib_num[40] = {0};
    scanf("%d%d",&num1,&num2);
    fib_num[0] = num1;
    fib_num[1] = num2;
    
    for(i = 2;i<40;i++)
    {
        fib_num[i]= fib_num[i-1] + fib_num[i-2];
    }
    for(int j = 0;j<40;j++)
    {
        printf("%d ",fib_num[j]);
    }
    return 0;
}