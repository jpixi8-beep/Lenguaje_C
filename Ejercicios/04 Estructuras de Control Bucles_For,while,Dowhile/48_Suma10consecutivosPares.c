#include <stdio.h>
int main(){
    int i, suma=0;
    for(i=0; i<10; i+=2){
        suma += i;
    }
    printf("La suma de los 10 numeros pares consecutivos es: %i\n", suma);
    return 0;
}