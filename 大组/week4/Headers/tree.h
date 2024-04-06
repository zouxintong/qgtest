#pragma once
#ifndef TREE_H
#define TREE_H
// �������ڵ�ṹ
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// �����½ڵ�
TreeNode* createTreeNode(int key);


// �������
TreeNode* insert(TreeNode* root, int key);

// ���Ҳ���
TreeNode* search(TreeNode* root, int key);

TreeNode* minValueNode(TreeNode* node);
// ɾ������
TreeNode* deleteNode(TreeNode* root, int key);


// ǰ�����򡢺���ݹ�
void preorderTraversal(TreeNode* node);


void inorderTraversal(TreeNode* node);

void postorderTraversal(TreeNode* node);


//�ǵݹ飨ʹ��ջ��


typedef struct StackNode {
    TreeNode* node;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

Stack* createStack();


bool isEmpty(Stack* stack);

void push(Stack* stack, TreeNode* node);
TreeNode* pop(Stack* stack);

void iterativePreorderTraversal(TreeNode* root);

void iterativeInorderTraversal(TreeNode* root);

void iterativePostorderTraversal(TreeNode* root);
// ���������ʹ�ö��У�


typedef struct QueueNode {
    TreeNode* node;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue();

bool isQueueEmpty(Queue* queue);
void enqueue(Queue* queue, TreeNode* node);

TreeNode* dequeue(Queue* queue);

void levelOrderTraversal(TreeNode* root);

// �ѵ���С��
typedef struct MinHeap {
    int* array;
    int size;
    int capacity;
} MinHeap;

// ������С��
MinHeap* createMinHeap(int capacity);

// ����С���в���Ԫ��
void insertMinHeap(MinHeap* minHeap, int key);

// ����С����ɾ��Ԫ�أ�ɾ���Ѷ�Ԫ�أ�
int deleteMinHeap(MinHeap* minHeap);
#endif /* TREE_H */