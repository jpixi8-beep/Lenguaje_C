
#include <stdio.h>
int main() {
   float examen;
    printf("Ingrese la nota del examen: ");
    scanf("%f", &examen);
    if (examen >= 6.0)
        puts("¡Aprobado!");
    return 0;   
}