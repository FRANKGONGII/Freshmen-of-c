#include <stdio.h>
#include <math.h>

int main()
{
  double a, b, c;
  double x1, x2;
  scanf("%lf %lf %lf", &a, &b, &c);
  x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
  x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
  printf("%.3f %.3f", x1, x2);

  return 0;
}