#include <stdio.h>
#include <stdlib.h>

int **adj;
int *size;
int *visited;
int n;

int dfs(int node, int parent) {
    visited[node] = 1;

    for(int i = 0; i < size[node]; i++) {
        int next = adj[node][i];

        if(!visited[next]) {
            if(dfs(next, node))
                return 1;
        }
        else if(next != parent) {
            return 1;
        }
    }

    return 0;
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

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");

    return 0;
}