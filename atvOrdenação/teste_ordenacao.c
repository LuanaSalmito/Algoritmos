#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "ordenacao.h"

const int SELECAO = 1;
const int INSERCAO = 2;

void print_usage(){
    printf("Programa para ordenação de números ineiros.\n\n");
    printf("\tUso: teste_ordenacao [Opção]\n");
    printf("\n");
    printf("Onde 'Opção' é uma das opções a seguir:\n\n");
    printf("\t -s: ordenação por seleção (padrão).\n");
    printf("\t -i: ordenação por inserção.\n");
    printf("\t -h: Mostra instruções de uso de programa.\n\n");
}

int define_metodo(int argc, char **argv){
    int metodo = SELECAO;
    if (argc>2){
        printf("*** Quantidade de parâmetros inválidos *** \n\n");
        print_usage();
        exit(1);
    }
    if (argc==2){
        if (strcmp(argv[1],"-h")){
          print_usage();
          exit(0);
        }
        else if (strcmp(argv[1],"-s")){
          metodo = SELECAO;
          fprintf(stderr,"Método seleção usado para ordenação.\n");
        }
        else if (strcmp(argv[1],"-i")){
          metodo = INSERCAO;
          fprintf(stderr,"Método inserção usado para ordenação.\n");
        }
        else{
            print_usage();
            exit(2);
        }
    }
    return metodo;
}

void imprime_array(int a[],int n){
  int i;
  if (n>0){
      printf("%d",a[0]);
    for (i=1 ; i<n ; ++i)
      printf(" %d",a[i]);
    printf("\n");
  }
}

int main(int argc, char **argv){
    int n,i,metodo = define_metodo(argc,argv);
    double inicio,fim,tempo_passado;
    scanf("%d",&n);
    int a[n];
    for (i=0 ; i<n ; ++i)
      scanf("%d",&a[i]);
     inicio = clock();
    switch(metodo){
        case 1: selecao(a,n);
          break;
        case 2: insercao(a,n);
          break;
    }
     fim=clock();
    tempo_passado = (fim-inicio)/CLOCKS_PER_SEC*1000;
    fprintf(stderr,"Tempo usado para ordenação: %0.4lf milisegundos.\n",tempo_passado);
    if (!ordenado(a,n)){
        fprintf(stderr,"\033[0;31mErro:\033[0m Array não ordenado. Saindo...\n");
        exit(-1);
    }
    // imprime_array(a,n);
    return 0;
}
