#define _CRT_SECURE_NO_WARNINGS  // 忽略 scanf_s 函数的警告
#include <stdio.h>
#include <stdlib.h>

// 双向链表结点定义
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// 创建新结点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败。\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 在链表尾部插入结点
void append(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    }
    else {
        Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// 判断链表是否成环
int hasCycle(Node* head) {
    Node* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1; // 成环
        }
    }
    return 0; // 无环
}

// 反转链表（非递归）
Node* reverseListIterative(Node* head) {
    Node* prev = NULL, * current = head, * next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    return prev;
}

// 反转链表（递归）
Node* reverseListRecursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* rest = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// 打印链表
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// 释放链表内存
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
//运行时需将01删去
int main01() {
    Node* head = NULL;
    // 用户输入处理
    int choice, data;
    do {
        printf("\n1. 添加\n");
        printf("2. 检查是否有环\n");
        printf("3. 反转链表（迭代）\n");
        printf("4. 反转链表（递归）\n");
        printf("5. 打印链表\n");
        printf("0. 退出\n");
        printf("请输入你的选择：");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("请输入要添加的数据：");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 2:
            if (hasCycle(head))
                printf("该链表有环。\n");
            else
                printf("该链表没有环。\n");
            break;
        case 3:
            head = reverseListIterative(head);
            printf("链表已迭代反转。\n");
            break;
        case 4:
            head = reverseListRecursive(head);
            printf("链表已递归反转。\n");
            break;
        case 5:
            printf("当前链表：");
            printList(head);
            break;
        case 0:
            break;
        default:
            printf("无效的选择。请重试。\n");
        }
    } while (choice != 0);

    freeList(head);
    return 0;
}
