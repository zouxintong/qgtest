#define _CRT_SECURE_NO_WARNINGS  // ���� scanf_s �����ľ���
#include <stdio.h>
#include <stdlib.h>
#include "singlelist.h"

int main01() {
    struct ListNode* head = NULL;

    // ���û����봴������
    int size;
    printf("����������Ĵ�С��");
    scanf("%d", &size);
    printf("����������Ԫ�أ��Կո�ָ���");
    for (int i = 0; i < size; ++i) {
        int val;
        scanf("%d", &val);
        append(&head, val);
    }

    // ��ӡԭʼ����
    printf("ԭʼ����\n");
    printList(head);

    // ��������ż����
    swapOddEven(head);
    printf("��������ż������\n");
    printList(head);

    // �ҵ���������е�
    int middle = findMiddle(head);
    printf("��������е㣺%d\n", middle);

    // �ж������Ƿ�ɻ�
    int hasCycleResult = hasCycle(head);
    printf("�����Ƿ�ɻ���%s\n", hasCycleResult ? "��" : "��");

    // ��ת����
    head = reverse(head);
    printf("��ת�����\n");
    printList(head);

    // �ݹ鷴ת����
    head = recursiveReverse(head);
    printf("�ݹ鷴ת�����\n");
    printList(head);

    // �ǵݹ鷴ת����
    head = iterativeReverse(head);
    printf("�ǵݹ鷴ת�����\n");
    printList(head);

    return 0;
}
