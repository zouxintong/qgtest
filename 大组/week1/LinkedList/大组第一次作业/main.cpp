#define _CRT_SECURE_NO_WARNINGS  // 忽略 scanf_s 函数的警告
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


int main() {
    Node* singlyHead = NULL;
    DoubleNode* doublyHead = NULL;
    int choice, data;

    while (1) {
        printf("**********************************************************\n");
        printf("*                    选择操作:                            *\n");
        printf("*                    操作结果:                            *\n");
        printf("*  1. 初始化单链表             12. 初始化双向链表         *\n");
        printf("*  2. 插入新节点(单链表)       13. 插入新节点(双向链表)   *\n");
        printf("*  3. 递归反转单链表           14. 递归反转双向链表       *\n");
        printf("*  4. 非递归反转单链表         15. 非递归反转双向链表     *\n");
        printf("*  5. 输出单链表               16. 输出双向链表           *\n");
        printf("*  6. 查找单链表中点           17. 查找双向链表中点       *\n");
        printf("*  7. 判断单链表是否成环       18. 判断双向链表是否成环   *\n");
        printf("*  8. 删除单链表节点           19. 删除双向链表节点       *\n");
        printf("*  9. 单链表节点位置奇偶反转   20. 双向链表节点位置奇偶反转 *\n");
        printf("* 10. 查询单链表               21. 查询双向链表           *\n");
        printf("* 11. 构造单链表循环链表      22. 构造双向链表循环链表   *\n");
        printf("* 23. 退出系统                                           *\n");
        printf("**********************************************************\n");


        printf("输入选择: ");
        scanf("%d", &choice);

        Node* middleNode = NULL; // 初始化middleNode
        DoubleNode* doubleMiddleNode = NULL; // 初始化doubleMiddleNode

        switch (choice) {
        case 1:
            singlyHead = createSinglyLinkedList();
            printf("单链表已初始化\n");
            break;
        case 2:
            printf("输入要插入的数据: ");
            scanf("%d", &data);
            insertNodeSingly(&singlyHead, data);
            break;
            break;
        case 3:
            singlyHead = reverseListRecursively(singlyHead);
            break;
        case 4:
            singlyHead = reverseListIteratively(singlyHead);
            break;
        case 5:
            printSinglyLinkedList(singlyHead);
            break;
        case 6:
            middleNode = findMiddleNode(singlyHead);
            if (middleNode) {
                printf("单链表中点数据: %d\n", middleNode->data);
            }
            else {
                printf("单链表为空\n");
            }
            break;
        case 7:
            if (hasLoop(singlyHead)) {
                printf("单链表存在环\n");
            }
            else {
                printf("单链表不存在环\n");
            }
            break;
        case 8:
            printf("输入要删除的数据: ");
            scanf("%d", &data);
            singlyHead = deleteNode(singlyHead, data);
            break;
        case 9:
            singlyHead = oddEvenList(singlyHead);
            break;
        case 10:
            printf("输入要查询的数据: ");
            scanf("%d", &data);
            if (searchNode(singlyHead, data)) {
                printf("单链表中存在数据 %d\n", data);
            }
            else {
                printf("单链表中不存在数据 %d\n", data);
            }
            break;
        case 11:
            printf("输入要构造循环链表的数据: ");
            scanf("%d", &data);
            singlyHead = createCircularLinkedList(&singlyHead, data);
            break;
        case 12:
            doublyHead = createDoubleLinkedList(); // 初始化双向链表
            printf("双向链表已初始化\n");
            break;
        case 13:
            printf("输入要插入的数据: ");
            scanf("%d", &data);
            insertNodeDoubly(&doublyHead, data);
            break;
        case 14:
            doublyHead = reverseDoubleListRecursively(doublyHead);
            break;
        case 15:
            doublyHead = reverseDoubleListIteratively(doublyHead);
            break;
        case 16:
            printDoubleLinkedList(doublyHead);
            break;
        case 17:
            doubleMiddleNode = findDoubleMiddleNode(doublyHead);
            if (doubleMiddleNode) {
                printf("双向链表中点数据: %d\n", doubleMiddleNode->data);
            }
            else {
                printf("双向链表为空\n");
            }
            break;
        case 18:
            if (hasDoubleLoop(doublyHead)) {
                printf("双向链表存在环\n");
            }
            else {
                printf("双向链表不存在环\n");
            }
            break;
        case 19:
            printf("输入要删除的数据: ");
            scanf("%d", &data);
            doublyHead = deleteDoubleNode(doublyHead, data);
            break;
        case 20:
            doublyHead = oddEvenDoubleList(doublyHead);
            break;
        case 21:
            printf("输入要查询的数据: ");
            scanf("%d", &data);
            if (searchDoubleNode(doublyHead, data)) {
                printf("双向链表中存在数据 %d\n", data);
            }
            else {
                printf("双向链表中不存在数据 %d\n", data);
            }
            break;
        case 22:
            printf("输入要构造循环链表的数据: ");
            scanf("%d", &data);
            doublyHead = createCircularDoubleLinkedList(&doublyHead, data);
            break;
        case 23:
            freeSinglyLinkedList(&singlyHead);
            freeDoubleLinkedList(&doublyHead);
            printf("退出系统\n");
            return 0;
        default:
            printf("无效选择\n");
            break;
        }
    }

    return 0;
}