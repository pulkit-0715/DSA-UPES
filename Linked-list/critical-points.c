#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void criticalPointsInfo(struct Node* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        printf("0\n");
        return;
    }

    int count = 0;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    struct Node* prev = head;
    struct Node* curr = head->next;
    struct Node* next = curr->next;

    while (next != NULL) {
        if ((curr->data > prev->data && curr->data > next->data) ||
            (curr->data < prev->data && curr->data < next->data)) {

            count++;

            if (curr->data < minVal)
                minVal = curr->data;

            if (curr->data > maxVal)
                maxVal = curr->data;
        }

        prev = curr;
        curr = next;
        next = next->next;
    }

    if (count == 0)
        printf("0\n");
    else
        printf("Count: %d\nMin: %d\nMax: %d\n", count, minVal, maxVal);
}

int main() {
    int n, x;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&head, x);
    }

    criticalPointsInfo(head);

    return 0;
}