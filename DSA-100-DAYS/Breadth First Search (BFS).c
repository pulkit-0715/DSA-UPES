#include <stdio.h>
#include <stdlib.h>

int **adj;
int *size;
int *visited;
int queue[1000];
int front = 0, rear = 0;
int n;

void bfs(int s) {
    visited[s] = 1;
    queue[rear++] = s;

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for(int i = 0; i < size[node]; i++) {
            int next = adj[node][i];

            if(!visited[next]) {
                visited[next] = 1;
                queue[rear++] = next;
            }
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

    bfs(s);

    return 0;
}