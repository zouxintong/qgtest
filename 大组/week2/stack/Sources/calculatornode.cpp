#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>

// ջ�Ĳ�������
void push(Stack* s, double value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("ջ���\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

double pop(Stack* s) {
    if (s->top == -1) {
        printf("ջ����\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}
