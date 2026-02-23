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

int hasCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return 1;
    }

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    if(n <= 0) return 0;

    struct Node* head = NULL;
    struct Node* temp = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = createNode(value);

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    if(hasCycle(head))
        printf("Cycle Detected");
    else
        printf("No Cycle");

    return 0;
}