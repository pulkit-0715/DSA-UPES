#include <stdio.h>

int maxSubArray(int nums[], int n) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    int j = 0;        
    int start = 0;    
    int end = 0;      

    for (int i = 1; i < n; i++) {

        if (currentSum + nums[i] > nums[i]) {
            currentSum = currentSum + nums[i];
        } else {
            currentSum = nums[i];
            j = i;
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = j;
            end = i;
        }
    }

    int ii = start, jj = end;
    printf("Maximum subarray: ");
    while (ii <= jj) {
        printf("%d ", nums[ii]);
        ii++;
    }
    printf("\n");

    return maxSum;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubArray(nums, n);
    printf("Maximum subarray sum = %d\n", result);

    return 0;
}
