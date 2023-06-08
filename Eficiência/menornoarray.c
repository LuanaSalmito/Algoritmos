#include <stdio.h>




int main(){

    int n; 
    scanf("%d",&n);
    int array[n];

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &array[i]);  //n
    }
    

    int maior = array[0];

    for(int i = 0; i < n; i++){
        if (array[i]>maior)             //n
        {
            maior = array[i]; 
        }
    }

    printf("O maior no array é: %d.\n",maior);




    return 0;
}
