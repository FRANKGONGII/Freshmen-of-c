#include <stdio.h>
int main(void)
{
  int n, num[4] = {0};
  scanf("%d", &n);
  int p = 3;
  while (n)
  {
    num[p--] = n & 0x1;
    n >>= 1;
  }
  for (int i = 4; i; i--)
    num[i] ^= num[i - 1];
  for (int i = 0; i < 4; i++)
    printf("%d", num[i]);
  printf("\n");
  return 0;
}
