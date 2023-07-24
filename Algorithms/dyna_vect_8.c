
#include "dyna-Vect.h"
#include <stdlib.h>

//As definições do big(O) estão ao final de cada função.

struct array_list_int {
  int* data;
  unsigned int size, capacity;
};



int increase_memory(array_list_int* list) {
  //Primeiro vejo seo ponteiro é válido
  if (list == NULL) {
    return -1; 
  }

  unsigned int new_capacity = list->capacity * 2;
  int* new_data = (int*)malloc(new_capacity * sizeof(int));

  //Diz se a alocação falhou 
  if (new_data == NULL) {
    return -1; 
  }

  //Coloca os elementos em um novo array
  for (unsigned int i = 0; i < list->size; i++) {
    new_data[i] = list->data[i];
  }

  //Apaga o antigo
  free(list->data);

  //Atualiza os atributos do ponteiro
  list->data = new_data;
  list->capacity = new_capacity;

  return 1;

  /////////////////////Big(O)= O(n)///////////////////
  // Pois nessa função há uma operação de cópia de array a qual percorre todos os elementos do array antigo
  // Que é copiado para um novo com todos os seus elementos originais.
}



array_list_int* array_list_create() {
  // Começa com capacidade 100.

  array_list_int* new_list = (array_list_int*)malloc(sizeof(array_list_int));
  // Avisa se a alocação deu certo
  if (new_list == NULL) 
    return NULL;

  new_list->data = (int*)malloc(sizeof(int) * 8); //Iniciando com 100
  if (new_list->data == NULL) {  //Se não der pra criar, retorna null
    return NULL; 
  }

  //Atualizando os parâmetros do ponteiro
  new_list->size = 0;
  new_list->capacity = 8;
  return new_list; //Retorna o ponteiro da list

  /////////////////////Big(O)= O(1)///////////////////
}

int array_list_get(array_list_int* list, int index, int* error){
  *error = 0;
  if (index < 0 || index >= list->size) {
    *error = 1;
    return 0;
  }
  return list->data[index];
  /////////////////////Big(O)= O(1)///////////////////
}

unsigned int array_list_push_back(array_list_int* list, int value) {
  if (list->capacity == list->size) {
    if (!increase_memory(list)) 
      return array_list_size(list);
  }
  list->data[list->size] = value;
  list->size++;
  return array_list_size(list);

  /////////////////////Big(O)= O(n)///////////////////
  //Como ela usa a função increase_memory(list), a qual pe o(n), isso vai aumentar o tempo de execução que seria o(1), para um tempo linear.
}


unsigned int array_list_pop_back(array_list_int* list) {
  //Aui vê se a lista ta vazia, por que se tiver, não se remove nada.
  if(list == NULL || list -> size == 0){
    return 0;
  }
  //Se não, retira o último elemento.
  list->size--;
  return array_list_size(list);
  /////////////////////Big(O)= O(1)///////////////////
  //Pois para retirar o ultimo elemento ele não percorre
  //todos os elementos, apenas decrementa no final.


}

unsigned int array_list_size(array_list_int* list) {
  //Vê se a lista está vazia, se tiver, vai retornar 0.
  if (list == NULL){
    return 0;
  }
  //Se não, retorna o tamanho.
  return list->size;
  /////////////////////Big(O)= O(1)///////////////////
}


int array_list_find(array_list_int* list, int element) {
  //Retorna -1 se a lista é vazia.
  if (list == NULL) {
    return -1; 
  }
  //Retorna indice do elemento.
  for (int i = 0; i < list->size; i++) {
    if (list->data[i] == element) {
      return i; 
    }
  }
  return -1; 
  /////////////////////Big(O)= O(n)///////////////////
  // Nessa operação, ele percorre todo o vetor até achar
  //o elemento, ou seja, se ele tiver no final, vai procurar n vezes.
}


unsigned int array_list_insert_at(array_list_int* list, int index, int value) {

  // Retorna o tamanho atual do vetor se a lista é NULL ou o índice é inválido
  if (list == NULL || index < 0 || index > list->size) {

    return array_list_size(list); 

  }

  // Verifica se é necessário aumentar a capacidade do vetor
  if (list->capacity == list->size) {
    if (!increase_memory(list)) {
      return array_list_size(list); 
    }
  }

  // Aloca para a direita para receber o novo elemento
  for (int i = list->size - 1; i >= index; i--) {
    list->data[i + 1] = list->data[i];
  }

  // Insere o novo elemento no índice especificado
  list->data[index] = value;
  list->size++; // Incrementa o tamanho do vetor

  return array_list_size(list); 

/////////////////////Big(O)= O(n)///////////////////
  // Nessa operação, pode ser necessário que ele atualize os elementos no pior caso.

}


unsigned int array_list_remove_from(array_list_int* list, int index) {
  //Retorna o tamanho atual do vetor se a lista é NULL ou o índice é inválido
  if (list == NULL || index < 0 || index >= list->size) {
    return array_list_size(list); 
  }

  // Desloca os elementos à esquerda a partir do índice para preencher o espaço do elemento removido
  for (int i = index; i < list->size - 1; i++) {
    list->data[i] = list->data[i + 1];
  }

  list->size--; // Decrementa o tamanho do vetor
  return array_list_size(list); // Retorna o tamanho atual

  /////////////////////Big(O)= O(n)///////////////////
  // Nessa operação, pode ser necessário que ele vá até o final para achar de onde ele quer tirar.
}

unsigned int array_list_capacity(array_list_int* list) {
  if (list == NULL) {
    return 0; 
  }
  return list->capacity; // Retorna a capacidade atual do vetor
  /////////////////////Big(O)= O(1)///////////////////

}


double array_list_percent_occupied(array_list_int* list) {

  if (list == NULL) {
    return 0.0; 
  }

  double occupied_percent = ((double)list->size / (double)list->capacity) * 100.0;
  return occupied_percent; // Retorna a porcentagem de ocupação do vetor
  /////////////////////Big(O)= O(1)///////////////////
}


void array_list_destroy(array_list_int* list) {
   if (list != NULL) {
    if (list->data != NULL) {
      free(list->data); // Libera a memória do array data
    }
    free(list); // Libera a memória da estrutura array_list_int
  }

}