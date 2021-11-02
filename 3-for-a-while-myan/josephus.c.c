#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n , k;
    scanf("%d %d",&n,&k);
    int* arr;
    arr = (int*)malloc(n*sizeof(int));
    int alive = n;
    int count = 0;
    int win = 0;
    for(int i = 0;i<n;i++)
    {
        arr[i] = 1;//alive
    }
    int j = 0;
    while(alive>1)
    {
        for(j = 0;j<n;j++)
        {
            if(arr[j]==1)//alived man can die
            {
                count++;
                if(count==k)
                {
                    arr[j] = 0;//dead
                    count=0;
                    alive--;
                    printf("%d ",j+1);
                    if(alive==1)
                    {
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        if(arr[i]==1)
        {
            win = i;
        }
    }
    printf("%d",win+1);
    return 0;
}