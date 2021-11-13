#include<stdio.h>
#include<stdlib.h>
void Change(int num[], int n,int m)
{
    for(int i = n-m;i<(2.0*n-m-1)/2;i++)
    {
        int tmp = 0;
        tmp = num[i];
        num[i] = num[2*n-m-1-i];
        num[2*n-m-1-i] = tmp;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int* num;
    num = (int*)malloc(n*sizeof(int));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    int m = 1;
    for(int i = n-1;i>=1;i--)
    {
        if(num[i-1]>num[i])
        {
            m++;
        }
        else
        {
            break;
        }
    }
    //计算最长递减后缀
    int tag = n-m;
    int tmp = num[n-m];
    for(int i = n-m;i<n;i++)
    {
        if(num[i]>num[n-m-1]&&num[i]<tmp)
        {
            tmp = num[i];
            tag = i;
        }
    }
    //找到要交换的数
    int tmp2 = 0;
    tmp2 = num[n-m-1];
    num[n-m-1] = num[tag];
    num[tag] = tmp2;
    //交换两个数
    Change(num,n,m);
    //颠倒最后m个数
    for(int i = 0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
}
   