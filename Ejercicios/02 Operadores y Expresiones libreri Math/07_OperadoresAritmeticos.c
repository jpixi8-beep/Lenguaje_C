#include <stdio.h>
int main() {
    int num1, num2;

    // Pedir al usuario que ingrese dos números
    printf("Ingrese el primer número: ");
    scanf("%i", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%i", &num2);

    // Realizar las operaciones aritméticas
    int suma = num1 + num2;
    int resta = num1 - num2;
    int multiplicacion = num1 * num2;
    float division = (num2 != 0) ? (num1 / num2) : 0; // Evitar división por cero
    float modulo = (num2 != 0) ? (num1 % num2) : 0; // Evitar módulo por cero

    // Mostrar los resultados
    printf("Suma: %i\n", suma);
    printf("Resta: %i\n", resta);
    printf("Multiplicación: %i\n", multiplicacion);
    if (num2 != 0) {
        printf("División: %f\n", division);
        printf("Módulo: %f\n", modulo);
    } else {
        printf("No se puede dividir por cero ni calcular el módulo por cero.\n");
    }

    return 0;
} 