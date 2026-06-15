#include <stdio.h>
int main(){
    int cantidad, anterior_anterior=0, Anterior=1, ultimo1;
    printf("Ingrese el numero de terminos: ");
    scanf("%d", &cantidad);
    printf("Serie de Fibonacci: ");
    for(int i=0; i<cantidad; i++){
        printf("%d ", anterior_anterior);
        ultimo1 = anterior_anterior + Anterior;
        anterior_anterior = Anterior;
        Anterior = ultimo1;
    }
    return 0;
}