/**
 * File: money.c
 *
 * Author:GYJ
 * ID:211250216
 * Date:2021/10/22
 */
#include<stdio.h>
int main()
{
  int n = 0;
  int m = 0;
  long sum = 0;
  long sum1 = 0;
  long sum2 = 0;
  scanf("%d",&n);
  for(int i = 0;i < n;i++)
  {
    scanf("%d%ld",&m,&sum);
    if(m == 1)
    {
      sum1 += sum;
    }
    else if(m == 2)
    {
      sum2 += sum;
    }
  }
  printf("%ld",sum2 - sum1);
  return 0;
}