/**
 * File: calculator.c
 *
 * Author:GYJ
 * ID:211250216
 * Date:2021/10/22
 */
#include<stdio.h>
#include<math.h>
int main()
{
    int a = 0;
    int b = 0;
    char op1 = 0;
    char op2 = 0;
    int test = 0;
    while ((scanf("%d",&a))!= EOF)
    {
        scanf(" %c%c%d",&op1, &op2, &b);
        if (op1 == '+' && op2 == ' ')
        {
            printf("%d", a + b);
        }
        else if (op1 == '-' && op2 == ' ')
        {
            printf("%d", a - b);
        }
        else if (op1 == '*' && op2 == ' ')
        {
            printf("%d", a * b);
        }
        else if (op1 == '*' && op2 == '*')
        {
            printf("%lf", pow((float)a, (float)b));
        }
        else if (op1 == '/' && op2 == ' ')
        {
            printf("%d", a / b);
        }
        else if (op1 == '/' && op2 == '*')
        {
            printf("%.3f", (double)a / (double)b);
        }
        else if (op1 == '%' && op2 == ' ')
        {
            printf("%d", a % b);
        }
    }
    return 0;
}