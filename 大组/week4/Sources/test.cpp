#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"





int getUserInput() {
    int input;
    printf("请输入一个整数：");
    scanf("%d", &input);
    return input;
}

int main() {
    TreeNode* root = NULL;
    MinHeap* minHeap = createMinHeap(100); 

    int choice;
    do {
        printf("\n二叉排序树操作选项：\n");
        printf("1. 插入节点\n");
        printf("2. 查找节点\n");
        printf("3. 删除节点\n");
        printf("4. 前序遍历（递归）\n");
        printf("5. 中序遍历（递归）\n");
        printf("6. 后序遍历（递归）\n");
        printf("7. 前序遍历（非递归）\n");
        printf("8. 中序遍历（非递归）\n");
        printf("9. 后序遍历（非递归）\n");
        printf("10. 层序遍历\n");
        printf("11. 插入最小堆\n");
        printf("12. 删除最小堆顶元素\n");
        printf("13. 退出\n");

        printf("请选择操作：");
        scanf(" %d", &choice);

        int key;
        TreeNode* result;
        switch (choice) {
        case 1: // 插入节点
            key = getUserInput();
            root = insert(root, key);
            printf("节点 %d 插入成功！\n", key);
            break;
        case 2: // 查找节点
            key = getUserInput();
            result = search(root, key);
            if (result != NULL) {
                printf("找到节点 %d\n", key);
            }
            else {
                printf("未找到节点 %d\n", key);
            }
            break;
        case 3: // 删除节点
            key = getUserInput();
            root = deleteNode(root, key);
            printf("节点 %d 删除成功！\n", key);
            break;
        case 4: // 前序遍历（递归）
            printf("前序遍历结果：");
            preorderTraversal(root);
            printf("\n");
            break;
        case 5: // 中序遍历（递归）
            printf("中序遍历结果：");
            inorderTraversal(root);
            printf("\n");
            break;
        case 6: // 后序遍历（递归）
            printf("后序遍历结果：");
            postorderTraversal(root);
            printf("\n");
            break;
        case 7: // 前序遍历（非递归）
            printf("前序遍历结果（非递归）：");
            iterativePreorderTraversal(root);
            printf("\n");
            break;
        case 8: // 中序遍历（非递归）
            printf("中序遍历结果（非递归）：");
            iterativeInorderTraversal(root);
            printf("\n");
            break;
        case 9: // 后序遍历（非递归）
            printf("后序遍历结果（非递归）：");
            iterativePostorderTraversal(root);
            printf("\n");
            break;
        case 10: // 层序遍历
            printf("层序遍历结果：");
            levelOrderTraversal(root);
            printf("\n");
            break;
        case 11: // 插入最小堆
            key = getUserInput();
            insertMinHeap(minHeap, key);
            printf("元素 %d 插入最小堆成功！\n", key);
            break;
        case 12: // 删除最小堆顶元素
            if (minHeap->size > 0) {
                int minValue = deleteMinHeap(minHeap);
                printf("最小堆顶元素 %d 删除成功！\n", minValue);
            }
            else {
                printf("最小堆为空，无法删除元素！\n");
            }
            break;
        case 13: 
            printf("程序已退出。\n");
            return 0;
        default:
            printf("无效的操作选项，请重新选择。\n");
            break;
        }

    } while (choice != 13);

    free(minHeap->array);
    free(minHeap);

    return 0;
}
