#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

// 创建新节点
TreeNode* createTreeNode(int key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode) {
        newNode->val = key;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// 插入操作
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return createTreeNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    }
    else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    return root;
}

// 查找操作
TreeNode* search(TreeNode* root, int key) {
    if (root == NULL || root->val == key) {
        return root;
    }
    if (key < root->val) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
// 删除操作
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // 找到要删除的节点
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // 有两个子节点的情况，找到右子树的最小节点来替换
        TreeNode* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}



// 二叉树遍历：前序、中序、后序递归
void preorderTraversal(TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->val);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void inorderTraversal(TreeNode* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->val);
        inorderTraversal(node->right);
    }
}

void postorderTraversal(TreeNode* node) {
    if (node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%d ", node->val);
    }
}

// 三序遍历非递归（使用栈）


Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, TreeNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->node = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

TreeNode* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    StackNode* temp = stack->top;
    TreeNode* poppedNode = temp->node;
    stack->top = temp->next;
    free(temp);
    return poppedNode;
}

void iterativePreorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    Stack* stack = createStack();
    push(stack, root);
    while (!isEmpty(stack)) {
        TreeNode* node = pop(stack);
        printf("%d ", node->val);
        if (node->right) {
            push(stack, node->right);
        }
        if (node->left) {
            push(stack, node->left);
        }
    }
}

void iterativeInorderTraversal(TreeNode* root) {
    Stack* stack = createStack();
    TreeNode* current = root;
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d ", current->val);
        current = current->right;
    }
}

void iterativePostorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    Stack* stack1 = createStack();
    Stack* stack2 = createStack();
    push(stack1, root);
    while (!isEmpty(stack1)) {
        TreeNode* node = pop(stack1);
        push(stack2, node);
        if (node->left) {
            push(stack1, node->left);
        }
        if (node->right) {
            push(stack1, node->right);
        }
    }
    while (!isEmpty(stack2)) {
        TreeNode* node = pop(stack2);
        printf("%d ", node->val);
    }
}

// 层序遍历（使用队列）

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, TreeNode* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

TreeNode* dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    TreeNode* dequeuedNode = temp->node;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return dequeuedNode;
}

void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    Queue* queue = createQueue();
    enqueue(queue, root);
    while (!isQueueEmpty(queue)) {
        TreeNode* node = dequeue(queue);
        printf("%d ", node->val);
        if (node->left) {
            enqueue(queue, node->left);
        }
        if (node->right) {
            enqueue(queue, node->right);
        }
    }
}



// 创建最小堆
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (int*)malloc(capacity * sizeof(int));
    return minHeap;
}

// 向最小堆中插入元素
void insertMinHeap(MinHeap* minHeap, int key) {
    if (minHeap->size == minHeap->capacity) {
        printf("堆已满，无法插入新元素\n");
        return;
    }
    // 将新元素插入堆的末尾
    minHeap->size++;
    int i = minHeap->size - 1;
    minHeap->array[i] = key;

    // 调整堆，保持最小堆性质
    while (i != 0 && minHeap->array[(i - 1) / 2] > minHeap->array[i]) {
        // 交换当前节点与其父节点
        int temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        minHeap->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// 从最小堆中删除元素（删除堆顶元素）
int deleteMinHeap(MinHeap* minHeap) {
    if (minHeap->size == 0) {
        printf("堆为空，无法删除元素\n");
        return -1; // 表示堆为空
    }
    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->array[0];
    }

    // 将堆顶元素替换为最后一个元素
    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;

    
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest]) {
            smallest = left;
        }
        if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            // 交换当前节点与最小子节点
            int temp = minHeap->array[i];
            minHeap->array[i] = minHeap->array[smallest];
            minHeap->array[smallest] = temp;
            i = smallest;
        }
        else {
            break;
        }
    }

    return root;
}