#define _CRT_SECURE_NO_WARNINGS  // 忽略 scanf_s 函数的警告
#include <stdio.h>
#include <stdlib.h>
#include "chainstack.h"

int main() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    initStack(stack);
    int choice, data;

    printf("链栈功能演示\n");

    while (1) {
        printf("\n1. 入栈\n2. 出栈\n3. 获取栈顶元素\n4. 清空栈\n5. 销毁栈\n6. 检测栈长度\n7. 退出\n");
        printf("请选择操作: ");

        // 检查用户输入是否为数字
        if (scanf("%d", &choice) != 1) {
            printf("输入错误，请重新输入\n");
            clearInputBuffer(); // 清理输入缓冲区
            continue;
        }

        switch (choice) {
        case 1:
            printf("请输入要入栈的数据: ");
            if (scanf("%d", &data) != 1) {
                printf("输入错误，请重新输入\n");
                clearInputBuffer();
                break;
            }
            push(stack, data);
            break;
        case 2:
            data = pop(stack);
            if (data != -1)
                printf("出栈元素: %d\n", data);
            break;
        case 3:
            printf("栈顶元素为: %d\n", top(stack));
            break;
        case 4:
            clearStack(stack);
            break;
        case 5:
            destroyStack(stack);
            return 0;
        case 6:
            printf("栈长度为: %d\n", stackLength(stack));
            break;
        case 7:
            printf("程序退出\n");
            destroyStack(stack);
            return 0;
        default:
            printf("无效选择\n");
        }
    }

    return 0;
}

