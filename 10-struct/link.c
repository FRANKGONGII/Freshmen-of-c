#include<stdio.h>
#include<stdlib.h>
typedef struct value{
       int val;
       struct value* next;
       struct value* back;
    } Value;
typedef struct ll{
        struct value* head;
        struct value* tail;
        struct value* move;
    } Linklist;

void Backward(Linklist *list,int m){// 把指针往后动m个节点
   for(int i = m;i>0;i--){
       list->move = list->move->back;
   }
} 

void Forward(Linklist *list,int m){// 把指针往前移动m个节点
    for(int i = m;i>0;i--){
        list->move = list->move->next;
    }
}

void Printl(Linklist *list){
    do{
        printf("%d",list->move->val);
        list->move = list->move->next;
    }while(list->move!=list->head);
}

void Remove(Linklist *list,int n){// 删除当前，move指向下一个节点
    Value *cur = list->move;// 备份用于删除
    list->move = list->move->back;// 指向上一个
    list->move->next = cur->next;
    cur->next->back = list->move;
    list->move = cur->next;
    free(cur);
    return;
}


void Insert(Linklist *list,int val){// 后面新增一个节点
    Value *value = (Value*)malloc(sizeof(*value));
    value->val = val;
    value->next = list->move->next;
    list->move->next->back = value;
    list->move->next = value;
    value->back = list->move;
    return;
}


void Print(Linklist *list){
    printf("%d\n",list->move->val);
    return;
}


void Append(Linklist *list,int i){
    Value *value = malloc(sizeof(*value));
    value->val = i;// 节点里的值
    if(list->head==NULL){// 如果链表里面还没有节点
        list->move = value;
        list->head = value;
        list->tail = value;
        value->back = list->head;
        value->next = list->head;
    }
    else{// 链表里面有节点
        list->tail->next = value;// list->tail 是上一个节点的指针，这是把上一个节点里面的next指向下一个节点
        value->next = list->head;// 最新指针要往回指，形成循环
        value->back = list->tail;// 建立新的尾指针的back指针
        list->tail = value;// 这是让尾指针指向最新的节点
        list->head->back = list->tail;// 建立头指针的back指针
    }
}
int main(){
    int n;
    int t;
    int num;
    char order[50];
    scanf("%d%d",&n,&t);// n是链表节点数，t是操作数目
    Linklist list;
    list.head = NULL;
    list.tail = NULL;
    list.move = NULL;
    for(int i = 1;i<=n;i++){
        Append(&list,i);
    }
    for(int i = 0;i<t;i++){
        scanf("%s",order);
        if(order[0]=='F'){// 要执行Forward
            scanf("%d",&num);// 拿到步数
            if(num%n<=n/2){// 应该前进
                Forward(&list,num%n);
            }
            else{
                Backward(&list,n-(num%n));
            }
        }
        else if(order[0]=='B'){// 要执行Backward
            scanf("%d",&num);
            if(num%n>=n/2){
                Forward(&list,n-(num%n));
            }
            else{
                Backward(&list,num%n);
            }
        }
        else if(order[0]=='P'){
            Print(&list);
        }
        else if(order[0]=='I'){
            scanf("%d",&num);
            Insert(&list,num);// 这里会改动整链表的节点数
            n++;
        }
        else if(order[0]=='R'){
            Remove(&list,n);
            n--;
        }
    }
    return 0;
}