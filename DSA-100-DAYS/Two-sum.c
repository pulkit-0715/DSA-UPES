#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

int cmp(const void* a, const void* b) {
    return ((Pair*)a)->val - ((Pair*)b)->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Pair* arr = (Pair*)malloc(numsSize * sizeof(Pair));
    
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    qsort(arr, numsSize, sizeof(Pair), cmp);

    int left = 0, right = numsSize - 1;

    while (left < right) {
        int sum = arr[left].val + arr[right].val;

        if (sum == target) {
            int* res = (int*)malloc(2 * sizeof(int));
            res[0] = arr[left].idx;
            res[1] = arr[right].idx;
            *returnSize = 2;
            free(arr);
            return res;
        }
        else if (sum < target)
            left++;
        else
            right--;
    }

    *returnSize = 0;
    free(arr);
    return NULL;
}
