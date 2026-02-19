#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int nums[], int n) {
    int totalSum = 0;
    int currMax = 0, maxSum = nums[0];
    int currMin = 0, minSum = nums[0];

    for(int i = 0; i < n; i++) {
        totalSum += nums[i];

        currMax = max(nums[i], currMax + nums[i]);
        maxSum = max(maxSum, currMax);

        currMin = min(nums[i], currMin + nums[i]);
        minSum = min(minSum, currMin);
    }

    if(maxSum < 0)
        return maxSum;

    return max(maxSum, totalSum - minSum);
}

int main() {
    int nums[] = {5, -3, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = maxSubarraySumCircular(nums, n);
    printf("%d\n", result);

    return 0;
}
