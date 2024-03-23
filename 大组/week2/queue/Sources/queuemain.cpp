#define _CRT_SECURE_NO_WARNINGS  // ���� scanf_s �����ľ���
#include "lqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    LQueue Q;
    InitLQueue(&Q);

    printf("�������������� (int, float, char): ");
    scanf("%s", datatype);

    if (strcmp(datatype, "int") == 0) {
        type = 'i';
    }
    else if (strcmp(datatype, "float") == 0) {
        type = 'f';
    }
    else if (strcmp(datatype, "char") == 0) {
        type = 'c';
    }
    else {
        printf("��֧�ֵ���������\n");
        return 0;
    }

    int choice;
    do {
        printf("\n1. ���\n2. ����\n3. ��ӡ����Ԫ��\n4. ��ӡ���г���\n5. ��ӡ����\n6. ��ն���\n7. �˳�\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            if (type == 'i') {
                int data;
                printf("������һ������: ");
                scanf("%d", &data);
                int* ptr = (int*)malloc(sizeof(int));
                *ptr = data;
                EnLQueue(&Q, ptr);
            }
            else if (type == 'f') {
                float data;
                printf("������һ��������: ");
                scanf("%f", &data);
                float* ptr = (float*)malloc(sizeof(float));
                *ptr = data;
                EnLQueue(&Q, ptr);
            }
            else {
                char data;
                printf("������һ���ַ�: ");
                scanf(" %c", &data);
                char* ptr = (char*)malloc(sizeof(char));
                *ptr = data;
                EnLQueue(&Q, ptr);
            }
            break;
        }
        case 2:
            if (DeLQueue(&Q))
                printf("�ɹ�����\n");
            else
                printf("����Ϊ��\n");
            break;
        case 3: {
            void* data;
            if (GetHeadLQueue(&Q, &data))
                LPrint(data);
            else
                printf("����Ϊ��\n");
            break;
        }
        case 4:
            printf("���г���: %d\n", LengthLQueue(&Q));
            break;
        case 5:
            TraverseLQueue(&Q, LPrint);
            printf("\n");
            break;
        case 6:
            ClearLQueue(&Q);
            printf("���������\n");
            break;
        case 7:
            DestroyLQueue(&Q);
            printf("�˳�...\n");
            break;
        default:
            printf("��Ч��ѡ��\n");
        }
    } while (choice != 7);

    return 0;
}
