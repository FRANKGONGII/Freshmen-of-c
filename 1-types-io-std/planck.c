#include <stdio.h>
const double h = 6.626e-34;
int main()
{
    double v;
    scanf("%lf", &v);
    printf("%.2e\n", h * v);
    return 0;
}
