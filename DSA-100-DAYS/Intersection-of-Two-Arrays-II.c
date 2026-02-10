#include <stdio.h>

int main() {
    int n1, n2;

    scanf("%d", &n1);
    int nums1[n1];

    for (int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
    }

    scanf("%d", &n2);
    int nums2[n2];

    for (int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
    }

    int used[n1];
    for (int i = 0; i < n1; i++) {
        used[i] = 0;
    }

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n1; j++) {
            if (!used[j] && nums2[i] == nums1[j]) {
                printf("%d ", nums2[i]);
                used[j] = 1;
                break;
            }
        }
    }

    return 0;
}
