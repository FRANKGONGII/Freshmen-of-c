#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n = 0;
    scanf("%d",&n);
    int* numbers;
    numbers = (int*)malloc(n*sizeof(int));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&numbers[i]);
        
    }
    printf("%d\n",numbers[0]);;
    for(int j = 1;j<n;j++)
    {
        int tmp = numbers[j];
        for(int s = 0;s<j;s++)
        {
            if(numbers[s]>tmp)
            {
                int tmp2 = numbers[s];
                numbers[s] = tmp;
                tmp = tmp2;
            }
            numbers[j] = tmp;
        }
        for(int i = 0;i<=j;i++)
        {
            printf("%d ",numbers[i]);
        }
       if(j!=n-1)
       {
           printf("\n");
       }
    }
    return 0;
}    