#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* swapPairs(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* newHead = head->next;
    struct Node* prev = NULL;
    struct Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        struct Node* nextPair = curr->next->next;
        struct Node* second = curr->next;

        second->next = curr;
        curr->next = nextPair;

        if (prev != NULL)
            prev->next = second;

        prev = curr;
        curr = nextPair;
    }

    return newHead;
}

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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, x;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&head, x);
    }

    head = swapPairs(head);
    printList(head);

    return 0;
}