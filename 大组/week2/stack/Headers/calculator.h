#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    double items[MAX_STACK_SIZE];
} Stack;

void push(Stack* s, double value);
double pop(Stack* s);

#endif /* CALCULATOR_H */