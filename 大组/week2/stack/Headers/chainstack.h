#pragma once
#ifndef STACK_H
#define STACK_H

//定义链栈的节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//定义链栈结构
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

