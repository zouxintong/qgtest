#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
// ������ڵ�ṹ��
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ˫������ڵ�ṹ��
typedef struct DoubleNode {
    int data;
    struct DoubleNode* prev;
    struct DoubleNode* next;
} DoubleNode;

// �����������������
Node* createSinglyLinkedList();
void insertNodeSingly(Node** head, int data);
Node* reverseListRecursively(Node* head);
Node* reverseListIteratively(Node* head);
void printSinglyLinkedList(Node* head);
Node* findMiddleNode(Node* head);
int hasLoop(Node* head);
Node* deleteNode(Node* head, int data);
Node* oddEvenList(Node* head);
int searchNode(Node* head, int data);
Node* createCircularLinkedList(Node** head, int data);
void freeSinglyLinkedList(Node** head);

// ˫�����������������
DoubleNode* createDoubleLinkedList();
void insertNodeDoubly(DoubleNode** head, int data);
DoubleNode* reverseDoubleListRecursively(DoubleNode* head);
DoubleNode* reverseDoubleListIteratively(DoubleNode* head);
void printDoubleLinkedList(DoubleNode* head);
DoubleNode* findDoubleMiddleNode(DoubleNode* head);
int hasDoubleLoop(DoubleNode* head);
DoubleNode* deleteDoubleNode(DoubleNode* head, int data);
DoubleNode* oddEvenDoubleList(DoubleNode* head);
int searchDoubleNode(DoubleNode* head, int data);
DoubleNode* createCircularDoubleLinkedList(DoubleNode** head, int data);
void freeDoubleLinkedList(DoubleNode** head);
#endif /* LINKEDLIST_H */