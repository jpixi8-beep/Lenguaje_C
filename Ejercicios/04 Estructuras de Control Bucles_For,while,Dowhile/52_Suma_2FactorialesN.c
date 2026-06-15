#include <stdio.h>
int main(){
    int fact1, fact2, suma;
    puts("Ingrase los dos factoriales;");
    scanf("%i, %i", &fact1, &fact2);
    for(int i=1; i<=fact1; i++){
        fact1*=i;
    }
    for(int i=1; i<=fact2; i++){
        fact2*=i;
    }
    suma=fact1+fact2;
    printf("La suma de los factoriales es: %i", suma);
    return 0;
}