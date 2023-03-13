#include <stdio.h>


void select_sort(int vetor[], int tam){
    int menor, troca;


    //Aqui é tam-1 pois leva em consideração, obviamente, a posição dos índices.

    for (int i = 0; (i < tam-1); i++)
    {
        menor = i;

        //Loop para trabalhar no proximo elemento;

        for (int j = (i+1); j < tam; j++)
        {
            if(vetor[j]<vetor[menor]){
                menor=j;
            }
        }
        if(i!=menor);{
            troca=vetor[i];
            vetor[i]=vetor[menor];
            vetor[menor]=troca;
        }
    }
}

int main(){
    // Vetor desordenado;
    int vetor[6]={8,3,1,42,12,5};

    // Função de ordenação que usa select sort;
    select_sort(vetor, 6);

    // Apresentar vetor ordenado;
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", vetor[i]);
    }
    


    return 0;
}

//No geral é um algoritmo lento, pois se for um grande numero de elementos ele vai procurar de forma quadrática a solução para ordenação.