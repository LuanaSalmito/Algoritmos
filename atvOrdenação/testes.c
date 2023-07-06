void selecao(int a[], int t){
    int i, j, min, temp;
    for (i = 0; i < t - 1; i++){
        min = i;
        for (j = i + 1; j < t; j++){
            if (a[j] < a[min]){
                min = j;
            }
        }
        if (min != i){
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void insercao(int a[], int t){
    int i, j, key;
    for (i = 1; i < t; i++){
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
