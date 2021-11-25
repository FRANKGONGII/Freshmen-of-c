#include<stdio.h>
#include<math.h>
char tri[20000][20000];
void Print(int n,int x,int y)
{
    if(n<8)
    {
        return;
    }
    else
    {
        for(int i = (n/4)-1;i>0;i--)
        {
            tri[y][x+i] = '_';
            tri[y][x-i+1] = '_';
        }
        for(int i = (n/4);i>0;i--)
        {
            tri[y+i][x-(n/4)+i] = '\\';
        }
        for(int i =(n/4);i>0;i--)
        {
            tri[y+i][x+(n/4-i+1)] = '/';
        }
    }
    Print(n/2,x-(n/4),y+(n/8));
    Print(n/2,x+(n/4),y+(n/8));
    Print(n/2,x,y-(n/8));
}
int main()
{
    int n;
    scanf("%d",&n);
    n = pow(2,n);
    int i,j;
    for(int i = 0;i<n;i++)
    {
        for(j = 0;j<2*n;j++)
        {
            tri[i][j] = ' ';
        }
    }
    for(int i = 0;i<2*n;i++)
    {
        tri[n-1][i] = '_';
    }
    for(int i = 0;i<n;i++)
    {
        tri[i][n-1-i] = '/';
    }
    for(int i = n;i<=2*n-1;i++)
    {
        tri[i-n][i] = '\\';
    }
    Print(2*n,n-1,(n/2)-1);
    for(int i = 0;i<n;i++)                    
    {                             
        for(int j = 0;j<2*n;j++)
        {
            printf("%c",tri[i][j]);
        }
        printf("\n");
    }
    return 0;
}