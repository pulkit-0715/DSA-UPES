#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

struct Node* reverseK(struct Node* head, int k) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }
    if (count < k)
        return head;

    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
        head->next = reverseK(next, k);

    return prev;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k, x;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&head, x);
    }

    scanf("%d", &k);

    head = reverseK(head, k);
    printList(head);

    return 0;
}