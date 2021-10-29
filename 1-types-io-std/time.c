#include <stdio.h>
char month[10], weekday[10];
int day, year, hour, min, second;
int main(void)
{
  scanf("%s%d%d%s%d%d%d", month, &day, &year, weekday, &hour, &min, &second);
  printf("%.3s %.3s %02d %02d:%02d:%02d %04d\n", weekday, month, day, hour, min, second, year);
  return 0;
}