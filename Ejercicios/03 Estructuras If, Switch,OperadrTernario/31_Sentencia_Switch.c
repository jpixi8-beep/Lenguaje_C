/* Sentencia Switch */
#include <stdio.h>

int main() {
    int opcion;
    puts("Selecciona una opción:\n1. Opción 1\n2. Opción 2\n3. Opción 3\n");
    scanf("%i", &opcion);

    switch (opcion) {
        case 1:
            printf("Elegiste la opción 1.\n");
            break;
        case 2:
            printf("Elegiste la opción 2.\n");
            break;
        case 3:
            printf("Elegiste la opción 3.\n");
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}