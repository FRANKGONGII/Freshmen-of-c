#include<stdio.h>
int judgeNum(int i,int row,int col,int n,int squ[n+2][n+2])
{
    
    int next_col = col +1;
    int next_row = row -1;
    if(squ[next_row][next_col]==-1)
    {
        return -1;
    }
    else if(squ[next_row][next_col]==-2)
    {
        if(next_col==n+1)
        {
            return 2;
        }
        else if(next_row==0)
        {
            return 3;
        }
    }
    else if(squ[next_row][next_col]==0)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int squ[n+2][n+2];
    for(int i = 0;i<n+2;i++)
    {
        for(int j = 0;j<n+2;j++)
        {
            squ[i][j] = 0;
        }
    }
    squ[0][0] = -1;
    squ[0][n+1] = -1;
    squ[n+1][0] = -1;
    squ[n+1][n+1] = -1;
    for(int i = 1;i<n+1;i++)
    {
        squ[0][i] = -2;
        squ[n+1][i] = -2;
        squ[i][0] = -2;
        squ[i][n+1] = -2;
    }
    int row;
    int col;
    for(int i = 1;i<=n*n;i++)
    {
        if(i == 1)
        {   
            row = 1;
            col = (n+1)/2;
            squ[row][col] = i;
        }
        else if(i >= 1)
        {
            int ret = judgeNum(i,row,col,n,squ);
            if(ret == -1)
            {
                squ[row+1][col] = i;
                col = col;
                row += 1;
            }
            else if(ret == 2)
            {
                squ[row-1][1] = i;
                col = 1;
                row -= 1;
            }
            else if(ret == 3)
            {
                squ[n][col+1] = i; 
                row = n;
                col += 1;
            }
            else if(ret == 0)
            {
                squ[row - 1][col + 1] = i;
                row -= 1;
                col += 1;
            }
            else
            {
                squ[row+1][col] = i;
                row += 1;
                col = col;
            }
        }
    }
    for(int i = 1;i<n+1;i++)
    {
        for(int j = 1;j<n+1;j++)
        {
            printf("%d ",squ[i][j]);
        }
        if(i!=n)
        printf("\n");
    }
    return 0;
}