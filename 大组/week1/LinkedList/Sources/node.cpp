#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


// �������������ʵ��
Node* createSinglyLinkedList() {
    Node* head = NULL;
    return head;
}

// �������в���ڵ�
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

// �ݹ鷴ת������
Node* reverseListRecursively(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = reverseListRecursively(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// ������ת������
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

// ��ӡ������
void printSinglyLinkedList(Node* head) {
    Node* current = head;
    printf("������: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// �ҵ���������м�ڵ�
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

// �жϵ������Ƿ���ڻ�
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

// ɾ����������ָ��Ԫ�صĽڵ�
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

// ���������е�����λ�ýڵ��ż��λ�ýڵ�ֿ���Ȼ��������һ��
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

// �ڵ������в���ָ��Ԫ��
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

// ����һ��������ѭ��������
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

// �ͷŵ������ڴ�
void freeSinglyLinkedList(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}



// ˫�������������ʵ��
DoubleNode* createDoubleLinkedList() {
    DoubleNode* head = NULL; 
    return head; 
}

// ��˫�������в���ڵ�
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
    // ���½ڵ����ӵ������β��
    current->next = newNode;
    newNode->prev = current;
}

// �ݹ�ط�ת˫������
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

// �����ط�ת˫������
DoubleNode* reverseDoubleListIteratively(DoubleNode* head) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }

    
    DoubleNode* prev = NULL;
    DoubleNode* current = head;

    
    while (current != NULL) {
        // ������ǰ�ڵ��prev��nextָ��
        current->prev = current->next;
        current->next = prev;
        // ����prev��currentָ��
        prev = current;
        current = current->prev;
    }

    return prev; 
}

// ��ӡ˫����������нڵ�ֵ
void printDoubleLinkedList(DoubleNode* head) {
    DoubleNode* current = head;
    printf("˫������: ");
    while (current != NULL) {
        printf("%d ", current->data); 
        current = current->next; // �ƶ�����һ���ڵ�
    }
    printf("\n");
}

// �ҵ�˫��������м�ڵ�
DoubleNode* findDoubleMiddleNode(DoubleNode* head) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // ��ʼ����ָ��Ϳ�ָ��
    DoubleNode* slow = head;
    DoubleNode* fast = head;

    // ʹ�ÿ���ָ�뷨�ҵ��м�ڵ�
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; 
}

// �ж�˫�������Ƿ���ڻ�
int hasDoubleLoop(DoubleNode* head) {
    
    if (head == NULL || head->next == NULL) {
        return 0;
    }

    
    DoubleNode* slow = head;
    DoubleNode* fast = head->next;

    // ʹ�ÿ���ָ�뷨�ж��������Ƿ���ڻ�
    while (slow != fast) {
        
        if (fast == NULL || fast->next == NULL) {
            return 0;
        }
        
        slow = slow->next;
        fast = fast->next->next;
    }

    return 1;
}

// ��˫��������ɾ��ָ��ֵ�Ľڵ�
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

    // �����������Ҫɾ���Ľڵ�
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

    return head; // ����ͷ��ָ��
}

// ��˫�����������λ�ýڵ��ż��λ�ýڵ�ֱ����ӣ������µ�ͷ�ڵ�ָ��
DoubleNode* oddEvenDoubleList(DoubleNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // ��ʼ����ż�ڵ�ָ��
    DoubleNode* odd = head;
    DoubleNode* even = head->next;
    DoubleNode* evenHead = even;
    // ��������������λ�ýڵ��ż��λ�ýڵ�ֱ�����
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

    // �����������ĩβ���ӵ�ż�������ͷ��
    odd->next = evenHead;
    if (evenHead != NULL) {
        evenHead->prev = odd;
    }

    return head;
}

// ��˫�������������ض�ֵ�Ľڵ㣬���ҵ��򷵻�1�����򷵻�0
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

// ����һ��ѭ��˫������������ͷ�ڵ�ָ��
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

// �ͷ�˫����������нڵ��ڴ�ռ�
void freeDoubleLinkedList(DoubleNode** head) {
    DoubleNode* current = *head;
    while (current != NULL) {
        DoubleNode* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

