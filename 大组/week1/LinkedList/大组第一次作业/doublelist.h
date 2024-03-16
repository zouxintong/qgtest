#pragma once
#ifndef DOUBLELIST_H
#define DOUBLELIST_H

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data);
void append(Node** headRef, int data);
int hasCycle(Node* head);
Node* reverseListIterative(Node* head);
Node* reverseListRecursive(Node* head);
void printList(Node* head);
void freeList(Node* head);

#endif /* DOUBLELIST_H */