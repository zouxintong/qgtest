#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

// �����½ڵ�
TreeNode* createTreeNode(int key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode) {
        newNode->val = key;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// �������
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

// ���Ҳ���
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
// ɾ������
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
        // �ҵ�Ҫɾ���Ľڵ�
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
        // �������ӽڵ��������ҵ�����������С�ڵ����滻
        TreeNode* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}



// ������������ǰ�����򡢺���ݹ�
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

// ��������ǵݹ飨ʹ��ջ��


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

// ���������ʹ�ö��У�

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



// ������С��
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (int*)malloc(capacity * sizeof(int));
    return minHeap;
}

// ����С���в���Ԫ��
void insertMinHeap(MinHeap* minHeap, int key) {
    if (minHeap->size == minHeap->capacity) {
        printf("���������޷�������Ԫ��\n");
        return;
    }
    // ����Ԫ�ز���ѵ�ĩβ
    minHeap->size++;
    int i = minHeap->size - 1;
    minHeap->array[i] = key;

    // �����ѣ�������С������
    while (i != 0 && minHeap->array[(i - 1) / 2] > minHeap->array[i]) {
        // ������ǰ�ڵ����丸�ڵ�
        int temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        minHeap->array[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// ����С����ɾ��Ԫ�أ�ɾ���Ѷ�Ԫ�أ�
int deleteMinHeap(MinHeap* minHeap) {
    if (minHeap->size == 0) {
        printf("��Ϊ�գ��޷�ɾ��Ԫ��\n");
        return -1; // ��ʾ��Ϊ��
    }
    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->array[0];
    }

    // ���Ѷ�Ԫ���滻Ϊ���һ��Ԫ��
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
            // ������ǰ�ڵ�����С�ӽڵ�
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