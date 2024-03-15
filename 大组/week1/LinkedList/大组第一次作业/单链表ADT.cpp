#define _CRT_SECURE_NO_WARNINGS  // ���� scanf_s �����ľ���

#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
struct ListNode {
    int val;
    struct ListNode* next;
};

// ��������ڵ�
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// ������β����ӽڵ�
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

// �����鴴������
struct ListNode* fromArray(int* arr, int size) {
    struct ListNode* head = NULL;
    for (int i = 0; i < size; ++i) {
        append(&head, arr[i]);
    }
    return head;
}

// ��ӡ����
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// ��������ż����
void swapOddEven(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL && current->next != NULL) {
        int temp = current->val;
        current->val = current->next->val;
        current->next->val = temp;
        current = current->next->next;
    }
}

// �ҵ���������е�
int findMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

// �ж������Ƿ�ɻ�
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

// ��ת����
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

// �ݹ鷴ת����
struct ListNode* recursiveReverse(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
// �ǵݹ鷴ת����
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

// ������
int main() {
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
