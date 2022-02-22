#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct String{
    char str[2000];
    struct String* next;
}string;

int hashStr(int hash,char* str){
    int len = strlen(str);
    int ret = 0;
    for(int i=0;i<len;i++){
        ret=(ret+str[i]*(i+1))%hash;
    }
    return ret;
}

int confirmExit(char** hashstr,int ret,char* req_str){
    char* str = hashstr[ret];
    int len1 = strlen(str);
    int len2 = strlen(req_str);
    if(len1!=len2){
        return 0;
    }
    else{
        int i;
        for(i = 0;i<len1;i++){
            if(str[i]==req_str[i]){
                continue;
            }
            else{
                return 0;
            }
        }
        if(i==len1){
            return 1;
        }
    }
}

int main(){
    int str_num,req_num;
    scanf("%d%d",&str_num,&req_num);
    int hash = 2*str_num;
    string* hashstr;
    hashstr = (string*)malloc(hash*sizeof(string));
    
    return 0;
}
