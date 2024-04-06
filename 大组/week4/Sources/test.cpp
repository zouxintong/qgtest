#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"





int getUserInput() {
    int input;
    printf("������һ��������");
    scanf("%d", &input);
    return input;
}

int main() {
    TreeNode* root = NULL;
    MinHeap* minHeap = createMinHeap(100); 

    int choice;
    do {
        printf("\n��������������ѡ�\n");
        printf("1. ����ڵ�\n");
        printf("2. ���ҽڵ�\n");
        printf("3. ɾ���ڵ�\n");
        printf("4. ǰ��������ݹ飩\n");
        printf("5. ����������ݹ飩\n");
        printf("6. ����������ݹ飩\n");
        printf("7. ǰ��������ǵݹ飩\n");
        printf("8. ����������ǵݹ飩\n");
        printf("9. ����������ǵݹ飩\n");
        printf("10. �������\n");
        printf("11. ������С��\n");
        printf("12. ɾ����С�Ѷ�Ԫ��\n");
        printf("13. �˳�\n");

        printf("��ѡ�������");
        scanf(" %d", &choice);

        int key;
        TreeNode* result;
        switch (choice) {
        case 1: // ����ڵ�
            key = getUserInput();
            root = insert(root, key);
            printf("�ڵ� %d ����ɹ���\n", key);
            break;
        case 2: // ���ҽڵ�
            key = getUserInput();
            result = search(root, key);
            if (result != NULL) {
                printf("�ҵ��ڵ� %d\n", key);
            }
            else {
                printf("δ�ҵ��ڵ� %d\n", key);
            }
            break;
        case 3: // ɾ���ڵ�
            key = getUserInput();
            root = deleteNode(root, key);
            printf("�ڵ� %d ɾ���ɹ���\n", key);
            break;
        case 4: // ǰ��������ݹ飩
            printf("ǰ����������");
            preorderTraversal(root);
            printf("\n");
            break;
        case 5: // ����������ݹ飩
            printf("������������");
            inorderTraversal(root);
            printf("\n");
            break;
        case 6: // ����������ݹ飩
            printf("������������");
            postorderTraversal(root);
            printf("\n");
            break;
        case 7: // ǰ��������ǵݹ飩
            printf("ǰ�����������ǵݹ飩��");
            iterativePreorderTraversal(root);
            printf("\n");
            break;
        case 8: // ����������ǵݹ飩
            printf("�������������ǵݹ飩��");
            iterativeInorderTraversal(root);
            printf("\n");
            break;
        case 9: // ����������ǵݹ飩
            printf("�������������ǵݹ飩��");
            iterativePostorderTraversal(root);
            printf("\n");
            break;
        case 10: // �������
            printf("������������");
            levelOrderTraversal(root);
            printf("\n");
            break;
        case 11: // ������С��
            key = getUserInput();
            insertMinHeap(minHeap, key);
            printf("Ԫ�� %d ������С�ѳɹ���\n", key);
            break;
        case 12: // ɾ����С�Ѷ�Ԫ��
            if (minHeap->size > 0) {
                int minValue = deleteMinHeap(minHeap);
                printf("��С�Ѷ�Ԫ�� %d ɾ���ɹ���\n", minValue);
            }
            else {
                printf("��С��Ϊ�գ��޷�ɾ��Ԫ�أ�\n");
            }
            break;
        case 13: 
            printf("�������˳���\n");
            return 0;
        default:
            printf("��Ч�Ĳ���ѡ�������ѡ��\n");
            break;
        }

    } while (choice != 13);

    free(minHeap->array);
    free(minHeap);

    return 0;
}
