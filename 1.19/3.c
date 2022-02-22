#include<stdio.h>
int main(){
    long  num = 0;
    long  year =  0;
    scanf("%ld%ld",&num,&year);
    long  all = 1;
    long  tmp = year;
    long tmp2 = num;
    num %= 19971107;
    tmp2 %= 19980323;
    while(year!=0){
        all *= num;
        all %= 19971107;
        year--;
    }
    printf("%ld ",all);
    all = 1;
    while(tmp!=0){
        all *= tmp2;
        all %= 19980323;
        tmp--;
    }
    printf("%ld",all);
    return 0;
}