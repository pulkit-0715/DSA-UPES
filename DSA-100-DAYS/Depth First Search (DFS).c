#include <stdio.h>
#include <stdlib.h>

int **adj;
int *size;
int *visited;
int n;

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for(int i = 0; i < size[node]; i++) {
        int next = adj[node][i];
        if(!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    scanf("%d", &n);

    adj = (int**)malloc(n * sizeof(int*));
    size = (int*)malloc(n * sizeof(int));
    visited = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &size[i]);
        adj[i] = (int*)malloc(size[i] * sizeof(int));

        for(int j = 0; j < size[i]; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s;
    scanf("%d", &s);

    dfs(s);

    return 0;
}