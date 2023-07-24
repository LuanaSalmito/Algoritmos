#include "dyna-Vect.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Mostra valor não inserido e sai do programa.*/
void error_at_insertion(array_list_int* l, int x) {
  fprintf(stderr, "\033[0;31mErro:\033[0m:\tValor %d não inserido!\n", x);
  fprintf(stderr, "\tA lista possui %d elementos.\n", array_list_size(l));
  exit(1);
}

/* Imprime a lista na saída padrão. */
void print_vector(array_list_int* l) {
  int i, x, erro;
  for (i = 0; i < array_list_size(l); ++i) {
    x = array_list_get(l, i, &erro);
    if (!erro) {
      printf("%d ", x);
    }
    else {
      fprintf(stderr, "ERRO: índice %d não é válido!\n", i);
      exit(2);
    }
  }
  printf("\n");
}

int main() {
    //-----------------------------1º - INSERÇÃO CONSECUTIVA-----------------------------------//
  time_t inicio, fim;
  int n, i, x;
  array_list_int* l01 = array_list_create();
  scanf("%d", &n);
  inicio = time(0);
  for (i = 0; i < n; ++i) {
    scanf("%d", &x);
    /* array_list_push_back retorna o novo tamanho da lista.
       Se não houve inserção o tamanho não será (i+1).
       O programa então mostra que não inseriu e termina.
       */
    if (array_list_push_back(l01, x) != (i + 1)) {
      error_at_insertion(l01, x);
    }
  }
  fim = time(0);
  fprintf(stderr, "Inserção de %d elementos em %.25lf milissegundos.\n", n,
    (((double)fim - (double)inicio) / (CLOCKS_PER_SEC * 1000)));
  printf("Tamanho do vetor: %d\n", array_list_size(l01));
  

  srand(time(NULL)); // Inicializar a semente do gerador de números aleatórios
  int num_searches = 100; // Número de buscas aleatórias a serem realizadas
  int* search_elements = (int*)malloc(num_searches * sizeof(int));
  for (i = 0; i < num_searches; ++i) {
    search_elements[i] = rand() % n; // Gerar números aleatórios no intervalo [0, n-1]
  }
  //------------------------------ 2º - BUSCA DE ELEMENTO---------------------------------------------//
  inicio = time(0);
  for (i = 0; i < num_searches; ++i) {
    int element = search_elements[i];
    int result = array_list_find(l01, element);
    if (result != -1) {
      printf("Element %d found at index %d.\n", element, result);
      break;
    } else {
      printf("Element %d not found in the list.\n", element);
    }
  }
  fim = time(0);
  fprintf(stderr, "Busca de %d elementos aleatórios em %.25lf milissegundos.\n", num_searches,
    (((double)fim - (double)inicio) / (CLOCKS_PER_SEC * 1000)));

  free(search_elements);
  printf("Tamanho do vetor: %d\n", array_list_size(l01));
  return 0;
  
  //------------------------3º - REMOÇÃO PELO ÍNDICE--------------------------------//

  srand(time(NULL)); // Inicializar a semente do gerador de números aleatórios
  int num_removals = 50; // Número de remoções aleatórias a serem realizadas
  for (i = 0; i < num_removals; ++i) {
    int index = rand() % array_list_size(l01); // Gerar índices aleatórios no intervalo [0, tamanho da lista - 1]
    inicio = time(0);
    unsigned int new_size = array_list_remove_from(l01, index);
    fim = time(0);
    fprintf(stderr, "Remoção do elemento no índice %d em %.25lf milissegundos. Novo tamanho: %d\n", index,
      (((double)fim - (double)inicio) / (CLOCKS_PER_SEC * 1000)), new_size);
  }
  printf("Tamanho do vetor: %d\n", array_list_size(l01));
 
//-------------------------- 4º - BUSCA E REMOÇÃO DE ELEMENTOS ALEATÓRIOS-------------//
//-------------------------- (JUNÇÃO DO 2º E 3º) ---------------------------------------//

 srand(time(NULL)); // Inicializar a semente do gerador de números aleatórios
  int num_operations = 50; // Número de operações de busca + remoção aleatórias a serem realizadas
  for (i = 0; i < num_operations; ++i) {
    int element = rand() % n; // Gerar números aleatórios no intervalo [0, n-1]

    // Busca e Remoção do elemento aleatório se encontrado
    inicio = time(0);
    int result = array_list_find(l01, element);
    if (result != -1) {
      unsigned int new_size = array_list_remove_from(l01, result);
    }
    fim = time(0);
    fprintf(stderr, "Operação %d (Busca + Remoção) do elemento %d em %.25lf milissegundos. Novo tamanho: %d\n", i + 1, element,
      (((double)fim - (double)inicio) / (CLOCKS_PER_SEC * 1000)), array_list_size(l01));
  }


  printf("Tamanho do vetor: %d\n", array_list_size(l01));
 //----------------------INSERÇÃO, BUSCA E REMOÇÃO JUNTOS-----------------------//
 //---------------------JUNÇÃO DAS TRÊS PRIMEIRAS PARTES------------------------//

 srand(time(NULL)); // Inicializar a semente do gerador de números aleatórios
  int num_operations_50 = 50; // Número total de operações aleatórias a serem realizadas
  time_t inicio_operacoes = time(0); // Tempo inicial das operações combinadas

  for (i = 0; i < num_operations_50; ++i) {
    int operation = rand() % 3; // Gerar um número aleatório no intervalo [0, 2] para definir a operação: 0 - Inserção, 1 - Busca, 2 - Remoção
    int element = rand() % (n + 10); // Gerar um número aleatório no intervalo [0, n+9] para ser o elemento a ser inserido/buscado/removido

    if (operation == 0) {
      // Inserção
      if (array_list_push_back(l01, element) != n + 1) {
        // Tratamento de erro, se necessário
      }
      n++;
    } else if (operation == 1) {
      // Busca
      int result = array_list_find(l01, element);
    } else {
      // Remoção
      int index = array_list_find(l01, element);
      if (index != -1) {
        array_list_remove_from(l01, index);
        n--;
      }
    }
  }

  time_t fim_operacoes = time(0); // Tempo final das operações combinadas
  fprintf(stderr, "Tempo total das operações (Inserção + Busca + Remoção) em %.25lf milissegundos.\n",
    (((double)fim_operacoes - (double)inicio_operacoes) / (CLOCKS_PER_SEC * 1000)));

  return 0;
}