#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    printf("%d\n", num);
    if (65 <= num && num <= 90)
    {
        printf("%c\n", num + 32);
        printf("%c\n", num);
    }
    else
    {
        printf("%c\n", num);
        printf("%c\n", num - 32);
    }
    return 0;
}
