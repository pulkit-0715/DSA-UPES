#include <stdio.h>
#include <string.h>
#define MAX 20

struct Stack {
    char arr[MAX];
    int top;
};

void init(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    if(s->top==-1)
    return 1;
    return 0;
}

void push(struct Stack *s, char c) {
    s->arr[++(s->top)] = c;
}

char pop(struct Stack *s) {
    if (isEmpty(s))
        return '\0';
    return s->arr[(s->top)--];
}

int validParentheses(char *str) {
    struct Stack s;
    init(&s);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (ch == '(') {
            push(&s, ch);
        }
        else {
            if (isEmpty(&s))
                return 0;

            char top = pop(&s);

            if ((ch == ')' && top != '('))
                return 0;
        }
    }

    return isEmpty(&s);
}

int main() {
    char str[20];

    printf("Enter expression: \n");
    scanf("%s", str);

    if (validParentheses(str))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}