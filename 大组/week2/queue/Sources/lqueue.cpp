#define _CRT_SECURE_NO_WARNINGS  // 忽略 scanf_s 函数的警告
#include "lqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char type;
char datatype[30];


// 初始化队列
void InitLQueue(LQueue* Q) {
    Q->front = Q->rear = NULL;  // 将队头和队尾指针置空
    Q->length = 0;              // 长度设为0
}

// 销毁队列
void DestroyLQueue(LQueue* Q) {
    Node* p = Q->front;
    while (p != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp->data);   // 释放结点中存储的数据
        free(temp);         // 释放结点空间
    }
    Q->front = Q->rear = NULL;  // 将队头和队尾指针置空
    Q->length = 0;              // 长度设为0
    free(Q);
}

// 判断队列是否为空
Status IsEmptyLQueue(const LQueue* Q) {
    return Q->length == 0 ? TRUE : FALSE;  // 长度为0表示空队列
}

// 获取队列的队头元素
Status GetHeadLQueue(LQueue* Q, void** e) {
    if (IsEmptyLQueue(Q))   // 如果队列为空，则返回FALSE
        return FALSE;
    *e = Q->front->data;    // 否则，将队头元素的数据指针传递给e
    return TRUE;
}

// 获取队列的长度
int LengthLQueue(LQueue* Q) {
    return Q->length;   // 返回队列长度
}

// 入队操作
Status EnLQueue(LQueue* Q, void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));   // 分配新结点空间
    if (newNode == NULL)    // 若分配失败，则返回FALSE
        return FALSE;

    newNode->data = data;   // 将数据存储到新结点中
    newNode->next = NULL;   // 新结点的next指针置空

    if (IsEmptyLQueue(Q)) {     // 如果队列为空
        Q->front = Q->rear = newNode;  // 新结点为队头也是队尾
    }
    else {
        Q->rear->next = newNode;    // 否则，将新结点连接到队尾
        Q->rear = newNode;          // 并更新队尾指针
    }

    Q->length++;   // 队列长度加1
    return TRUE;
}

// 出队操作
Status DeLQueue(LQueue* Q) {
    if (IsEmptyLQueue(Q))   // 如果队列为空，则返回FALSE
        return FALSE;

    Node* temp = Q->front;   // 保存队头指针
    Q->front = Q->front->next;   // 更新队头指针为下一个结点
    free(temp->data);    // 释放队头结点中存储的数据
    free(temp);          // 释放队头结点空间

    if (Q->front == NULL)   // 若队头为空，则队尾也为空
        Q->rear = NULL;

    Q->length--;   // 队列长度减1
    return TRUE;
}

// 清空队列
void ClearLQueue(LQueue* Q) {
    Node* p = Q->front;
    while (p != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp->data);   // 释放结点中存储的数据
        free(temp);         // 释放结点空间
    }
    Q->front = Q->rear = NULL;  // 将队头和队尾指针置空
    Q->length = 0;              // 长度设为0
}

// 遍历队列并对每个元素执行函数foo
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
    if (IsEmptyLQueue(Q))   // 如果队列为空，则返回FALSE
        return FALSE;

    Node* p = Q->front;   // 从队头开始遍历
    while (p != NULL) {
        foo(p->data);    // 对每个元素执行函数foo
        p = p->next;     // 移动到下一个结点
    }
    return TRUE;
}

// 打印队列元素
void LPrint(void* q) {
    if (strcmp(datatype, "int") == 0) {
        printf("%d ", *(int*)q);
    }
    else if (strcmp(datatype, "float") == 0) {
        printf("%.2f ", *(float*)q);
    }
    else if (strcmp(datatype, "char") == 0) {
        printf("%c ", *(char*)q);
    }
    else {
        printf("不支持的数据类型\n");
    }
}



