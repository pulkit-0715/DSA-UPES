#include <stdio.h>
#include <stdlib.h>

int **rooms;
int *sizes;
int *visited;
int n;

void dfs(int room) {
    visited[room] = 1;

    for(int i = 0; i < sizes[room]; i++) {
        int key = rooms[room][i];
        if(!visited[key]) {
            dfs(key);
        }
    }
}

int main() {
    scanf("%d", &n);

    rooms = (int**)malloc(n * sizeof(int*));
    sizes = (int*)malloc(n * sizeof(int));
    visited = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &sizes[i]);
        rooms[i] = (int*)malloc(sizes[i] * sizeof(int));

        for(int j = 0; j < sizes[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    dfs(0);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            printf("false");
            return 0;
        }
    }

    printf("true");

    return 0;
}