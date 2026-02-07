#include <stdio.h>

void rightRotate(int arr[], int start, int end) {
    int temp = arr[end];
    for (int i = end; i > start; i--) {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

void rearrange(int arr[], int n) {
    int wrongIndex = -1;

    for (int i = 0; i < n; i++) {
        
        if (wrongIndex >= 0) {
            if ((arr[i] >= 0 && arr[wrongIndex] < 0) ||
                (arr[i] < 0 && arr[wrongIndex] >= 0)) {
                
                rightRotate(arr, wrongIndex, i);

                if (i - wrongIndex >= 2)
                    wrongIndex += 2;
                else
                    wrongIndex = -1;
            }
        }

        if (wrongIndex == -1) {
            if (((arr[i] >= 0) && (i % 2 == 0)) ||
                ((arr[i] < 0) && (i % 2 == 1))) {
                wrongIndex = i;
            }
        }
    }
}

int main() {
    int arr[] = {-7,10,-6,2,3,-8,0,7,11,-20};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
