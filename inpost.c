#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

int isOperand(char c) {
    return ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char c;

    printf("Enter an infix expression (no spaces): ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        c = infix[i];

        if (isOperand(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '\0' && peek() != '(') {
                postfix[k++] = pop();
            }
            if (peek() == '(') {
                pop();
            }
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                if (c == '^' && peek() == '^') {
                    break;
                }
                postfix[k++] = pop();
            }
            push(c);
        }
        i++;
    }

    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

