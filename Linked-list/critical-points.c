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

int countCriticalPoints(struct Node* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return 0;

    int count = 0;
    struct Node* prev = head;
    struct Node* curr = head->next;
    struct Node* next = curr->next;

    while (next != NULL) {
        if ((curr->data > prev->data && curr->data > next->data) ||
            (curr->data < prev->data && curr->data < next->data)) {
            count++;
        }
        prev = curr;
        curr = next;
        next = next->next;
    }

    return count;
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

    printf("%d", countCriticalPoints(head));

    return 0;
}