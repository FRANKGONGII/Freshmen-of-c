#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    int* out;
    out = (int*)malloc(n*sizeof(int));
    for(int i = 1;i<=n;i++)
    {
        char str[100];
        scanf("%s",str);
        int len = strlen(str);
        for(int i = 0;i<len;i++)
        {
            char min = str[i];
            int index = i;
            for(int j = i+1;j<len;j++)
            {
                if(str[j]<min)
                {
                   min = str[j];
                   index = j;
                }
            }
            int tmp = str[i];
            str[i] = str[index];
            str[index] = tmp;
        }
        int test = 1;
        for(int i = 0;i<len-1;i++)
        {
            if(str[i] == str[i+1] - 1)
            {
                continue;
            }
            else
            {
                test = 0;
                break;
            }
        }
        if(test)
        {
            out[i-1] = 1;
        }
        else
        {
           out[i-1] = 0;
        }
    }
    for(int i = 0;i<n;i++)
    {
        if(out[i] == 1)
        {
            printf("Yes");
            if(i != n-1)
            {
                printf("\n");
            }
        }
        else
        {
            printf("No");
            if(i != n-1)
            {
                printf("\n");
            }
        }
    }
}