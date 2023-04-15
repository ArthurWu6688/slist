//
// Created by 吴映鹏 on 2023/4/14.
//

#ifndef LIST_SLIST_H
#define LIST_SLIST_H

#include "common.h"
#define SList_ElemType int

typedef struct SListNode {
    SList_ElemType data;
    struct SListNode *next;
}SListNode,*SList;

//函数声明
void SListInit(SList* phead);
void SListPushBack(SList *phead,SList_ElemType value);
void SListPushFront(SList *phead,SList_ElemType value);
void SListPopBack(SList *phead);
void SListPopfront(SList *phead);
void SListShow(SList phead);
SListNode* SListFind(SList phead,SList_ElemType key);
int SListLength(SList phead);
void SListDeleteByVal(SList *phead,SList_ElemType key);
void SListInsertByVal(SList *phead,SList_ElemType value);

//函数定义
void SListInit(SList* phead) {
    assert(phead != NULL);
    *phead = NULL;
}

//插入
void SListPushBack(SList *phead,SList_ElemType value) {
    assert(phead != NULL);
    SListNode *s = (SListNode *) malloc(sizeof(SListNode));
    assert(s != NULL);
    s->next = NULL;
    s->data = value;

    if (*phead == NULL)
        *phead = s;
    else {
        SListNode *p = *phead;
        while (p->next != NULL)
            p = p->next;
        p->next = s;
    }
}

void SListPushFront(SList *phead,SList_ElemType value){
    assert(phead!=NULL);
    SListNode *s = (SListNode*)malloc(sizeof(SListNode));
    assert(s != NULL);
    s->data=value;
    s->next=*phead;
    *phead=s;
}

void SListInsertByVal(SList *phead,SList_ElemType value) {
    SListNode *s = (SListNode *) malloc(sizeof(SListNode));
    s->next = NULL;
    s->data = value;

    SListNode *prve = NULL;
    SListNode *p = *phead;
    while (p != NULL && p->data < value) {
        prve = p;
        p = p->next;
    }
    if (p == NULL) {
        prve->next = s;
    }
    if (prve != NULL) {
        s->next = p;
        prve->next = s;
    } else {
        s->next = p;
        *phead = s;
    }
}

//删除
void SListPopBack(SList *phead) {
    assert(phead != NULL);
    SList p = *phead;
    SList prev = NULL;
    while (p->next != NULL) {
        prev = p;
        p = p->next;
    }
    if (prev == NULL)
        *phead = NULL;
    else
        prev->next = NULL;
    free(p);
}

void SListPopfront(SList *phead) {
    assert(phead != NULL);
    SListNode *p = *phead;
    *phead = p->next;
    free(p);
}

void SListDeleteByVal(SList *phead,SList_ElemType key) {
    assert(phead);
    SListNode *p = *phead;
    SListNode *prev = NULL;
    while (p->next != NULL && p->data != key) {
        prev = p;
        p = p->next;
    }
    if (p != NULL) {
        if (prev != NULL)
            prev->next = p->next;
        else
            *phead = p->next;
    }
    free(p);
}

//查找
SListNode* SListFind(SList phead,SList_ElemType key) {
    assert(phead != NULL);
    while (phead != NULL&&phead->data!=key) {
        phead = phead->next;
    }
    return phead;
}

int SListLength(SList phead) {
    int len = 0;
    while (phead != NULL) {
        ++len;
        phead = phead->next;
    }
    return len;
}

//显示
void SListShow(SList phead) {
    while (phead != NULL) {
        printf("%d->", phead->data);
        phead = phead->next;
    }
    printf("over\n");
}

#endif //LIST_SLIST_H
