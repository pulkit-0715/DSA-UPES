#include <stdio.h>

int image[100][100];
int n, m;

void dfs(int r, int c, int oldColor, int newColor) {
    if(r < 0 || c < 0 || r >= n || c >= m) return;
    if(image[r][c] != oldColor) return;

    image[r][c] = newColor;

    dfs(r + 1, c, oldColor, newColor);
    dfs(r - 1, c, oldColor, newColor);
    dfs(r, c + 1, oldColor, newColor);
    dfs(r, c - 1, oldColor, newColor);
}

int main() {
    int sr, sc, color;

    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &image[i][j]);

    scanf("%d%d%d", &sr, &sc, &color);

    int oldColor = image[sr][sc];

    if(oldColor != color)
        dfs(sr, sc, oldColor, color);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}