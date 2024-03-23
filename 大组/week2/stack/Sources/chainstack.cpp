#define _CRT_SECURE_NO_WARNINGS  // ���� scanf_s �����ľ���
#include <stdio.h>
#include <stdlib.h>
#include "chainstack.h"


    //��ʼ��ջ
void initStack(Stack* stack) {
    stack->top = NULL;
    stack->length = 0;
}

//�ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}



//��ȡջ��Ԫ��
int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("ջΪ��\n");
        return -1;
    }
    return stack->top->data;
}




  //���ջ
void clearStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
    stack->length = 0;
    printf("ջ�����\n");
}

  //����ջ
void destroyStack(Stack* stack) {
    clearStack(stack);
    free(stack);
    printf("ջ������\n");
}

//���ջ����
int stackLength(Stack* stack) {
    return stack->length;
}


//��ջ
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->length++;
    printf("%d ��ջ�ɹ�\n", data);
}

//��ջ
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("ջΪ��\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->length--;
    return data;
}
// �������뻺����
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
