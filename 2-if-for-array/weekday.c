#include<stdio.h>
#include<math.h>
int main(void)
{
    int year = 0;
    int month = 0;
    int day = 0;
    scanf("%d%d%d", &year, &month, &day);
    if (month == 1 || month == 2)
    {
        month  = month + 10;
        year = year - 1;
    }
    else
    {
        month = month - 2;
    }
    double c = year / 100;
    double y = year % 100;
    double w = 0;
    w = day + floor((2.6)*month-(0.2)) + y + floor(y/4) + floor(c/4) - 2*c;
    w = (int)w % 7;
    while (w < 0)
    {
        w = w + 7;
    }
    printf("%d",(int)w);
    return 0;
}