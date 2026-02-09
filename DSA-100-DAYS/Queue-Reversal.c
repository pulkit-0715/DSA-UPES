#include <stdio.h>
#include <stdbool.h>

#define MAX 1000


int q[MAX];
int front = -1, rear = -1;


int st[MAX];
int top = -1;

bool isQueueEmpty() {
    return front == -1;
}

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    q[++rear] = x;
}

int dequeue() {
    if (isQueueEmpty()) return -1;
    int val = q[front++];
    if (front > rear) front = rear = -1;
    return val;
}

void reverseQueue() {
   
    while (!isQueueEmpty()) {
        st[++top] = dequeue();
    }

   
    while (top != -1) {
        enqueue(st[top--]);
    }
}

void printQueue() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    reverseQueue();

    printQueue();   

    return 0;
}
