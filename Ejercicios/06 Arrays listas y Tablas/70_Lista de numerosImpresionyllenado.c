//Lista de numeros
#include <stdio.h>

int main() {
    int numeros[5]; // Declaración de un arreglo de enteros con capacidad para 5 elementos

    // Solicitar al usuario que ingrese 5 números
    printf("Ingrese 5 numeros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]); // Leer el número ingresado por el usuario y almacenarlo en el arreglo
    }

    // Mostrar los números ingresados
    printf("\nLos numeros ingresados son:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]); // Imprimir cada número del arreglo
    }
    printf("\n");

    return 0;
}