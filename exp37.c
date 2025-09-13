#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* expr) {
    int i = 0;
    char ch;

    while ((ch = expr[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');  // Convert char to int
        } else {
            int val2 = pop();
            int val1 = pop();
            int result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': 
                    if (val2 == 0) {
                        printf("Division by zero error!\n");
                        exit(1);
                    }
                    result = val1 / val2; 
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
            push(result);
        }
    }
    return pop();  // Final result
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression (e.g. 53+82-*): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of postfix expression = %d\n", result);

    return 0;
}
