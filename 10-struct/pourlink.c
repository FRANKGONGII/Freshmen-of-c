#include<stdio.h>
#include<stdlib.h>
typedef struct Value{
    int element;
    struct Value* next;
    struct Value* back;
}value;
typedef struct List{
    struct Value* head;
    struct Value* tail;
}list;

/*void pourStack(int x,int y,list* index){
    (index+y-1)->tail->next = (index+x-1)->tail;
    value* move = (index+x-1)->tail->back;
    if(move==NULL){// 只有一个数
        (index+x-1)->tail->next = NULL;
        (index+x-1)->tail->back = (index+y-1)->tail;
        (index+y-1)->tail = (index+x-1)->head;
        (index+x-1)->head = NULL;
        (index+x-1)->tail = NULL;
    }
    else{
        while(move->back!=NULL){
            value* tmp = move->back;
            move->back = move->next;
            move->next = tmp;
            move = move->next;
        }
        if(move->back==NULL){// 说明走到头了
            move->back = move->next;
            move->next = NULL;
        }
        (index+x-1)->tail->back = (index+y-1)->tail;
    }
    
}*/

void pourStack(int x,int y,list* index){
    if((index+x-1)->head==NULL){
        return;// x栈里面没有元素
    }
    if((index+y-1)->head!=NULL){// y是一个原本有元素的栈
        value* move = (index+x-1)->tail;
        while(move->back!=NULL){// 还没走到头
            value* val = malloc(sizeof(*val));
            val->element = move->element;
            (index+y-1)->tail->next = val;
            val->back = (index+y-1)->tail;
            val->next = NULL;
            (index+y-1)->tail = val;
            move = move->back;
            free(move->next);
        }
        if(move->back==NULL){// 已经走到头
            value* val = malloc(sizeof(*val));
            val->element = move->element;
            val->next = NULL;
            (index+y-1)->tail->next = val;
            val->back = (index+y-1)->tail;
            (index+y-1)->tail = val;
            (index+x-1)->head= NULL;
            (index+x-1)->tail= NULL;
            free(move);
        }
    }
    else if((index+y-1)->head==NULL){// y没有元素
        (index+y-1)->head = (index+x-1)->tail;
        (index+y-1)->tail = (index+x-1)->tail;
        value* move = (index+x-1)->tail->back;
        while(move!=NULL){
            value* val = malloc(sizeof(*val));
            val->element = move->element;
            (index+y-1)->tail->next = val;
            val->back = (index+y-1)->tail;
            val->next = NULL;
            (index+y-1)->tail = val;
            move = move->back;
            //free(move->next);
        }
        if(move==NULL){
            (index+x-1)->head = NULL;
            (index+x-1)->tail = NULL;
            (index+y-1)->head->back = NULL;
            (index+y-1)->tail->next = NULL;
            return;
        }
    }
}
void makeList(int i,list* index){
    value* val = malloc(sizeof(*val));
    val->element = i+1;
    (index+i)->head = val;// 不要忘记必须是结构体指针才能用->
    (index+i)->tail = val;
    val->next = NULL;
    val->back = NULL;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    list* index;
    index = (list*)malloc(n*sizeof(list));
    for(int i = 0;i<n;i++){
        makeList(i,index);
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        pourStack(x,y,index);
    }
    for(int i = 0;i<n;i++){
        value* move = (index+i)->head;
        do{
            if(move==NULL){
                printf("0");
            }
            else{
                printf("%d ",move->element);
                move = move->next;
            }
        }while(move!=NULL);
        printf("\n");
    }
    //printf("%d",(index+1)->tail->element);
    return 0;
}