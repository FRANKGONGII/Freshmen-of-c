#include<stdio.h>
#include<string.h>
int main(){
    char score[30000];
    scanf("%[\n,W,L]",score);
    //printf("%s\n",score);
    int i = 0;
    int ch = 0;
    int fo = 0;
    while(score[i]!='\0'){
        if(score[i]=='W'){
            ch++;
        }
        else if(score[i]=='L'){
            fo++;
        }
        if((ch>=11||fo>=11)&&((ch-fo>=2)||(fo-ch>=2))){
            printf("%d:%d\n",ch,fo);
            ch = 0;
            fo = 0;
        }
        i++;
    }
    if(score[i]=='\0'){
        printf("%d:%d\n\n",ch,fo);
        ch = 0;
        fo = 0;
    }
    i = 0;
    while(score[i]!='\0'){
        if(score[i]=='W'){
            ch++;
        }
        else if(score[i]=='L'){
            fo++;
        }
        if((ch>=21||fo>=21)&&((ch-fo>=2)||(fo-ch>=2))){
            printf("%d:%d\n",ch,fo);
            ch = 0;
            fo = 0;
        }
        i++;
    }
    if(score[i]=='\0'){
        printf("%d:%d",ch,fo);
        ch = 0;
        fo = 0;
    }
    return 0;
}