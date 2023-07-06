#include <stdio.h>

int maze_backtracking(int maze[20][20],
int linha, int coluna,
int x, int y){

if (x==-1 || y==-1 || x==coluna || y==linha || maze[y][x]!=0)
return 0; //Parte que diz se x e y estão dentro dos limites permitidos. Ss não o local tiver ocupado, ai ele retorna o zero pra mostrar que não é um caminho válido. Ou se já ta na posição final.

if (x==coluna-1 && y==linha-1)
return 1; // Parte que diz se x e y estão na celula final, se sim, ai um caminho foi encontrado.

maze[y][x] = 9;
int resposta = 0;
 // As chamadas recursivas que verificam as direções, sendo elas a partir da posição atual. Fazendo isso para todas as células possíveis (?).
 //Qunado ele acha um caminho que leva até o final, ja retorna 1.

resposta = maze_backtracking(maze, linha, coluna, x, y+1) ||
      maze_backtracking(maze, linha, coluna, x+1, y) ||
      maze_backtracking(maze, linha, coluna, x-1, y) ||
      maze_backtracking(maze, linha, coluna, x, y-1);

maze[y][x] = 0;  //Coloca zero na posição atual e retorna o valor das recurções. 
return resposta;
}

int main() {
  
int linha, coluna, maze[20][20];
scanf("%d %d", &linha, &coluna);
for (int i=0 ; i<linha ; ++i)
for (int j=0 ; j<coluna ; ++j)
scanf("%d",&maze[i][j]);
int fim = maze_backtracking(maze, linha,
coluna,0,0);
printf("%d\n",fim);

return 0;
}
