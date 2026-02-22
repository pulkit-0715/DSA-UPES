#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    int n;
    scanf("%d", &n);

    if(n <= 0) return 0;

    int x;
    scanf("%d", &x);

    struct Node* head = createNode(x);
    struct Node* temp = head;

    for(int i = 1; i < n; i++) {
        scanf("%d", &x);
        temp->next = createNode(x);
        temp = temp->next;
    }

    head = reverseList(head);

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
