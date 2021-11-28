#include<stdio.h>
#include<stdlib.h>
int findMax(int* num,int i)
{
    int max = num[0];
    for(int j = 0;j<i;j++)
    {
        if(num[j]>max)
        {
            max = num[j];
        }
    }
    return max;
}
int Maxl(int num[2000][2000],int i,int m)
{
    int max = num[i][0];
    for(int j = 0;j<m;j++)
    {
        if(num[i][j]>max)
        {
            max = num[i][j];
        }
    }
    return max;
}
int Maxf(int num[2000][2000],int i,int n)
{
    int max = num[0][i];
    for(int j = 0;j<n;j++)
    {
        if(num[j][i]>max)
        {
            max = num[j][i];
        }
    }
    return max;
}
void Left(int num[2000][2000],int n,int m)
{
    int* left;
    left = (int*)malloc(n*sizeof(int));
    for(int i = 0;i<n;i++)
    {
        left[i] = Maxl(num,i,m);
    }
    int max = findMax(left,n);
    for(int i = 0;i<max;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(left[j]==max-i)
            {
                printf("*");
                left[j]--;
            }
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void Front(int num[2000][2000],int n,int m)
{
    int* front;
    front = (int*)malloc(m*sizeof(int));
    for(int i = 0;i<m;i++)
    {
        front[i] = Maxf(num,i,n);
    }
    int max = findMax(front,m);
    for(int i = 0;i<max;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(front[j]==max-i)
            {
                printf("*");
                front[j]--;
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int num[2000][2000];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    Front(num,n,m);
    printf("\n");
    Left(num,n,m);
    return 0;
}