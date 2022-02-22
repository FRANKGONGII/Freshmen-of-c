#include<stdio.h>
int Express(char arr[],char tar[],int poi1,int poi2){
    char a=0;
    if(!tar[poi2]){
        if(!arr[poi1]) return 1;
        else return 0;
    }
     else if(tar[poi2]=='\\'){
       a=tar[poi2+1];
       if(tar[poi2+2]!='*'){
           if (arr[poi1]==a) return Express(arr,tar,poi1+1,poi2+2);
           else return 0;
       }
       else if(arr[poi1]==a) return Express(arr,tar,poi1,poi2+3)||Express(arr,tar,poi1+1,poi2);
       else return Express(arr,tar,poi1,poi2+3);
     }
     else if(tar[poi2]=='.'){
         if(tar[poi2+1]!='*'){
            if(arr[poi1]) return Express(arr,tar,poi1+1,poi2+1);
            else return Express(arr,tar,poi1,poi2+1);
         } 
         else if(arr[poi1]) return Express(arr,tar,poi1,poi2+2)||Express(arr,tar,poi1+1,poi2);
         else return Express(arr,tar,poi1,poi2+2);
     }
     else{
         a=tar[poi2];
         if(tar[poi2+1]!='*'){
             if(a==arr[poi1]) return Express(arr,tar,poi1+1,poi2+1);
             else return 0;
         }
         else if(arr[poi1]==a) return Express(arr,tar,poi1,poi2+2)||Express(arr,tar,poi1+1,poi2);
         else return Express(arr,tar,poi1,poi2+2);
     }
}

int main(){
    char arr[35]={'\0'};
    char tar[35]={'\0'};
    scanf("%s\n%s",&arr,&tar);
    printf("%d",Express(arr,tar,0,0));
    return 0;
}

/*递归，遇到*分别分出消除、不消除两个分支
递归结束：正则表达式为空、正则中遇到无*的字符且与给定字符串不符
注意.*的分析*/

