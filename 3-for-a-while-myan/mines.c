#include<stdio.h>
int main()
{
    int n = 0;
    scanf("%d\n",&n);
    char arr[n+2][n+2];
    for(int i = 0;i<n+2;i++)
    {
        for(int j = 0;j<n+2;j++)
        {
            arr[i][j]='o';
        }
    }
    for(int i = 1;i<n+1;i++)
    {
        for(int j = 1;j<n+1;j++)
        {
            scanf("%c",&arr[i][j]);
        }
        if(i != n)
        {
            getchar();
        }
    }

    for(int i = 1;i<n+1;i++)
    {
        for(int j = 1;j<n+1;j++)
        {
            int count = 0;
            if(arr[i][j]!='*')
            {
               
            for(int s = i -1;s<i+2;s++)
            {
                for(int p = j-1;p<j+2;p++)
                {
                    if((s!=i||p!=j)&&arr[s][p]=='*')
                    {
                        count++;
                    }
                }
            } 
            arr[i][j] = (char)count;
            }
           
        }
    }
    for(int i = 1;i<n+1;i++)
    {
        for(int j =1;j<n+1;j++)
        {
            if(arr[i][j]=='*')
            {
                printf("%c",arr[i][j]);
            }
            else
            {
                printf("%d",arr[i][j]);
            }
            
        }
        printf("\n");
    }
    return 0;
}