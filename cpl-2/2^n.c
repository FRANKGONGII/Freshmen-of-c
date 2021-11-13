#include<stdio.h>
void plusNum(int number[35000],int i)
{
    int up_digi = 0;
    for(int i = 34999;i>=0;i--)
    {
        int sum = 0;
        sum = number[i] * 2 + up_digi;
        up_digi = sum / 10;
        number[i] = sum % 10;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int number[35000] = {0};
    number[34999] = 1;
    for(int i = 1;i<=n;i++)
    {
        plusNum(number,i);
    }
    int count = 0;
    for(int i = 0;i<35000;i++)
    {
        if(number[i]!=0)
        {
            count = i;
            break;
        }
    }
    for(int i = count;i<35000;i++)
    {
        printf("%d",number[i]);
    }
    return 0;
}