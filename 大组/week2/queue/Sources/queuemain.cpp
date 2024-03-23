#define _CRT_SECURE_NO_WARNINGS  // 忽略 scanf_s 函数的警告
#include "lqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    LQueue Q;
    InitLQueue(&Q);

    printf("请输入数据类型 (int, float, char): ");
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
        printf("不支持的数据类型\n");
        return 0;
    }

    int choice;
    do {
        printf("\n1. 入队\n2. 出队\n3. 打印队首元素\n4. 打印队列长度\n5. 打印队列\n6. 清空队列\n7. 退出\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            if (type == 'i') {
                int data;
                printf("请输入一个整数: ");
                scanf("%d", &data);
                int* ptr = (int*)malloc(sizeof(int));
                *ptr = data;
                EnLQueue(&Q, ptr);
            }
            else if (type == 'f') {
                float data;
                printf("请输入一个浮点数: ");
                scanf("%f", &data);
                float* ptr = (float*)malloc(sizeof(float));
                *ptr = data;
                EnLQueue(&Q, ptr);
            }
            else {
                char data;
                printf("请输入一个字符: ");
                scanf(" %c", &data);
                char* ptr = (char*)malloc(sizeof(char));
                *ptr = data;
                EnLQueue(&Q, ptr);
            }
            break;
        }
        case 2:
            if (DeLQueue(&Q))
                printf("成功出队\n");
            else
                printf("队列为空\n");
            break;
        case 3: {
            void* data;
            if (GetHeadLQueue(&Q, &data))
                LPrint(data);
            else
                printf("队列为空\n");
            break;
        }
        case 4:
            printf("队列长度: %d\n", LengthLQueue(&Q));
            break;
        case 5:
            TraverseLQueue(&Q, LPrint);
            printf("\n");
            break;
        case 6:
            ClearLQueue(&Q);
            printf("队列已清空\n");
            break;
        case 7:
            DestroyLQueue(&Q);
            printf("退出...\n");
            break;
        default:
            printf("无效的选择\n");
        }
    } while (choice != 7);

    return 0;
}
