#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()

void find_shortest_path(std::vector<std::vector<int>>& maze, int x, int y, int steps, int& min_steps) {
    int linha = maze.size();
    int coluna = maze[0].size();

    if (x < 0 || x >= coluna || y < 0 || y >= linha || maze[y][x] == 1) {
        return;
    }

    if (x == coluna - 1 && y == linha - 1) {
        min_steps = std::min(min_steps, steps);
        return;
    }

    maze[y][x] = 1;  // Marcar célula como visitada

    // Explorar as 4 direções possíveis (acima, abaixo, esquerda, direita)
    find_shortest_path(maze, x, y - 1, steps + 1, min_steps);
    find_shortest_path(maze, x, y + 1, steps + 1, min_steps);
    find_shortest_path(maze, x - 1, y, steps + 1, min_steps);
    find_shortest_path(maze, x + 1, y, steps + 1, min_steps);

    maze[y][x] = 0;  // Marcar célula como livre novamente
}

int shortest_path(std::vector<std::vector<int>>& maze) {
    int linha = maze.size();
    int coluna = maze[0].size();
    int min_steps = INF;  // Armazenar o menor caminho encontrado

    find_shortest_path(maze, 0, 0, 0, min_steps);

    return (min_steps != INF) ? min_steps : -1;
}

int main() {
    int n, m;
    std::cout << "Digite a quantidade de linhas (n) e colunas (m) do labirinto: ";
    std::cin >> n >> m;

    std::vector<std::vector<int>> maze(n, std::vector<int>(m, 0));
    std::cout << "Digite as células do labirinto:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> maze[i][j];
        }
    }

    std::cout << "O menor número de passos para chegar à saída é: " << shortest_path(maze) << std::endl;

    return 0;
}
