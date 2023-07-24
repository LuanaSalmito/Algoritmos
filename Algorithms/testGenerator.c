#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10000000;

    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", rand());
    }

   
    return 0;
}
