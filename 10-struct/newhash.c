#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct String{
    char str[1005];
    //struct String* next;
    struct String* back;
}string;

typedef struct List{
    string* head;
    string* tail;
}list;

int mystrcmp(char* str1,char* str);
void mystrcopy(string* s1,char* str);
int Hash(char*str,int n);


int mystrcmp(char* str1,char* str){
    int len1 = strlen(str1);
    int len2 = strlen(str);
    if(len1!=len2){
        return -1;
    }
    int i = 0;
    for(i = 0;i<len1;i++){
        if(str1[i]!=str[i]){
            return -1;
        }
    }
    if(i==len1){
        return 0;
    }
}

void mystrcopy(string* s1,char* str){
    int i;
    while(str[i]!='\0'){
        s1->str[i] = str[i];
        i++;
    }
    if(str[i]=='\0'){
        s1->str[i] = '\0';
    }
    return;
}

int Hash(char* str,int n){
    int len = strlen(str);
    int ret = 0;
    for(int i=0;i<len;i++){
        ret=(ret+str[i]*(i+1))%n;
    }
    return ret;
}

int main(){
    int str_num,req_num;
    scanf("%d%d",&str_num,&req_num);
    string** strlist;
    strlist = (string**)malloc((10+str_num)*sizeof(string*));// 建立头list数组

    for(int i = 0;i<10+str_num;i++){
        strlist[i] = NULL;
    }// 初始头尾list

    for(int i = 0;i<str_num;i++){
        /*char str1[2000];
        scanf("%s",str1);*/
        
        string* s1;
        s1 = (string*)malloc(sizeof(string));
        scanf("%s",s1->str);
        int ret = Hash(s1->str,10+str_num);
        //printf("%s = %d\n",s1->str,ret);

        //mystrcopy(s1,str1);


        if(strlist[ret]==NULL){// 这个hash值内还没有元素
            strlist[ret] = s1;
            s1->back = NULL;
            //s1->next = NULL;
        }
        else{// 这个hash值内已经有元素了
            //strlist[ret]->next = s1;
            s1->back = strlist[ret];
            strlist[ret] = s1;
            //s1->next = NULL;
        }
    }

    /*for(int i = 0;i<2*str_num;i++){
        if(strlist[i]!=NULL){
            printf("i = %d:",i);
            string* move = strlist[i];
            printf("%s ",move->str);
            while(move->back!=NULL){
                move = move->back;
                printf("%s ",move->str);
            }
        }
    }*/

    for(int i = 0;i<req_num;i++){
        char str[1005];
        scanf("%s",str);
        int ret = Hash(str,10+str_num);

        string* move = strlist[ret];
        if(strlist[ret]==NULL){
            printf("No\n");
        }
        else{
            while(move->back!=NULL){
                if(mystrcmp(move->str,str)==0){
                    printf("Yes\n");
                    break;
                }
                move = move->back;
                //printf("1 ");
            }
            //printf("here\n");
            if(move->back==NULL){
                //printf("here\n");
                if(mystrcmp(move->str,str)==0){
                    printf("Yes\n");
                }
                else{
                    printf("No\n");
                }
            }
        }
    }
    return 0;
}