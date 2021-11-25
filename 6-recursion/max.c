#include<stdio.h>
#include<stdlib.h>
void Findm(int* num,int n,int start,int*index1,int* index2)
{
    if(n>=start)
    {
        int index = start;
        int max = num[start];
        for(int i = start;i<=n;i++)
        {
            if(num[i]>num[index])
            {
                index = i;
                max = num[i];
            }
        }
        //find the max number
        index1[index] = start+1;
        index2[index] = n+1;
        Findm(num,index-1,start,index1,index2);
        Findm(num,n,index+1,index1,index2);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int* num;
    num = (int*)malloc(n*sizeof(int));
    int* index1;
    index1 = (int*)malloc(n*sizeof(int));
    int* index2;
    index2 = (int*)malloc(n*sizeof(int));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    Findm(num,n-1,0,index1,index2);
    for(int i= 0;i<n;i++)
    {
        printf("%d %d\n",index1[i],index2[i]);
    }
    return 0;
}