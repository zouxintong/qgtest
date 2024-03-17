#define _CRT_SECURE_NO_WARNINGS  // ���� scanf_s �����ľ���
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


int main() {
    Node* singlyHead = NULL;
    DoubleNode* doublyHead = NULL;
    int choice, data;

    while (1) {
        printf("**********************************************************\n");
        printf("*                    ѡ�����:                            *\n");
        printf("*                    �������:                            *\n");
        printf("*  1. ��ʼ��������             12. ��ʼ��˫������         *\n");
        printf("*  2. �����½ڵ�(������)       13. �����½ڵ�(˫������)   *\n");
        printf("*  3. �ݹ鷴ת������           14. �ݹ鷴ת˫������       *\n");
        printf("*  4. �ǵݹ鷴ת������         15. �ǵݹ鷴ת˫������     *\n");
        printf("*  5. ���������               16. ���˫������           *\n");
        printf("*  6. ���ҵ������е�           17. ����˫�������е�       *\n");
        printf("*  7. �жϵ������Ƿ�ɻ�       18. �ж�˫�������Ƿ�ɻ�   *\n");
        printf("*  8. ɾ��������ڵ�           19. ɾ��˫������ڵ�       *\n");
        printf("*  9. ������ڵ�λ����ż��ת   20. ˫������ڵ�λ����ż��ת *\n");
        printf("* 10. ��ѯ������               21. ��ѯ˫������           *\n");
        printf("* 11. ���쵥����ѭ������      22. ����˫������ѭ������   *\n");
        printf("* 23. �˳�ϵͳ                                           *\n");
        printf("**********************************************************\n");


        printf("����ѡ��: ");
        scanf("%d", &choice);

        Node* middleNode = NULL; // ��ʼ��middleNode
        DoubleNode* doubleMiddleNode = NULL; // ��ʼ��doubleMiddleNode

        switch (choice) {
        case 1:
            singlyHead = createSinglyLinkedList();
            printf("�������ѳ�ʼ��\n");
            break;
        case 2:
            printf("����Ҫ���������: ");
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
                printf("�������е�����: %d\n", middleNode->data);
            }
            else {
                printf("������Ϊ��\n");
            }
            break;
        case 7:
            if (hasLoop(singlyHead)) {
                printf("��������ڻ�\n");
            }
            else {
                printf("���������ڻ�\n");
            }
            break;
        case 8:
            printf("����Ҫɾ��������: ");
            scanf("%d", &data);
            singlyHead = deleteNode(singlyHead, data);
            break;
        case 9:
            singlyHead = oddEvenList(singlyHead);
            break;
        case 10:
            printf("����Ҫ��ѯ������: ");
            scanf("%d", &data);
            if (searchNode(singlyHead, data)) {
                printf("�������д������� %d\n", data);
            }
            else {
                printf("�������в��������� %d\n", data);
            }
            break;
        case 11:
            printf("����Ҫ����ѭ�����������: ");
            scanf("%d", &data);
            singlyHead = createCircularLinkedList(&singlyHead, data);
            break;
        case 12:
            doublyHead = createDoubleLinkedList(); // ��ʼ��˫������
            printf("˫�������ѳ�ʼ��\n");
            break;
        case 13:
            printf("����Ҫ���������: ");
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
                printf("˫�������е�����: %d\n", doubleMiddleNode->data);
            }
            else {
                printf("˫������Ϊ��\n");
            }
            break;
        case 18:
            if (hasDoubleLoop(doublyHead)) {
                printf("˫��������ڻ�\n");
            }
            else {
                printf("˫���������ڻ�\n");
            }
            break;
        case 19:
            printf("����Ҫɾ��������: ");
            scanf("%d", &data);
            doublyHead = deleteDoubleNode(doublyHead, data);
            break;
        case 20:
            doublyHead = oddEvenDoubleList(doublyHead);
            break;
        case 21:
            printf("����Ҫ��ѯ������: ");
            scanf("%d", &data);
            if (searchDoubleNode(doublyHead, data)) {
                printf("˫�������д������� %d\n", data);
            }
            else {
                printf("˫�������в��������� %d\n", data);
            }
            break;
        case 22:
            printf("����Ҫ����ѭ�����������: ");
            scanf("%d", &data);
            doublyHead = createCircularDoubleLinkedList(&doublyHead, data);
            break;
        case 23:
            freeSinglyLinkedList(&singlyHead);
            freeDoubleLinkedList(&doublyHead);
            printf("�˳�ϵͳ\n");
            return 0;
        default:
            printf("��Чѡ��\n");
            break;
        }
    }

    return 0;
}