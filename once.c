/**
 * File: once.c
 *
 * Author:GYJ
 * ID:211250216
 * Date:2021/10/22
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int* arr;
    int* arrcopy;
    arr = (int*)malloc((2 * n - 1) * sizeof(int));
    arrcopy = (int*)malloc((2 * n) * sizeof(int));
    for (int i = 0; i < 2 * n - 1;i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0;i < 2 * n;i++)
    {
        arrcopy[i] = 0;
    }
    for (int i = 0; i < 2 * n - 1; i++)
    {
        arrcopy[arr[i]]++;
    }
    for (int i = 0;i < 2 * n - 1;i++)
    {
        if (arrcopy[arr[i]] == 1)
        {
            printf("%d", arr[i]);
            break;
        }
    }
    return 0;
}