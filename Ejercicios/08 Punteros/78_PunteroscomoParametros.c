#include <stdio.h>
void incrementar(int *valor)
{
    (*valor)++;//Utilizamos el operador de incremento para aumentar el valor al que apunta el puntero.
}
int main()
{
    int numero = 5;
    incrementar(&numero);//Llamamos a la función incrementar pasando la dirección de la variable numero utilizando el operador &.
    printf("Valor incrementado: %d\n", numero);//Imprimimos el valor incrementado de la variable numero, que ahora es 6.
    return 0;  
}