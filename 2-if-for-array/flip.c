/**
 * File: flip.c
 *
 * Author:GYJ
 * ID:211250216
 * Date:2021/10/24
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  int n = 0;
  scanf("%d",&n);
  int* arr;
  arr = (int*)malloc(n*sizeof(int));
  for (int j = 0;j <= n - 1;j++)
  {
      arr[j] = 1;
  }
  for(int i = 2;i<=n;i+=2)
  {
    for(int j = 1;j<=n;j+=2)
    {
      if((j+1)%i==0)
      {
        arr[j] = 1- arr[j];
      }
    }
  }
  for(int i = 3;i<=n;i+=2)
  {
    for(int j = 2 ; j<=n;j++)
    {
      if((j+1)%i==0)
      {
        arr[j] = 1- arr[j];
      }
    }
  }
  for(int j = 0;j<=n-1;j++)
  {
    if(arr[j]==1)
    {
      printf("%d ",j+1);
    }
  }
  return 0;
}