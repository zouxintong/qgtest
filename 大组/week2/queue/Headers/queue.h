#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
//定义链式队列节点结构体
typedef struct node {
    void* data;
    struct node* next;
} Node;
//定义链式队列结构体
typedef struct Lqueue {
    Node* front;
    Node* rear;
    size_t length;
} LQueue;
//定义枚举类型
typedef enum { FALSE = 0, TRUE = 1 } Status;

extern char type;
extern char datatype[30];

void InitLQueue(LQueue* Q);
void DestroyLQueue(LQueue* Q);
Status IsEmptyLQueue(const LQueue* Q);
Status GetHeadLQueue(LQueue* Q, void** e);
int LengthLQueue(LQueue* Q);
Status EnLQueue(LQueue* Q, void* data);
Status DeLQueue(LQueue* Q);
void ClearLQueue(LQueue* Q);
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q));
void LPrint(void* q);

#endif

