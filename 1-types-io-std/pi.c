#include <stdio.h>
#include <math.h>
int main(void)
{
  double pi_1 = 16 * atan(0.2) - 4 * atan(1.0 / 239);
  double pi_2 = log(1.0 * 640320 * 640320 * 640320 + 744) / sqrt(163);
  printf("%.15lf\n%.15lf\n", pi_1, pi_2);
  return 0;
}
