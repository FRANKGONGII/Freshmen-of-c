#include<stdio.h>
#include<string.h>
void Trans(int num,int* nums,int i)
{
    for(int j = 7;j>=0;j--)
    {
        nums[j+8*i] = num%2;
        num /= 2;
    }
}
int main()
{
    int nums1[100];
    int num1;
    for(int i = 0;i<=3;i++)
    {
        scanf("%d",&num1);
        if(i!=3)
        {
            scanf(".");
        }
        Trans(num1,nums1,i);
    }
    int sons[100];
    int son;
    for(int i = 0;i<=3;i++)
    {
        scanf("%d",&son);
        if(i!=3)
        {
            scanf(".");
        }
        Trans(son,sons,i);
    }
    int nums2[100];
    int num2;
    for(int i = 0;i<=3;i++)
    {
        scanf("%d",&num2);
        if(i!=3)
        {
            scanf(".");
        }
        Trans(num2,nums2,i);
    }
    int res1[100];
    int res2[100];
    int j;
    for(j = 0;j<32;j++)
    {
        res1[j] = nums1[j] & sons[j];
        res2[j] = nums2[j] & sons[j];
        if(res1[j]==res2[j])
        {
            ;
        }
        else if(res1[j]!=res2[j])
        {
            printf("False");
            break;
        }
    }
    if(j==32)
    {
        printf("True");
    }
    return 0;
}