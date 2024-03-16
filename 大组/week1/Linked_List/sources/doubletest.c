#include <stdio.h>
#include <stdlib.h>
#include "../Headers/doublelist.h"

int main()
{
    Node *head = NULL;
    int choice, data;
    do
    {
        printf("\n1. 添加\n");
        printf("2. 检查是否有环\n");
        printf("3. 反转链表（迭代）\n");
        printf("4. 反转链表（递归）\n");
        printf("5. 打印链表\n");
        printf("0. 退出\n");
        printf("请输入你的选择：");
        scanf("%d", &choice);
        switch (choice)
        {
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
