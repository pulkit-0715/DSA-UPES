#include <stdio.h>

int longestOnes(int* nums, int numsSize, int k) {
    int left = 0;
    int zeroCount = 0;
    int maxLen = 0;

    for (int right = 0; right < numsSize; right++) {

        if (nums[right] == 0)
            zeroCount++;

        while (zeroCount > k) {
            if (nums[left] == 0)
                zeroCount--;
            left++;
        }

        if (right - left + 1 > maxLen)
            maxLen = right - left + 1;
    }

    return maxLen;
}

int main() {
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d elements (0s and 1s):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    int result = longestOnes(nums, n, k);
    printf("Maximum consecutive ones = %d\n", result);

    return 0;
}
