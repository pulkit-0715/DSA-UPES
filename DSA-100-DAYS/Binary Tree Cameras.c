#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int index = 0;

struct Node* buildTree(int arr[], int n) {
    if(index >= n || arr[index] == -1) {
        index++;
        return NULL;
    }

    struct Node* root = createNode(arr[index++]);
    root->left = buildTree(arr, n);
    root->right = buildTree(arr, n);

    return root;
}

int cameras = 0;

int solve(struct Node* root) {
    if(root == NULL) return 1;

    int left = solve(root->left);
    int right = solve(root->right);

    if(left == -1 || right == -1) {
        cameras++;
        return 0;
    }

    if(left == 0 || right == 0) return 1;

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if(solve(root) == -1) cameras++;

    printf("%d", cameras);

    return 0;
}