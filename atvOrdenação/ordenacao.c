#include "ordenacao.h"
#include <stdio.h>

void ler_Vetor(int a[], int n){

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

}
/* Função implementada, agora so falta os métodos de ordenação para os que não estavam */

int ordenado(int a[],  int t){

    for (int i = 0; i < t - 1; i++)
    {
        if (a[i] > a[i+1])
        {
            return 0;
        } 
    }
    return 1;
    
}

/* TODO: Implementar função */
void selecao(int a[], int t){
}

/* TODO: Implementar função */
void insercao(int a[], int t){
}

int main(){
    int n;
    scanf("%d", &n);
    int array[n];
    ler_Vetor(array,n);

    int naoDecrescente = ordenado(array,n);
    
    switch (naoDecrescente){ 
    {
    case 0:
    printf("Array ainda não ordenado.\n");
    selecao(array, n);
    insercao(array,n);
    printf("Agora está ordenado.");
    break;

    case 1:
    printf("Array já estava ordenado.\n");
        break;
    }  


    return 0;
    }
}
