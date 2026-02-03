#include <stdio.h>

int missingNum(int arr[], int size) {
    int n = size + 1;
    long long sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    long long total = (long long)n * (n + 1) / 2;

    return (int)(total - sum);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n - 1];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = missingNum(arr, n - 1);
    printf("%d\n", missing);

    return 0;
}
