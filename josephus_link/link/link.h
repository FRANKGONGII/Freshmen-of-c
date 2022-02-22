#ifndef LINK_LINK_H_
#define LINK_LINK_H_
//避免多次在不同头文件里面引用同一个头文件
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}Node;
typedef struct ll{
    Node *head;
    Node *tail;
}LinkList;

void Init(LinkList *list);
void Append(LinkList *list,int i);
Node *Search(const LinkList *list, int val);// 如何寻找一个具有特定值的节点？

#endif LINK_LINK_H_