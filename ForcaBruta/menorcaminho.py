
n, m = map(int, input("Digite a quantidade de linhas (n) e colunas (m) do labirinto: ").split())

maze = []
print("Digite as células do labirinto separadas por espaço:")
for _ in range(n):
    row = list(map(int, input().split()))
    maze.append(row)




################## Métodos ##########################
def find_shortest_path(maze, x, y, steps, min_steps):
    linha = len(maze)
    coluna = len(maze[0])

    if x < 0 or x >= coluna or y < 0 or y >= linha or maze[y][x] == 1:
        return

    if x == coluna - 1 and y == linha - 1:
        if steps < min_steps[0] or min_steps[0] == INF:
            min_steps[0] = steps  # Atualizar o menor caminho encontrado
        return

    maze[y][x] = 1  # Marcar célula como visitada

    # Explorar as 4 direções possíveis (acima, abaixo, esquerda, direita)
    find_shortest_path(maze, x, y - 1, steps + 1, min_steps)
    find_shortest_path(maze, x, y + 1, steps + 1, min_steps)
    find_shortest_path(maze, x - 1, y, steps + 1, min_steps)
    find_shortest_path(maze, x + 1, y, steps + 1, min_steps)

    maze[y][x] = 0  # Marcar célula como livre novamente

def menorCaminho(maze):
    linha = len(maze)
    coluna = len(maze[0])
    min_steps = [INF]  # Armazenar o menor caminho encontrado

    find_shortest_path(maze, 0, 0, 0, min_steps)

    return min_steps[0] if min_steps[0] != INF else -1



print(menorCaminho(maze)) 