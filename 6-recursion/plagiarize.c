#include<stdio.h>
#include<stdlib.h>
void find(int p,int* number)
{
    if(number[p-1]==p)
    {
        printf("%d ",p);
    }
    else
    {
        find(number[p-1],number);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int* number;
    number = (int*)malloc(n*sizeof(int));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&number[i]);
    }
    for(int i = 0;i<n;i++)
    {
        if(number[i]==i+1)
        {
            printf("%d ",i+1);
        }
        else
        {
            find(number[i],number);
        }
    }
    return 0;
}