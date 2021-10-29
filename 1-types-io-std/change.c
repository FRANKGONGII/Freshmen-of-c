#include <stdio.h>
int main(void)
{
  int n;
  scanf("%d", &n);
  printf("%d\n%d\n%d\n%d\n", n / 20, (n % 20) / 10, ((n % 20) % 10) / 5, (((n % 20) % 10) % 5));
  return 0;
}