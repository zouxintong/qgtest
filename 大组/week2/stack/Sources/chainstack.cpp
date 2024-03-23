#define _CRT_SECURE_NO_WARNINGS  // 忽略 scanf_s 函数的警告
#include <stdio.h>
#include <stdlib.h>
#include "chainstack.h"


    //初始化栈
void initStack(Stack* stack) {
    stack->top = NULL;
    stack->length = 0;
}

//判断栈是否为空
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}



//获取栈顶元素
int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空\n");
        return -1;
    }
    return stack->top->data;
}




  //清空栈
void clearStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
    stack->length = 0;
    printf("栈已清空\n");
}

  //销毁栈
void destroyStack(Stack* stack) {
    clearStack(stack);
    free(stack);
    printf("栈已销毁\n");
}

//检测栈长度
int stackLength(Stack* stack) {
    return stack->length;
}


//入栈
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->length++;
    printf("%d 入栈成功\n", data);
}

//出栈
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->length--;
    return data;
}
// 清理输入缓冲区
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
