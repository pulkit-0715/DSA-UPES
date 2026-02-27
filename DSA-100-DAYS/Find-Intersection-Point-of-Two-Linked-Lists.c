#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m;

    scanf("%d", &n);

    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;

    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    struct Node* intersection = getIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}