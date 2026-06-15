//Programa sencillo que muestre claramente sin tanto comentario como es el uso de los punteros junto con la memoria dinamica en c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *puntero = (int *)malloc(sizeof(int));//Utilizamos malloc para asignar memoria dinámica para un entero y almacenamos la dirección de esa memoria en el puntero.
    if (puntero == NULL) {
        printf("Error al asignar memoria.\n");
        return 1; // Salimos del programa si no se pudo asignar memoria.
    }
    
    *puntero = 42; // Asignamos un valor al espacio de memoria al que apunta el puntero.
    printf("Valor almacenado en la memoria dinámica: %d\n", *puntero); // Imprimimos el valor almacenado utilizando el puntero.
    
    free(puntero); // Liberamos la memoria asignada para evitar fugas de memoria.
    return 0;
}