#include <stdio.h>

// Function to right rotate the array from 'start' to 'end'
void rightRotate(int arr[], int start, int end) {
    int temp = arr[end];
    for (int i = end; i > start; i--) {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

void rearrange(int arr[], int n) {
    int i, j;

    // Step 1: Partition negatives to left side
    j = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }

    // Step 2: Rearrange alternately using rotation
    int pos = j;   // index of first positive
    int neg = 0;   // index of first negative

    while (neg < pos && pos < n && arr[neg] < 0) {
        rightRotate(arr, neg + 1, pos);
        neg += 2;
        pos++;
    }
}

int main() {
    int arr[] = {1, 2, -3, -4, -5, 6, -7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, n);

    printf("Rearranged array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
