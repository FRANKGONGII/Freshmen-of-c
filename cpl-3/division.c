//we are given two binary numbers here, and we need calculate A/B and A%B, the translate the result to two binary numbers
//else, we need to follow a special rule, put the (A%B) behind the A and output them 
#include<stdio.h>
#include<string.h>
#include<math.h>
int Trans_2_s(long long num,char* nums)
{
    int i = 0;
    while(num!=0)
    {
        nums[i] = (num%2);
        num /= 2;
        i++;
    }
    return i;
    //i is the number of digits
}
void Trans_2(long long num)
{
    if(num>0)
    {
        Trans_2(num/2);
    }
    if(num!=0)
    {
        printf("%d",num%2);
    }
}
//print a number in binary form
long long Trans_1(char* num,int len)
{
    long long sum = 0;
    for(int i = 0;i<len;i++)
    {
        sum +=  (num[i]-48)*pow(2,len-1-i);
    }
    return sum;
}
//translate a binary number to decimal number
int main()
{
    char nums1[50];
    char nums2[50];
    scanf("%s",nums1);
    scanf("%s",nums2);
    int len1 = strlen(nums1);
    int len2 = strlen(nums2);
    long long num1 = Trans_1(nums1,len1);
    long long num2 = Trans_1(nums2,len2);
    if(num1>=num2)
    {
        Trans_2(num1/num2);
        //we make num1/num2 a binary number here and output it
    }
    //num1 is bigger than num2
    else if(num1<num2)
    {
        printf("0");
    }
    printf("\n");
    //num1 is smaller than num2
    for(int i = 0;i<len1;i++)
    {
        printf("%c",nums1[i]);
    }
    //print (b)num1, prepare to print (A%B) behind
    char nums4[50];
    int ret = Trans_2_s(num1%num2,nums4);
    //get the number of digits of (A%B)
    for(int i = 0;i<len2-ret;i++)
    {
        printf("0");
    }
    //print some 0 to make the (A%B) the has the same digits as num2
    for(int i = ret-1;i>=0;i--)
    {
        printf("%d",nums4[i]);
        //print (A%B)
        //the same question, why d can print but c can not??(i know that now!!But i don't want to correct it here)
    }
    return 0;
}
