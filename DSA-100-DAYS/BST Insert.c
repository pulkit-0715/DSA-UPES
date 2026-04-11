#include <stdio.h>
#include <stdlib.h>

// Define structure for BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int value) {
    // If tree is empty, create new node
    if (root == NULL) {
        return createNode(value);
    }

    // Insert in left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Insert in right subtree
    else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder traversal (to check BST)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder traversal of BST: ");
    inorder(root);

    return 0;
}