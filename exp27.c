#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Check if string is alphanumeric
int isAlphanumeric(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '(' && str[i] != ')' &&
            str[i] != '{' && str[i] != '}' &&
            str[i] != '[' && str[i] != ']') {
            return 0;
        }
    }
    return 1;
}

// Check for balanced brackets
int isBalanced(const char *str) {
    char stack[100];
    int top = -1;

    for (int i = 0; str[i]; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) return 0;
            char open = stack[top--];
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '['))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (strlen(str) == 0) {
        printf("Invalid: Empty string.\n");
        return 0;
    }

    if (!isAlphanumeric(str)) {
        printf("Invalid: String contains invalid characters.\n");
        return 0;
    }

    if (!isBalanced(str)) {
        printf("Invalid: Brackets are not balanced.\n");
        return 0;
    }

    printf("Valid string!\n");
    return 0;
}
