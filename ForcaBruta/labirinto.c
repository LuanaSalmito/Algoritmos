#include <stdio.h>

#define MAX_SIZE 10
#define INF 1000000

int is_valid_move(int grid[][MAX_SIZE], int visited[][MAX_SIZE], int rows, int cols, int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        return 0;

    if (grid[row][col] == 1 || visited[row][col])
        return 0;

    return 1;
}

int find_shortest_path(int grid[][MAX_SIZE], int rows, int cols) {
    int visited[MAX_SIZE][MAX_SIZE] = {0};
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int min_count = INF;

    int start_row = 0;
    int start_col = 0;
    int end_row = rows - 1;
    int end_col = cols - 1;

    void backtrack(int row, int col, int count) {
        if (row == end_row && col == end_col) {
            if (count < min_count)
                min_count = count;
            return;
        }

        visited[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int new_row = row + directions[i][0];
            int new_col = col + directions[i][1];

            if (is_valid_move(grid, visited, rows, cols, new_row, new_col))
                backtrack(new_row, new_col, count + 1);
        }

        visited[row][col] = 0;
    }

    backtrack(start_row, start_col, 1);

    if (min_count == INF)
        return -1;
    else
        return min_count;
}

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int grid[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int shortest_path = find_shortest_path(grid, rows, cols);

    printf("%d\n", shortest_path);

    return 0;
}
