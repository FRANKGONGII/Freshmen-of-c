#include<stdio.h>
#include<stdlib.h>
int main()
{
    long n,m;
    scanf("%ld %ld\n",&n,&m);
    long* nums1;
    nums1 = (long*)malloc(n*sizeof(long));
    long* nums2;
    nums2 = (long*)malloc(m*sizeof(long));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&nums1[i]);
    }
    for(int j = 0;j<m;j++)
    {
        scanf("%d",&nums2[j]);
    }
    long* all;
    all = (long*)malloc((m+n)*sizeof(long));
    for(int i = 0;i<n;i++)
    {
        all[i] = nums1[i];
    }
    for(int i = n;i<m+n;i++)
    {
        all[i] = nums2[i-n];
    }
    for(int i = 0;i<n+m;i++)
    {
        long min = all[i];
        int index = i;
        long tmp = 0;
        for(int j = i+1;j<n+m;j++)
        {
            if(all[j]<min)
            {
                min = all[j];
                index = j;
            }
        }
        tmp = all[i];
        all[i] = all[index];
        all[index] = tmp;
    }
    for(int i = 0;i<m+n;i++)
    {
        int test = 1;
        for(int j = i-1;j>0;j--)
        {
            if(all[i] == all[j])
            {
               test = 0;
            }
        }
        if(test)
        {
            printf("%ld ",all[i]);
        }
    }
    return 0;
}