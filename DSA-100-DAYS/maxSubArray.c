#include <stdio.h>

int maxSubArray(int nums[], int n) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < n; i++) {
        if (currentSum + nums[i] > nums[i])
            currentSum = currentSum + nums[i];
        else
            currentSum = nums[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubArray(nums, n);
    printf("%d\n", result);

    return 0;
}
