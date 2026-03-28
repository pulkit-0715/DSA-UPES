#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

int pr(char c) {
    if (c=='+' || c=='-') return 1;
    if (c=='*' || c=='/') return 2;
    return 0;
}

int main() {
    char s[100];

    printf("Enter expression: ");
    scanf("%s", s);

    for (int i=0; s[i]; i++) {
        if (isalnum(s[i]))
            printf("%c", s[i]);

        else if (s[i]=='(')
            stack[++top] = s[i];

        else if (s[i]==')') {
            while (stack[top] != '(')
                printf("%c", stack[top--]);
            top--;
        }

        else {
            while (top!=-1 && pr(stack[top]) >= pr(s[i]))
                printf("%c", stack[top--]);
            stack[++top] = s[i];
        }
    }

    while (top!=-1)
        printf("%c", stack[top--]);

    return 0;
}