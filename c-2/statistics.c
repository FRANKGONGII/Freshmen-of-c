/**
 * File: statistics.c
 *
 * Author:GYJ
 * ID:211250216
 * Date:2021/10/24
 */
#include<stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    char* arr;
    arr = (char*)malloc(n * sizeof(char));
    int arrcount[26] = { 0 };
    scanf("%s", arr);
    for (int i = 0;i <= n - 1;i++)
    {
        for (int j = 97;j <= 122;j++)
        {
            if (arr[i] == j)
            {
                arrcount[j - 97]++;
            }
        }
    }
    int max = 0;
    max = arrcount[0];
    for (int j = 0;j <= 25;j++)
    {
        if (arrcount[j] >= max)
        {
            max = arrcount[j];
        }
    }
    for (int i = 1;i <= max;i++)
    {
        for (int j = 0;j <= 25;j++)
        {
            if (i - max + arrcount[j] > 0)
            {
                printf(" = ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }

    for (int i = 97;i <= 122;i++)
    {
        printf("---");
    }
    printf("\n");
    for (int i = 97;i <= 122;i++)
    {
        printf(" %c ", i);
    }
    return 0;
}