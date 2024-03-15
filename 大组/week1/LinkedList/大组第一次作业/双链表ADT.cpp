#define _CRT_SECURE_NO_WARNINGS  // ���� scanf_s �����ľ���
#include <stdio.h>
#include <stdlib.h>

// ˫�������㶨��
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// �����½��
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ�ܡ�\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// ������β��������
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

// �ж������Ƿ�ɻ�
int hasCycle(Node* head) {
    Node* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1; // �ɻ�
        }
    }
    return 0; // �޻�
}

// ��ת�����ǵݹ飩
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

// ��ת�����ݹ飩
Node* reverseListRecursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* rest = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// ��ӡ����
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// �ͷ������ڴ�
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
//����ʱ�轫01ɾȥ
int main01() {
    Node* head = NULL;
    // �û����봦��
    int choice, data;
    do {
        printf("\n1. ���\n");
        printf("2. ����Ƿ��л�\n");
        printf("3. ��ת����������\n");
        printf("4. ��ת�����ݹ飩\n");
        printf("5. ��ӡ����\n");
        printf("0. �˳�\n");
        printf("���������ѡ��");
        scanf("%d", &choice);
        switch (choice) {
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
