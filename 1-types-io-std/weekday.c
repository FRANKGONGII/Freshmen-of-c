#include <stdio.h>
#include <math.h>

int main()
{
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    if (month == 1 || month == 2)
        year -= 1;
    int c = year / 100;
    int y = year - c * 100;
    int d = day;
    int m = (month < 3) ? month + 10 : month - 2;
    int w = (d + (int)floor(2.6 * (double)m - 0.2) + y + y / 4 + c / 4 - 2 * c) % 7;
    if (w < 0)
        w += 7;
    printf("%d", w);
    return 0;
}
