#define _CRT_SECURE_NO_WARNINGS  // ���� scanf_s �����ľ���
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculator.h"


double evaluateExpression(char* exp);

int main() {
    char expression[100];
    char choice;

    do {
        printf("������һ���������ʽ��");
        fgets(expression, sizeof(expression), stdin);

        double result = evaluateExpression(expression);
        printf("�����%.2f\n", result);

        printf("�Ƿ������Y/N����");
        scanf(" %c", &choice);
        getchar();

    } while (choice == 'Y' || choice == 'y');

    printf("���������\n");
    return 0;
}

double evaluateExpression(char* exp) {
    Stack numStack;
    numStack.top = -1;

    Stack opStack;
    opStack.top = -1;

    while (*exp) {
        if (isdigit(*exp) || *exp == '.') {
            push(&numStack, atof(exp));
            while (isdigit(*exp) || *exp == '.') {
                exp++;
            }
        }
        else if (*exp == '+' || *exp == '-' || *exp == '*' || *exp == '/') {
            while (opStack.top != -1 && ((opStack.items[opStack.top] == '*') || (opStack.items[opStack.top] == '/'))) {
                char op = pop(&opStack);
                double b = pop(&numStack);
                double a = pop(&numStack);
                if (op == '*') {
                    push(&numStack, a * b);
                }
                else {
                    push(&numStack, a / b);
                }
            }
            push(&opStack, *exp);
            exp++;
        }
        else if (*exp == '(') {
            push(&opStack, *exp);
            exp++;
        }
        else if (*exp == ')') {
            while (opStack.items[opStack.top] != '(') {
                char op = pop(&opStack);
                double b = pop(&numStack);
                double a = pop(&numStack);
                switch (op) {
                case '+':
                    push(&numStack, a + b);
                    break;
                case '-':
                    push(&numStack, a - b);
                    break;
                case '*':
                    push(&numStack, a * b);
                    break;
                case '/':
                    push(&numStack, a / b);
                    break;
                }
            }
            pop(&opStack); // ����������
            exp++;
        }
        else {
            exp++; // ���Կո�
        }
    }

    while (opStack.top != -1) {
        char op = pop(&opStack);
        double b = pop(&numStack);
        double a = pop(&numStack);
        switch (op) {
        case '+':
            push(&numStack, a + b);
            break;
        case '-':
            push(&numStack, a - b);
            break;
        case '*':
            push(&numStack, a * b);
            break;
        case '/':
            push(&numStack, a / b);
            break;
        }
    }

    return pop(&numStack);
}