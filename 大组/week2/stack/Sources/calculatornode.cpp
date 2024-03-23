#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>

// 栈的操作函数
void push(Stack* s, double value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("栈溢出\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

double pop(Stack* s) {
    if (s->top == -1) {
        printf("栈下溢\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}
