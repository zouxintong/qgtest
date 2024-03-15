#define _CRT_SECURE_NO_WARNINGS  // 忽略 scanf_s 函数的警告

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode {
    int val;
    struct ListNode* next;
};

// 创建链表节点
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 向链表尾部添加节点
void append(struct ListNode** headRef, int val) {
    struct ListNode* newNode = createNode(val);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct ListNode* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// 从数组创建链表
struct ListNode* fromArray(int* arr, int size) {
    struct ListNode* head = NULL;
    for (int i = 0; i < size; ++i) {
        append(&head, arr[i]);
    }
    return head;
}

// 打印链表
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// 单链表奇偶调换
void swapOddEven(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL && current->next != NULL) {
        int temp = current->val;
        current->val = current->next->val;
        current->next->val = temp;
        current = current->next->next;
    }
}

// 找到单链表的中点
int findMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

// 判断链表是否成环
int hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

// 反转链表
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

// 递归反转链表
struct ListNode* recursiveReverse(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
// 非递归反转链表
struct ListNode* iterativeReverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

// 主函数
int main() {
    struct ListNode* head = NULL;

    // 从用户输入创建链表
    int size;
    printf("请输入链表的大小：");
    scanf("%d", &size);
    printf("请输入链表元素，以空格分隔：");
    for (int i = 0; i < size; ++i) {
        int val;
        scanf("%d", &val);
        append(&head, val);
    }

    // 打印原始链表
    printf("原始链表：\n");
    printList(head);

    // 单链表奇偶调换
    swapOddEven(head);
    printf("单链表奇偶调换后：\n");
    printList(head);

    // 找到单链表的中点
    int middle = findMiddle(head);
    printf("单链表的中点：%d\n", middle);

    // 判断链表是否成环
    int hasCycleResult = hasCycle(head);
    printf("链表是否成环：%s\n", hasCycleResult ? "是" : "否");

    // 反转链表
    head = reverse(head);
    printf("反转链表后：\n");
    printList(head);

    // 递归反转链表
    head = recursiveReverse(head);
    printf("递归反转链表后：\n");
    printList(head);
    // 非递归反转链表
    head = iterativeReverse(head);
    printf("非递归反转链表后：\n");
    printList(head);

    return 0;
}
