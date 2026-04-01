#include <stdio.h>

void dailyTemperatures(int temp[], int n, int ans[]) {
    int stack[n];   // stack to store indices
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && temp[i] > temp[stack[top]]) {
            int prev = stack[top];
            top--;
            ans[prev] = i - prev;
        }
        stack[++top] = i;
    }

    // Remaining elements have no warmer day
    while (top != -1) {
        ans[stack[top]] = 0;
        top--;
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int temp[] = {73,74,75,71,69,72,76,73};
    int n = sizeof(temp)/sizeof(temp[0]);
    int ans[n];

    dailyTemperatures(temp, n, ans);

    printf("Result:\n");
    printArray(ans, n);

    return 0;
}