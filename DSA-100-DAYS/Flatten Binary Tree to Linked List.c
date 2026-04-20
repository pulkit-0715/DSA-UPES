#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    if(val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while(front < rear && i < n) {
        struct Node* curr = queue[front++];

        if(i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void flatten(struct Node* root) {
    while(root) {
        if(root->left) {
            struct Node* temp = root->left;

            while(temp->right)
                temp = temp->right;

            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}

void printList(struct Node* root) {
    while(root) {
        printf("%d ", root->data);
        root = root->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    flatten(root);

    printList(root);

    return 0;
}