//Sintaxis basica y uso de Punteros en c
#include <stdio.h>

int main()
{
    int numero = 10;
    int *puntero;
    puntero = &numero;
    printf("Valor del puntero: %p\n", puntero);
    printf("Valor al que apunta el puntero: %d\n", *puntero);
    return 0;
}