#include<stdio.h>
#include<string.h>
int Check(char* str1,char* str2,int i,int j,int len1, int len2){
    if(i<len1-1&&j<len2-1){// 还没到最后一位（最多倒数第二位）
        if(str1[i]==str2[j]&&str2[j+1]!='*'){// 直接相等而且后一位不是*的情况
            return Check(str1,str2,++i,++j,len1,len2);
        }
        else if(str1[i]==str2[j]&&str2[j+1]=='*'){// 相等但是可以忽略
            int s = len1-1;
            int p = j+1;
            for(s = len1-1;s>i;s--){
                for(p = j+1;p<=len2-1;p++){
                    if(str1[s]==str2[j]){// 按照贪婪原则，利用X*匹配尽可能多的字符
                        break;
                    }
                }
            }
            return Check(str1,str2,++i,j+2,len1,len2)//忽略
            +Check(str1,str2,s,p,len1,len2);//贪婪
        }
        else if(str1[i]!=str2[j]){// 本位不相等
            if(str2[j]=='.'&&str2[j+1]!='*'){// 本位是万能字符，利用'.'替代任意字符，而且下一位不是*，不能无限替代
                return Check(str1,str2,++i,++j,len1,len2);
            }
            else if(str2[j]=='.'&&str2[j+1]=='*'){// 本位是万能字符，而且下一位是*，开启贪婪模式
                int s = len1-1;
                int p = j+1;
                for(s = len1-1,p=j+1;s>i,p<=len2-1;s--,p++){
                    if(str1[s]==str2[p]){
                        break;
                    }
                }
                return Check(str1,str2,s,p,len1,len2);
            }
            else if(str2[j]!='.'&&str2[j+1]=='*'){// 本位不是万能字符，利用*忽略不匹配的字符，
                return Check(str1,str2,i,j+2,len1,len2);
            }
            else if(str2[j]=='\\'){// 转义字符的情况
                if(str2[j+1]=='.'&&str1[i]=='.'){// 可以匹配上
                    return Check(str1,str2,++i,j+2,len1,len2);
                }
                else if(str2[j+1]=='*'&&str1[i]=='*'){
                    return Check(str1,str2,++i,j+2,len1,len2);
                }
                else if(str2[j+1]=='\\'&&str1[i]=='\\'){
                    return Check(str1,str2,++i,j+2,len1,len2);
                }
                else{// 不能匹配上
                    return 0;
                }
            }
            else{// 不相等的各种情况下不能匹配上
                return 0;
            }
        }
    }
    else if(i!=len1-1&&j==len2-1){// 正则串走完了，但是原始串还没有走完
        return 0;// 肯定不能通过
    }
    else if(i==len1-1&&j!=len2-1){// 走完了原始串，但是没有走完正则串
        for(;j<len2;j+=2){
            if(str2[j+1]=='*'){// 必须要是X*X*X*的形式才可以保证后面的内容不会影响
                continue;
            }
            else if(str2[j]=='\\'){
                if(str1[i]==str2[j+1]){
                    Check(str1,str2,++i,j+2,len1,len2);
                }
            }
            else{
                return 0;
            }
        }
    }
    else if(i==len1-1&&j==len2-1){
        if(str1[i]==str2[j]){
            return 1;
        }
        else if(str2[j]=='.'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(i>len1-1||j>len2-1){
        return 1;
    }
}
int main(){
    char str1[50];
    char str2[50];
    scanf("%s%s",str1,str2);// str1是原始串，str2是正则串
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0;
    int j = 0;
    int ret = Check(str1,str2,i,j,len1,len2);
    if(ret == 0){
        printf("0");
    }
    else{
        printf("1");
    }
    return 0;
}
