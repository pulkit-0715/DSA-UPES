#include <stdio.h>

int queue[10000][2];
int front = 0, rear = 0;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int grid[100][100];
    int fresh = 0, time = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);

            if(grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            else if(grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    while(front < rear && fresh > 0) {
        int size = rear - front;
        time++;

        while(size--) {
            int r = queue[front][0];
            int c = queue[front][1];
            front++;

            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;

                    queue[rear][0] = nr;
                    queue[rear][1] = nc;
                    rear++;
                }
            }
        }
    }

    if(fresh == 0) printf("%d", time);
    else printf("-1");

    return 0;
}