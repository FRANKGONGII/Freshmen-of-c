#include"link.h"
void Append(LinkList *list,int val){
    Node *node = malloc(sizeof(*node));// node是一个结构体指针，解引用得到整个结构体，因此sizeof(*node)
    if(node==NULL){
        printf("Error in malloc() in Append()");
        return;
    }
    else{
        node->val = val;// 记录这个node的编号


        // 先考虑一般情况，再考虑边界情况，最后看看能不能融合两个情况
        if(list->tail == NULL){// 目前这个链表是空的，现在是第一个元素
            list->head = node;
            list->tail = node;
            node->next = list->head;
        }
        else{
            list->tail->next = node;// 老的尾部要指向新的尾部 !!注意这里list—>tail可能是空指针
            node->next = list->head;// 新的尾部要指向链表的头部
            list->tail = node;// 这个node是新的尾部
        }
    }
}