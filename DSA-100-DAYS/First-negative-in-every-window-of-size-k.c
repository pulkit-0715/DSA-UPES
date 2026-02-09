#include <stdio.h>

#define MAX 100000

void firstNegInt(int arr[], int n, int k) {
    int dq[MAX];
    int front = 0, rear = -1;

    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq[++rear] = i;
        }
    }

    if (front <= rear) printf("%d ", arr[dq[front]]);
    else printf("0 ");

    for (int i = k; i < n; i++) {
        while (front <= rear && dq[front] <= i - k) {
            front++;
        }

        if (arr[i] < 0) {
            dq[++rear] = i;
        }

        if (front <= rear) printf("%d ", arr[dq[front]]);
        else printf("0 ");
    }
}

int main() {
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = 8;
    int k = 3;

    firstNegInt(arr, n, k);

    return 0;
}
