#include<stdio.h>
int main()
{
    float num;
    scanf("%x",&num);
    printf("%d\n",*(int*)&num);
    printf("%lu\n",*(unsigned int*)&num);
    printf("%.6f",num);
    return 0;
}