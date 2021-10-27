#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n = 0;
    scanf("%d",&n);
    int* arr;
    int min = 1;
    arr = (int*)malloc(n*sizeof(int));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(arr[0]!=1)
    {
        printf("%d",min);
        goto end;
    }
    int test = 1;
    for(int j = 2;j<arr[n-1];j++)
    {
        for(int i = 0;i<n;i++)
        {
            if(arr[i]<j&&arr[i+1]>j)
            {
                printf("%d",j);
                test = 0;
                goto end;
            }
        }
    }
    if(test ==1)
    {
        printf("%d",arr[n-1]+1);
    }
    end:
    return 0;
}