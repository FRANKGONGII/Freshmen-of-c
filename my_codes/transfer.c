#include<stdio.h>
void change(int input)
{ 
    for(int i = 31;i>=0;i--)
    {
        if (((input>>i)&1)==1)
        {
           printf("1");
        }
        else if (((input>>i)&1) == 0)
        {
           printf("0");
        }
    }
}
int main(void)
{
    int input = 0;
    scanf_s("%d", &input);
    change(input);
    return 0;
}