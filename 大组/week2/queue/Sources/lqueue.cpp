#define _CRT_SECURE_NO_WARNINGS  // ���� scanf_s �����ľ���
#include "lqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char type;
char datatype[30];


// ��ʼ������
void InitLQueue(LQueue* Q) {
    Q->front = Q->rear = NULL;  // ����ͷ�Ͷ�βָ���ÿ�
    Q->length = 0;              // ������Ϊ0
}

// ���ٶ���
void DestroyLQueue(LQueue* Q) {
    Node* p = Q->front;
    while (p != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp->data);   // �ͷŽ���д洢������
        free(temp);         // �ͷŽ��ռ�
    }
    Q->front = Q->rear = NULL;  // ����ͷ�Ͷ�βָ���ÿ�
    Q->length = 0;              // ������Ϊ0
    free(Q);
}

// �ж϶����Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q) {
    return Q->length == 0 ? TRUE : FALSE;  // ����Ϊ0��ʾ�ն���
}

// ��ȡ���еĶ�ͷԪ��
Status GetHeadLQueue(LQueue* Q, void** e) {
    if (IsEmptyLQueue(Q))   // �������Ϊ�գ��򷵻�FALSE
        return FALSE;
    *e = Q->front->data;    // ���򣬽���ͷԪ�ص�����ָ�봫�ݸ�e
    return TRUE;
}

// ��ȡ���еĳ���
int LengthLQueue(LQueue* Q) {
    return Q->length;   // ���ض��г���
}

// ��Ӳ���
Status EnLQueue(LQueue* Q, void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));   // �����½��ռ�
    if (newNode == NULL)    // ������ʧ�ܣ��򷵻�FALSE
        return FALSE;

    newNode->data = data;   // �����ݴ洢���½����
    newNode->next = NULL;   // �½���nextָ���ÿ�

    if (IsEmptyLQueue(Q)) {     // �������Ϊ��
        Q->front = Q->rear = newNode;  // �½��Ϊ��ͷҲ�Ƕ�β
    }
    else {
        Q->rear->next = newNode;    // ���򣬽��½�����ӵ���β
        Q->rear = newNode;          // �����¶�βָ��
    }

    Q->length++;   // ���г��ȼ�1
    return TRUE;
}

// ���Ӳ���
Status DeLQueue(LQueue* Q) {
    if (IsEmptyLQueue(Q))   // �������Ϊ�գ��򷵻�FALSE
        return FALSE;

    Node* temp = Q->front;   // �����ͷָ��
    Q->front = Q->front->next;   // ���¶�ͷָ��Ϊ��һ�����
    free(temp->data);    // �ͷŶ�ͷ����д洢������
    free(temp);          // �ͷŶ�ͷ���ռ�

    if (Q->front == NULL)   // ����ͷΪ�գ����βҲΪ��
        Q->rear = NULL;

    Q->length--;   // ���г��ȼ�1
    return TRUE;
}

// ��ն���
void ClearLQueue(LQueue* Q) {
    Node* p = Q->front;
    while (p != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp->data);   // �ͷŽ���д洢������
        free(temp);         // �ͷŽ��ռ�
    }
    Q->front = Q->rear = NULL;  // ����ͷ�Ͷ�βָ���ÿ�
    Q->length = 0;              // ������Ϊ0
}

// �������в���ÿ��Ԫ��ִ�к���foo
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
    if (IsEmptyLQueue(Q))   // �������Ϊ�գ��򷵻�FALSE
        return FALSE;

    Node* p = Q->front;   // �Ӷ�ͷ��ʼ����
    while (p != NULL) {
        foo(p->data);    // ��ÿ��Ԫ��ִ�к���foo
        p = p->next;     // �ƶ�����һ�����
    }
    return TRUE;
}

// ��ӡ����Ԫ��
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
        printf("��֧�ֵ���������\n");
    }
}



