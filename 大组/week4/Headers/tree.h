#pragma once
#ifndef TREE_H
#define TREE_H
// 二叉树节点结构
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* createTreeNode(int key);


// 插入操作
TreeNode* insert(TreeNode* root, int key);

// 查找操作
TreeNode* search(TreeNode* root, int key);

TreeNode* minValueNode(TreeNode* node);
// 删除操作
TreeNode* deleteNode(TreeNode* root, int key);


// 前序、中序、后序递归
void preorderTraversal(TreeNode* node);


void inorderTraversal(TreeNode* node);

void postorderTraversal(TreeNode* node);


//非递归（使用栈）


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
// 层序遍历（使用队列）


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

// 堆的最小堆
typedef struct MinHeap {
    int* array;
    int size;
    int capacity;
} MinHeap;

// 创建最小堆
MinHeap* createMinHeap(int capacity);

// 向最小堆中插入元素
void insertMinHeap(MinHeap* minHeap, int key);

// 从最小堆中删除元素（删除堆顶元素）
int deleteMinHeap(MinHeap* minHeap);
#endif /* TREE_H */