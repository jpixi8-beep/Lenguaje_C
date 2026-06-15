#include <stdio.h>
int main() {
    char nota;
    printf("Ingrese la nota del alumno: ");
    scanf("%c", &nota);
    switch (nota) {
        case 'A':
            printf("Excelente");
            break;
        case 'B':
            printf("Muy Bien");
            break;
        case 'C':
            printf("Bien");
            break;
        case 'D':
            printf("Regular");
            break;
        case 'F':
            printf("Reprobado");
            break;
        default:
            printf("Nota no válida");
            break;
    }
    return 0;
}