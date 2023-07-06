#include <stdio.h>

int maze_backtracking(int maze[20][20], int linha, int coluna, int x, int y, int distance, int *minDistance) {
    if (x == -1 || y == -1 || x == coluna || y == linha || maze[y][x] != 0) {
        return 0;
    }

    if (x == coluna - 1 && y == linha - 1) {
        if (distance < *minDistance) {
            *minDistance = distance;
        }
        return 1;
    }

    maze[y][x] = 9;

    int ans = 0;

    ans = maze_backtracking(maze, linha, coluna, x, y + 1, distance + 1, minDistance) ||
          maze_backtracking(maze, linha, coluna, x + 1, y, distance + 1, minDistance) ||
          maze_backtracking(maze, linha, coluna, x - 1, y, distance + 1, minDistance) ||
          maze_backtracking(maze, linha, coluna, x, y - 1, distance + 1, minDistance);

    maze[y][x] = 0;

    return ans;
}

int findShortestPath(int maze[20][20], int linha, int coluna) {
    int minDistance = linha * coluna; // Valor inicial máximo
    maze_backtracking(maze, linha, coluna, 0, 0, 0, &minDistance);

    if (minDistance == linha * coluna) {
        return -1; // Não há caminho possível até a célula final
    }

    return minDistance;
}

int main() {
    int linha, coluna, maze[20][20];
    scanf("%d %d", &linha, &coluna);
    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna; ++j) {
            scanf("%d", &maze[i][j]);
        }
    }

    int shortestPath = findShortestPath(maze, linha, coluna);
    printf("%d\n", shortestPath);

    return 0;
}
