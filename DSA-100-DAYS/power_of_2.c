#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int num;
    scanf("%d", &num);

    if (isPowerOfTwo(num))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
