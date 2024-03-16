#define _CRT_SECURE_NO_WARNINGS  // ���� scanf_s �����ľ���

#include <stdio.h>
#include <stdlib.h>
#include "doublelist.h"

int main()
{
    Node* head = NULL;
    int choice, data;
    do
    {
        printf("\n1. ���\n");
        printf("2. ����Ƿ��л�\n");
        printf("3. ��ת����������\n");
        printf("4. ��ת�����ݹ飩\n");
        printf("5. ��ӡ����\n");
        printf("0. �˳�\n");
        printf("���������ѡ��");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("������Ҫ��ӵ����ݣ�");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 2:
            if (hasCycle(head))
                printf("�������л���\n");
            else
                printf("������û�л���\n");
            break;
        case 3:
            head = reverseListIterative(head);
            printf("�����ѵ�����ת��\n");
            break;
        case 4:
            head = reverseListRecursive(head);
            printf("�����ѵݹ鷴ת��\n");
            break;
        case 5:
            printf("��ǰ����");
            printList(head);
            break;
        case 0:
            break;
        default:
            printf("��Ч��ѡ�������ԡ�\n");
        }
    } while (choice != 0);

    freeList(head);
    return 0;
}

