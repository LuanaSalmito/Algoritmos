#include <stdio.h>

void lervertor(int vetor[], int n){

    int i;
    for(i = 0; i < n; i){
        scanf("%d", &vetor[i]);
    }
    
}
void verificanum(int vetor[], int n, int v){
    int i,num=0;
    for(i = 0; i < n;i++){
        if (vetor[i]==v)
        {
            num = vetor[i];
            printf("Sim");
        }
        else{
            printf("Não");
        }
    }
}



int main(){

    int n,v;

    printf("Digite o numero elementos:\n");
    scanf("%d", &n);
    printf("Digite o número o qual deseja encontrar:\n");
    scanf("%d", &v);

    int vetor[n];

    lervertor(vetor, n);
    verificanum(vetor, n, v);

    return 0;
}