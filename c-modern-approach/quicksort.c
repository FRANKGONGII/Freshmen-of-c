#include<stdio.h>
int split(int* num,int low,int high)
{
    int part_element = num[low];
    while(1)
    {
        while(low<high && part_element <= num[high])
        {
            high--;
        }
        if(low>=high)
        {
            break;
        }
        num[low++] = num[high];
        while(low<high && num[low] <= part_element)
        {
            low++;
        }
        if(low>=high)
        {
            break;
        }
        num[high--] = num[low];
    }
    num[low] = part_element;
    return low;
}
void quicksort(int* num,int low,int high)
{
    int middle;
    if(low>=high)
    {
        return ;
    }
    middle = split(num,low,high);
    quicksort(num,low,middle-1);
    quicksort(num,middle+1,high);
}
int main()
{
    int num[10];
    for(int i = 0;i<10;i++)
    {
        scanf("%d",&num[i]);
    }
    quicksort(num,0,9);
    for(int i = 0;i<10;i++)
    {
        printf("%d ",num[i]);
    }
    return 0;
}