#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n = 0;
    int k = 0;
    int start = 0;
    scanf("%d %d\n",&n,&k);
    int* arr;
    int* index;
    arr = (int*)malloc(n*sizeof(int));
    index = (int*)malloc(n*sizeof(int));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    k = k % n;
    for(int i = 0;i<n;i++)
    {
        index[i] = i+k;
    }
    for(int i = 0;i<n;i++)
    {
        if(index[i]>n-1)
        {
            start = i;
            break;
        }
    }
    for(int j = start;j<n;j++)
    {
        printf("%d ",arr[j]);
    }
    for(int j = 0;j<start;j++)
    {
        printf("%d ",arr[j]);
    }
    return 0;
}