#define _CRT_SECURE_NO_WARNINGS  // ���� scanf_s �����ľ���
#include <stdio.h>
#include <stdlib.h>
#include "chainstack.h"

int main() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("�ڴ����ʧ��\n");
        return 1;
    }
    initStack(stack);
    int choice, data;

    printf("��ջ������ʾ\n");

    while (1) {
        printf("\n1. ��ջ\n2. ��ջ\n3. ��ȡջ��Ԫ��\n4. ���ջ\n5. ����ջ\n6. ���ջ����\n7. �˳�\n");
        printf("��ѡ�����: ");

        // ����û������Ƿ�Ϊ����
        if (scanf("%d", &choice) != 1) {
            printf("�����������������\n");
            clearInputBuffer(); // �������뻺����
            continue;
        }

        switch (choice) {
        case 1:
            printf("������Ҫ��ջ������: ");
            if (scanf("%d", &data) != 1) {
                printf("�����������������\n");
                clearInputBuffer();
                break;
            }
            push(stack, data);
            break;
        case 2:
            data = pop(stack);
            if (data != -1)
                printf("��ջԪ��: %d\n", data);
            break;
        case 3:
            printf("ջ��Ԫ��Ϊ: %d\n", top(stack));
            break;
        case 4:
            clearStack(stack);
            break;
        case 5:
            destroyStack(stack);
            return 0;
        case 6:
            printf("ջ����Ϊ: %d\n", stackLength(stack));
            break;
        case 7:
            printf("�����˳�\n");
            destroyStack(stack);
            return 0;
        default:
            printf("��Чѡ��\n");
        }
    }

    return 0;
}

