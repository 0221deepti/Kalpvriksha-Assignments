#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;
// define top value as -1
void initStack(Stack *s) {
    s->top = -1;
}

// push function
void push(Stack *s, int value) {
    if (s->top >= MAX - 1) {
        printf("stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

// pop function
int pop(Stack *s) {
    if (s->top == -1) {
        printf("stack underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// peek function
int peek(Stack *s) {
    if (s->top == -1) {
        return -1; // if stack is empty
    }
    return s->items[s->top];
}

// for operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to perform arithmetic operations
int applyOperation(int a, int b, char operator) {
    switch (operator) {
        case '+':return a + b;
        case '-':return a - b;
        case '*':return a * b;
        case '/':
            if (b == 0) {
                printf("Division by zero\n");
            }
            return a/b;
        default:
            return 0;
    }
}
// checking
int evaluateExpression(char *exp) {
    Stack values, ops;
    initStack(&values);
    initStack(&ops);

    int i = 0;
    while (exp[i] != '\0') {
        // remove space
        if (isspace(exp[i])) {
            i++;
            continue;
        }

        // char is digit
        if (isdigit(exp[i])) {
            int value = 0;
            while (i < strlen(exp) && isdigit(exp[i])) {
                value = (value * 10) + (exp[i] - '0');
                i++;
            }
            push(&values, value);
            continue;
        }

        // char is operator
        if (strchr("+-*/", exp[i])) {
            while (peek(&ops) != -1 && precedence(peek(&ops)) >= precedence(exp[i])) {
                int b = pop(&values);
                int a = pop(&values);
                char op = pop(&ops);
                push(&values, applyOperation(a, b, op));
            }
            push(&ops, exp[i]);
            i++;
            continue;
        }


        printf("Invalid expression\n");
    }
// rest operators
    while (peek(&ops) != -1) {
        int b = pop(&values);
        int a = pop(&values);
        char op = pop(&ops);
        push(&values, applyOperation(a, b, op));
    }

    return pop(&values);
}


int main() {
    char exp[MAX];
    printf("Enter Expression: ");
    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = '\0'; // use to remove newline character 

    int result = evaluateExpression(exp);
    printf("Result: %d\n", result);
    return 0;
}
