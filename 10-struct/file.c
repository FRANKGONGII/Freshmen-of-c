#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct file{
    char str[20];
    struct file* son1;
    struct file* son2;
    struct file* father;
}File;

int Quire(File* file,int num);

int R_Search(File* file,char* str){
    printf("file = %s\n",file->str);
    printf("str = %s\n",str);
    if(strcmp(file->str,str)==0){
        if(file->father->son1!=NULL&&strcmp(file->father->son1->str,str)==0){
            printf("!!\n");
            file->father->son1 = NULL;
            return 1;
        }
        printf("match\n");
        file->father->son2 = NULL;
        return 1;
    }
    else{
        if(file->son1==NULL&&file->son2==NULL){
            return 0;
        }
        else if(file->son1==NULL&&file->son2!=NULL){
            return R_Search(file->son2,str);
        }
        else if(file->son2==NULL&&file->son1!=NULL){
            return R_Search(file->son1,str);
        }
        else{
            int ret = R_Search(file->son1,str);
            if(ret!=0){
                printf("%d\n",ret);
                return 1;
            }
            else{
                return R_Search(file->son2,str);
            }
        }
    }
}


int Q_Search(File* file,char* str,int num){
    int num1 = 0;
    int num2 = 0;
    if(strcmp(file->str,str)==0){
        if(file->son1!=NULL){
            num++;// 加一个点
            num1 = Quire(file->son1,num);
        }
        if(file->son2!=NULL){
            if(file->son1==NULL){
                num++;
            }
            num2 = Quire(file->son2,num);
        }
        //printf("FIND\n");
        int ret = num1+num2+1;
        return ret;
    }
    else{
        if(file->son1!=NULL&&file->son2==NULL){
            return Q_Search(file->son1,str,num);
        }
        else if(file->son2!=NULL&&file->son1==NULL){
            return Q_Search(file->son2,str,num);
        }
        else if(file->son1!=NULL&&file->son2!=NULL){
            return Q_Search(file->son1,str,num)+Q_Search(file->son2,str,num);
        }
        else if(file->son1==NULL&&file->son2==NULL){
            return 0;
        }
    }
}

int Quire(File* file,int num){
    int num1 = 0;
    int num2 = 0;
    if(file->son1!=NULL){
        num++;
        num1 = Quire(file->son1,num);
    }
    if(file->son2!=NULL){
        if(file->son1==NULL){
            num++;
        }
        num2 = Quire(file->son2,num);
    }
    if(file->son1==NULL&&file->son2==NULL){
        return 1;
    }
    return num1+num2+1;
}

void Print(File* file){
    int i = 0;
    while((file->str[i]>=48&&file->str[i]<=57)||(file->str[i]>=97&&file->str[i]<=122)){
        printf("%c",file->str[i]);
        i++;
    }
    if(file->str[i]=='\0'){
        return;
    }
}

void Init(File* file){
    file->son1 = NULL;
    file->son2 = NULL;
    file->father = NULL;
}

void Mystrcmp(File* file,char* str){
    int i = 0;
    while(str[i]!='\0'){
        file->str[i] = str[i];
        i++;
    }
    if(str[i]=='\0'){
        file->str[i] = '\0';
    }
}

void Link(File* file,File* head,char* str2){
    if(strcmp(str2,head->str)==0){
        //printf("match\n");
        if(head->son1==NULL){
            head->son1 = file;
            file->father = head;
            return;
        }
        else{
            head->son2 = file;
            file->father = head;
            return;
        }
    }
    else{
        if(head->son1!=NULL){
            Link(file,head->son1,str2);
        }
        if(head->son2!=NULL){
            Link(file,head->son2,str2);
        }
    }
}

int main(){
    int file_num,re_num;
    scanf("%d%d",&file_num,&re_num);
    File* head;
    head = (File*)malloc(sizeof(*head));
    for(int i = 0;i<file_num;i++){
        char str1[20];
        char str2[20];
        scanf("%s%s",str1,str2);
        if(str2[0]=='~'){
            Init(head);
            Mystrcmp(head,str1);
        }
        else{
            File* file;
            file = (File*)malloc(sizeof(*file));
            Init(file);
            Mystrcmp(file,str1);
            Link(file,head,str2);
        }
    }
    for(int i = 0;i<re_num;i++){
        char re[20];
        char str[20];
        scanf("%s%s",re,str);
        if(re[0]=='q'){
            int ret = Q_Search(head,str,0);
            printf("%d\n",ret);
        }
        else if(re[0]=='r'){
            R_Search(head,str);
        }
    }
    return 0;
}
