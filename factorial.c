/**
 * File: factorial.c
 *
 * Author:
 * ID:
 * Date:
 */
#include<stdio.h>
int main()
{
    long long n = 0;
    long long sum = 0;
    scanf("%lld", &n);
    long long arr[1000];
    /*long* arr;
    arr = (long*)malloc(n*sizeof(long));*/
    for (int i = 0;i < n;i++)
    {
        arr[i] = 1;
    }
    for (long long j = 0;j < n;j++)
    {
        for (long long i = 1;i <= j + 1;i++)
        {
            arr[j] = arr[j] * i;
        }
        arr[j] = arr[j] % 10007;
    }
    for (int j = 0;j < n;j++)
    {
        sum = sum + arr[j];
    }
    printf("%lld", sum % 10007);
    return 0;
}