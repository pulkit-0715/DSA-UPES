#include <stdio.h>

#define MAX 100

int main() {
    int n, i, j;
    int matrix[MAX][MAX];
    int isIdentity = 1;


    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j) {
                if(matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                if(matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if(isIdentity == 0)
            break;
    }


    if(isIdentity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}
