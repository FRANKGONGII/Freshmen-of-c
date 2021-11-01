#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n = 0;
    int target = 0;
    scanf("%d %d\n",&n,&target);
    int* arrsou;
    arrsou = (int*)malloc(n*sizeof(int));
    int x = 0;
    int y = 0;
    for(int i = 0;i<n;i++)
    {
       scanf("%d",&arrsou[i]);
    }
    //initialize the len , target and the x,y that stores the numbers we want,get the numbers of arraysource and store.
    for(int i = 0;i<n-1;i++)
    {
        for(int j = n-1;j>0;j--)
        {
            if(arrsou[i]+arrsou[j]==target)
            {
                x = arrsou[i];
                y = arrsou[j];
            }
        }
    }
    printf("%d %d",x,y);
    return 0;
}