#include "doublelist.h"
#include <stdio.h>
#include <stdlib.h>

// 创建新结点
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("内存分配失败。\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 在链表尾部插入结点
void append(Node** headRef, int data)
{
    Node* newNode = createNode(data);
    if (*headRef == NULL)
    {
        *headRef = newNode;
    }
    else
    {
        Node* temp = *headRef;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// 判断链表是否成环
int hasCycle(Node* head)
{
    Node* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1; // 成环
        }
    }
    return 0; // 无环
}

// 反转链表（非递归）
Node* reverseListIterative(Node* head)
{
    Node* prev = NULL, * current = head, * next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    return prev;
}

// 反转链表（递归）
Node* reverseListRecursive(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* rest = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// 打印链表
void printList(Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// 释放链表内存
void freeList(Node* head)
{
    Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}