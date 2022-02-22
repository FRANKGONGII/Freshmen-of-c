#include"link//link.h"
//一个循环链表，只需要指向头部和尾部的两个指针

void Sitaround(LinkList *list,int num);
void Kitione(LinkList *list);
void Print(LinkList *list);
void Delete(LinkList *list, Node *prev);// 传入上一个节点的指针，这样可以方便一点（pre->next就是要删除的节点）

int main(){
    LinkList list;
    int num;
    scanf("%d",&num);
    Init(&list);
    Sitaround(&list,num);
    //Kitione(&list);
    Print(&list);
    return 0;
}

void Siraround(LinkList *list,int num){
    for(int i = 1;i<=num;i++){
        Append(list,i);
    }
}

void Print(LinkList *list){
    if(list == NULL){
        return;
    }
    Node *iter = list->head;
    do{
        printf("%d ",iter->val);
        iter = iter->next;
    }while(iter != list->head);
}
    
void Delete(LinkList *list, Node* prev){
    Node *cur = prev->next;// cur是这次要删除的节点
    Node *next = cur->next;

    if(prev == cur){// 如果整个链表只有一个节点
        
    }

    if(cur == list->head){

    }
    else if(cur == list->tail){

    }
    else{

    }
    free(cur);
    Delete(list,next);// 删除被这次删除的下一个的下一个节点
}