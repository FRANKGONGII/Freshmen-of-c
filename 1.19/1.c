#include<stdio.h>
#include <stdlib.h>
int main(){
    int num = 0;
    int k = 0;
    int n = 0;
    scanf("%d%d%d",&num,&k,&n);
    int* stu;
    stu = (int*)malloc(num*sizeof(int));
    for(int i = 0;i<num;i++){
        stu[i] = 1;
    }
    int j = 0;
    int i = 9;
    k%=10;
    n%=10;
    int count1= 0;
    int count2 = 0;
    while(num>0){
        for(j = 0;j<n;j++)
        {
            if(stu[j]==1)//alived man can die
            {
                count1++;
                if(count1==k)
                {
                    stu[j] = 0;//dead
                    count1=0;
                    num--;
                    printf("%d ",j+1);
                    if(num==0)
                    {
                        break;
                    }
                }
            }
        }
        /*for(i = 9;i>=0;i--)
        {
            if(stu[i]==1)//alived man can die
            {
                count2++;
                if(count2==n)
                {
                    stu[i] = 0;//dead
                    count2=0;
                    num--;
                    printf("%d ",j+1);
                    if(num==0)
                    {
                        break;
                    }
                }
            }
        }*/
    }
    return 0;
}