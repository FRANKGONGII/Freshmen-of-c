//a programme to judge an answer to a sudoku is right or wrong


#include<stdio.h>
void reSetarr(int* arr)
{
    for (int i = 0;i < 9;i++)
    {
        arr[i] = 0;
    }
}
int main()
{
    int arr[9][9] ;
    int test[9] = { 0 };
    int chekline = 1;
    int chekcol = 1;
    int chekgrid = 1;
    for (int i = 0;i < 9;i++)
    {
        for (int j = 0;j < 9;j++)
        {
            scanf("%d ",&arr[i][j]);
        }
    }
    for (int i = 0;i < 9;i++)
    {
        for (int j = 0;j < 9;j++)
        {
            test[arr[i][j] - 1]++;
        }
        for (int i = 0;i < 9;i++)
        {
            if (test[i] != 1)
            {
                chekline = 0;
                break;
            }
        }
        reSetarr(test);
    }
    //check every line, if the answer passes this test, keep chekline 1 and reset the count array

    for (int i = 0;i < 9;i++)
    {
        for (int j = 0;j < 9;j++)
        {
            test[arr[j][i] - 1]++;
        }
        for (int i = 0;i < 9;i++)
        {
            if (test[i] != 1)
            {
                chekcol = 0;
                break;
            }
        }
        reSetarr(test);
    }
    //check every culomn, if the answer passes this test, keep checkcol 1 and reset the count array

    for (int i = 1;i < 8;i += 3)
    {
        for (int j = 1;j < 8;j += 3)
        {
            for (int k = i - 1;k < i + 2;k++)
            {
                for (int s = i - 1;s < i + 2;s++)
                {
                    test[arr[k][s] - 1]++;
                }
            }
            for (int i = 0;i < 9;i++)
            {
                if (test[i] != 1)
                {
                    chekgrid = 0;
                    break;
                }
            }
            reSetarr(test);
            //check one grid
        }

    }
    //check all 9 grids

    if (chekgrid == 1 && chekline == 1 && chekcol == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}