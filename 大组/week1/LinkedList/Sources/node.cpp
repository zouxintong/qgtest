#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


// 单链表操作函数实现
Node* createSinglyLinkedList() {
    Node* head = NULL;
    return head;
}

// 向单链表中插入节点
void insertNodeSingly(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// 递归反转单链表
Node* reverseListRecursively(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = reverseListRecursively(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// 迭代反转单链表
Node* reverseListIteratively(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// 打印单链表
void printSinglyLinkedList(Node* head) {
    Node* current = head;
    printf("单链表: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 找到单链表的中间节点
Node* findMiddleNode(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// 判断单链表是否存在环
int hasLoop(Node* head) {
    if (head == NULL || head->next == NULL) {
        return 0;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return 0;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return 1;
}

// 删除单链表中指定元素的节点
Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            break;
        }
        current = current->next;
    }

    return head;
}

// 将单链表中的奇数位置节点和偶数位置节点分开，然后连接在一起
Node* oddEvenList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

// 在单链表中查找指定元素
int searchNode(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// 创建一个带环的循环单链表
Node* createCircularLinkedList(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;

    if (*head == NULL) {
        *head = newNode;
        return *head;
    }

    Node* current = *head;
    while (current->next != *head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = *head;

    return *head;
}

// 释放单链表内存
void freeSinglyLinkedList(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}



// 双向链表操作函数实现
DoubleNode* createDoubleLinkedList() {
    DoubleNode* head = NULL; 
    return head; 
}

// 向双向链表中插入节点
void insertNodeDoubly(DoubleNode** head, int data) {
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    DoubleNode* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    // 将新节点连接到链表的尾部
    current->next = newNode;
    newNode->prev = current;
}

// 递归地反转双向链表
DoubleNode* reverseDoubleListRecursively(DoubleNode* head) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }

   
    DoubleNode* newHead = reverseDoubleListRecursively(head->next);
    
    head->next->next = head;
    head->next = NULL;
    head->prev = head->next;

    return newHead; 
}

// 迭代地反转双向链表
DoubleNode* reverseDoubleListIteratively(DoubleNode* head) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }

    
    DoubleNode* prev = NULL;
    DoubleNode* current = head;

    
    while (current != NULL) {
        // 交换当前节点的prev和next指针
        current->prev = current->next;
        current->next = prev;
        // 更新prev和current指针
        prev = current;
        current = current->prev;
    }

    return prev; 
}

// 打印双向链表的所有节点值
void printDoubleLinkedList(DoubleNode* head) {
    DoubleNode* current = head;
    printf("双向链表: ");
    while (current != NULL) {
        printf("%d ", current->data); 
        current = current->next; // 移动到下一个节点
    }
    printf("\n");
}

// 找到双向链表的中间节点
DoubleNode* findDoubleMiddleNode(DoubleNode* head) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // 初始化慢指针和快指针
    DoubleNode* slow = head;
    DoubleNode* fast = head;

    // 使用快慢指针法找到中间节点
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; 
}

// 判断双向链表是否存在环
int hasDoubleLoop(DoubleNode* head) {
    
    if (head == NULL || head->next == NULL) {
        return 0;
    }

    
    DoubleNode* slow = head;
    DoubleNode* fast = head->next;

    // 使用快慢指针法判断链表中是否存在环
    while (slow != fast) {
        
        if (fast == NULL || fast->next == NULL) {
            return 0;
        }
        
        slow = slow->next;
        fast = fast->next->next;
    }

    return 1;
}

// 从双向链表中删除指定值的节点
DoubleNode* deleteDoubleNode(DoubleNode* head, int data) {
    
    if (head == NULL) {
        return NULL;
    }

   
    if (head->data == data) {
        
        DoubleNode* temp = head;
        head = head->next;
        
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head; 
   }

    // 遍历链表查找要删除的节点
    DoubleNode* current = head;
    while (current->next != NULL) {
        
        if (current->next->data == data) {
            
            DoubleNode* temp = current->next;
            
            if (temp->next != NULL) {
                temp->next->prev = current;
            }
           
            current->next = temp->next;
            free(temp);
            break;
        }
        current = current->next; 
    }

    return head; // 返回头部指针
}

// 将双向链表的奇数位置节点和偶数位置节点分别连接，返回新的头节点指针
DoubleNode* oddEvenDoubleList(DoubleNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // 初始化奇偶节点指针
    DoubleNode* odd = head;
    DoubleNode* even = head->next;
    DoubleNode* evenHead = even;
    // 遍历链表，将奇数位置节点和偶数位置节点分别连接
    while (even != NULL && even->next != NULL) {
       
        odd->next = even->next;
        odd->next->prev = odd;
        odd = odd->next;
        
        even->next = odd->next;
        if (even->next != NULL) {
            even->next->prev = even;
        }
        even = even->next;
    }

    // 将奇数链表的末尾连接到偶数链表的头部
    odd->next = evenHead;
    if (evenHead != NULL) {
        evenHead->prev = odd;
    }

    return head;
}

// 在双向链表中搜索特定值的节点，若找到则返回1，否则返回0
int searchDoubleNode(DoubleNode* head, int data) {
    DoubleNode* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1; 
        }
        current = current->next;
    }
    return 0; 
}

// 创建一个循环双向链表，并返回头节点指针
DoubleNode* createCircularDoubleLinkedList(DoubleNode** head, int data) {
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;

    if (*head == NULL) {
        
        *head = newNode;
        return *head;
    }

   
    DoubleNode* current = *head;
    while (current->next != *head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    newNode->next = *head;
    (*head)->prev = newNode;

    return *head;
}

// 释放双向链表的所有节点内存空间
void freeDoubleLinkedList(DoubleNode** head) {
    DoubleNode* current = *head;
    while (current != NULL) {
        DoubleNode* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

