/**
 * File: cube.c
 *
 * Author:GYJ
 * ID:211250216
 * Date:2021/10/22 21:00
 */
#include<stdio.h>
#include<stdlib.h>
int main() 
{
  long long sum = 0;
  long n = 0;
  scanf("%ld",&n);
  long* arr;
  arr = (long*)malloc(n * sizeof(long));
  for(int i = 0; i< n;i++)
  {
    scanf("%ld",&arr[i]);
  }
  for(int i = 0;i< n;i++)
  {
    sum = sum + arr[i]*(n - i);
  }
  printf("%lld",sum);
  return 0;
}