#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}

void infix_to_postfix(const char* infix, char* postfix) {
    Stack stack;
    initStack(&stack); 
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);
        } else {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!is_empty(&stack)) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0';
}

int evaluate_postfix(const char* postfix) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push(&stack, ch - '0');
        } else if (ch >= '0' && ch <= '9') {
            int num = 0;
            while (ch >= '0' && ch <= '9') {
                num = num * 10 + (ch - '0');
                ch = postfix[++i];
            }
            i--;  
            push(&stack, num);
        } else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default: printf("Error\n"); exit(1);
            }
            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0'; 

    infix_to_postfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluate_postfix(postfix);
    printf("Evaluation Result: %d\n", result);

    return 0;
}
