#include <iostream>
#include <vector>

using namespace std;

bool findPath(vector<vector<int>>& maze, int x, int y) {
    int n = maze.size();
    int m = maze[0].size();

    // Verifica se a célula atual é a saída
    if (x == n - 1 && y == m - 1) {
        return true;
    }

    // Verifica se a célula atual é válida e livre
    if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0) {
        // Marca a célula como visitada
        maze[x][y] = 1;

        // Tenta encontrar um caminho a partir das células vizinhas
        if (findPath(maze, x - 1, y) || findPath(maze, x + 1, y) ||
            findPath(maze, x, y - 1) || findPath(maze, x, y + 1)) {
            return true;
        }

        // Não encontrou um caminho válido, marca a célula como não visitada
        maze[x][y] = 0;
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Leitura do labirinto
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    // Verifica se é possível encontrar um caminho
    if (findPath(maze, 0, 0)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
