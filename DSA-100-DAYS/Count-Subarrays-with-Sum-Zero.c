#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000003

typedef struct Node {
    long long key;
    long long count;
    struct Node* next;
} Node;

Node* table[SIZE];

long long hash(long long key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

void insert(long long key) {
    long long idx = hash(key);
    Node* temp = table[idx];
    while (temp) {
        if (temp->key == key) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = table[idx];
    table[idx] = newNode;
}

long long getCount(long long key) {
    long long idx = hash(key);
    Node* temp = table[idx];
    while (temp) {
        if (temp->key == key)
            return temp->count;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long *arr = (long long*)malloc(n * sizeof(long long));
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    long long sum = 0, count = 0;

    insert(0);

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        count += getCount(sum);
        insert(sum);
    }

    printf("%lld", count);
    return 0;
}
