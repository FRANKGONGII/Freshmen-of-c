#include<stdio.h>
#include<stdlib.h>
int test(int* ant,int i)
{
    if(ant[i-1]>=0)
    {
        if(ant[i-1]>abs(ant[i]))
        {
            ant[i] = ant[i-1];
            ant[i-1] = 0;
        }
        else if(ant[i-1]<abs(ant[i]))
        {
            ant[i-1] = ant[i];
            ant[i] = 0;
        }
        else
        {
            ant[i] = ant[i-1] = 0;
        }
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int* ant;
    ant = (int*)malloc(n*sizeof(int));
    for(int i = 0;i<n ;i++)
    {
        scanf("%d",&ant[i]);
    }
    int war  = 1;
    while(war!= 0)
    {
        war = 0;
        for(int i = 0;i<n;i++)
        {
            if(ant[i]<0 && i!=0)
            {
                war += test(ant,i);
            }
        }
    }
    if(ant[0]!=0)
    {
        printf("%d ",ant[0]);
    }
    int count = 0;
    int incount = 0;
    for(int i = 1;i<n;i++)
    {
        if(ant[i]!=0)
        {
           count++;
        }
    }
    for(int i = 1;i<n;i++)
    {
        if(ant[i]!=0)
        {
                incount++;
                printf("%d",ant[i]);
                if(incount!=count)
                {
                    printf(" ");
                }
        }
    }
}