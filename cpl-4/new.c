#include<stdio.h>
#include<string.h>
int Check(char* str1,char* str2,int i,int j,int len1,int len2){
    if(i<=len1-1&&j<len2-1){// 原串还没有走完
        if(str1[i]==str2[j]&&str2[j+1]!='*'){// 直接相等
            Check(str1,str2,i++,j++,len1,len2);
        }
        else if(str1)

    }
}
int main(){
    char str1[50];
    char str2[50];
    scanf("%s%s",str1,str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int ret = Check(str1,str2,0,0,len1,len2);
    if(ret == 0){
        printf("0");
    }
    else{
        printf("1");
    }
    return 0;
}