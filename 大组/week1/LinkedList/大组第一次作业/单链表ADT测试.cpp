#define _CRT_SECURE_NO_WARNINGS  // 忽略 scanf_s 函数的警告
#include <stdio.h>
#include <stdlib.h>
#include "singlelist.h"

int main01() {
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
