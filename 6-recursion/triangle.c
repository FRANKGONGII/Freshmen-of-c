#include<stdio.h>
#include<stdlib.h>
#include<math.h>
char tri[2000][2000];
void Print(int n,int x,int y)
{
    if(n<2) 
    {
        return;         
    }
    int i;
    for(i=0;i<n-1;i++)
    {
        tri[x-n][y-i] = '_';        
        tri[x-i][y-i] = '\\';    
        tri[x-n][y+i] = '_';      
        tri[x-i][y+i] = '/';      
    }
    tri[x-i][y-i]   = '\\';
    tri[x-i][y+i-1] = '/';      
 
    Print(n/2,x,y-n);
    Print(n/2,x,y+n);
    Print(n/2,x-n,y);
}
 
int main()
{
    int n;
    scanf("%d",&n);
    n = pow(2,n);
    int i,j;
    for(i = 0;i< 1000;i++)
    {
        for(j = 0;j< 2000;j++)
        {
            tri[i][j] = ' ';
        }
    }
    for(int i = 0;i<2*n;i++)
    {
        tri[n-1][i] = '_';  
    }
    for(int i = n-1;i>=0;i--)
    {
        tri[i][n-i] = '/';
    }
    for(int i = 2*n-1;i>=n;i--)
    {
        tri[i][i-n] = '\\';
    }
    Print(n/2,n,n);
    for(i = 0;i<=n;i++)
    {
        for(j = 0;j<2*n;j++)
        {
            printf("%c",tri[i][j]);
        }
        printf("\n");
    }
    return 0;
}