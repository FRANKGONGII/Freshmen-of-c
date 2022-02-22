#include<stdio.h>
#include<stdlib.h>
void printStack(int **stack, int n){
    for(int i = 0;i<n;i++){
        if(*(stack+i)==NULL){
            printf("0\n");
            continue;
        }
        else{
            if(*(*(stack+i))>=1){
                for(int j = 1;j<=*(*(stack+i));j++){
                    printf("%d ",*(*(stack+i)+j));
                }
                printf("\n");
            }
            else{
                printf("0");
                printf("\n");
            }
        }
    }
}
void pourStack(int x,int y,int** stack,int n){
    if(*(stack+x-1)==NULL){
        return;
    }
    else{ 
        int len_x = *(*(stack+x-1));
        if(*(stack+y-1)==NULL){
            *(stack+y-1) = (int*)malloc(len_x*sizeof(char));
            *(*(stack+y-1)) = 0;
        }
        int len_y = *(*(stack+y-1));
        for(int i = len_x;i>0;i--){
            *(*(stack+y-1)+len_y+(len_x-i+1)) = *(*(stack+x-1)+i);
        }
        *(*(stack+y-1)) += *(*(stack+x-1));
        free(*(stack+x-1));
        *(stack+x-1) = NULL;
    }
}
int main(){
    int n,m;// n是初始栈的个数，m是操作的次数
    scanf("%d%d",&n,&m);
    int** stack;
    stack = (int**)malloc(n*sizeof(int*));
    for(int i = 0;i<n;i++){
        *(stack+i) = (int*)malloc(100*sizeof(int));
        *(*(stack+i)) = 1;// 每个栈内目前只有一个元素
        *(*(stack+i)+1) = i+1;// 每个栈的第一个元素
    }
    int x,y;
    for(int i = 0;i<m;i++){
        scanf("%d%d",&x,&y);// x是倒的，y是被倒的
        pourStack(x,y,stack,n);
    }
    printStack(stack,n);
}