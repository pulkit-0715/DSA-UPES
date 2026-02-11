#include <stdio.h>

#define MAX 100

void transpose(int n, int m, int matrix[MAX][MAX]) {
    int ans[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 2, m = 3;

    int matrix[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    transpose(n, m, matrix);

    return 0;
}
