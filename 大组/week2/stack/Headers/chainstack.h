#pragma once
#ifndef STACK_H
#define STACK_H

//������ջ�Ľڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//������ջ�ṹ
typedef struct {
    Node* top;
    int length;
} Stack;

void initStack(Stack* stack);
int isEmpty(Stack* stack);
int top(Stack* stack);
void clearStack(Stack* stack);
void destroyStack(Stack* stack);
int stackLength(Stack* stack);
void push(Stack* stack, int data);
int pop(Stack* stack);
void clearInputBuffer();

#endif /* STACK_H */

