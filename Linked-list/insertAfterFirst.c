#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAfterFirst(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty, cannot insert after first node\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = head->next;
    head->next = newNode;
}


void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = NULL;

    printf("Before insertion:\n");
    display(head);

    insertAfterFirst(head, 15);

    printf("After insertion:\n");
    display(head);

    return 0;
}
