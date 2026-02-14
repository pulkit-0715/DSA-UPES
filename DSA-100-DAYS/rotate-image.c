#include <stdio.h>

#define MAX 100

void rotate(int matrix[MAX][MAX], int n) {
    int i, j, temp;

    for(i = 0; i < n; i++) {
        for(j = i; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = temp;
        }
    }
}

int main() {
    int n, i, j;
    int matrix[MAX][MAX];

    printf("Enter size of matrix (n): ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    rotate(matrix, n);

    printf("Rotated Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
