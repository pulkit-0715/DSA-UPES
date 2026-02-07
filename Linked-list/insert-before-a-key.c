#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void printlist(struct Node *head){
    struct Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insert(struct Node* head, int key, int value){
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Invalid key entered (not found in list)\n");
        return head;
    }

    struct Node *block = (struct Node*)malloc(sizeof(struct Node));
    block->data = value;

    if (prev == NULL){
        block->next = head;
        head = block;
    }
    else{
        prev->next = block;
        block->next = temp;
    }

    return head;
}

int main(){
    int n;
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    if (n <= 0) return 0;

    printf("Enter data:\n");

    struct Node *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++){
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
    }

    int key, data;
    printf("Enter the value to insert:\n");
    scanf("%d", &data);

    printf("Enter key (before which to insert):\n");
    scanf("%d", &key);

    head = insert(head, key, data);

    printlist(head);

    return 0;
}
