#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push() {
    int val;
    scanf("%d",&val);

    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } 
    else {
        top++;
        stack[top] = val;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } 
    else {
        top--;
    }
}

void peek() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element is %d\n", stack[top]);
}

void isEmpty() {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");
}

void print_stack() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {

   int n;
   printf("How many elements to add?\n");
   scanf("%d",&n);

   for(int i=0;i<n;i++)
       push();

   print_stack();

   int p;
   printf("How many elements to pop?\n");
   scanf("%d",&p);

   for(int i=0;i<p;i++)
       pop();

   print_stack();

   return 0;
}