#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int Max(int* arr,int start,int end)
{
    int max = arr[start];
    for(int i = start+1;i<=end;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    int i = 0;
    int arr[100];
    int max = 0;
    while(scanf("%d",&arr[i])!=EOF)
    {
        i++;
    }
    if(i == 2)
    {
        printf("%d",abs(arr[0]-arr[1]));
    }
    if(i>2)
    {
        for(int j = 0;j<i-1;j++)
        {
            if((abs(Max(arr,0,j)-Max(arr,j+1,i-1)))>max)
            {
                max = abs(Max(arr,0,j)-Max(arr,j+1,i-1));
            }
        }
        printf("%d",max);
    }
    return 0;
}