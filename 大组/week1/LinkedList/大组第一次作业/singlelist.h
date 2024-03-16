#pragma once
#ifndef SINGLELIST_H
#define SINGLELIST_H

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val);
void append(struct ListNode** headRef, int val);
int findMiddle(struct ListNode* head);
int hasCycle(struct ListNode* head);
struct ListNode* reverse(struct ListNode* head);
struct ListNode* recursiveReverse(struct ListNode* head);
struct ListNode* iterativeReverse(struct ListNode* head);
void printList(struct ListNode* head);
void swapOddEven(struct ListNode* head);

#endif /* SINGLELIST_H */

