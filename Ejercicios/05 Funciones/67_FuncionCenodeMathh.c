//Programa qe muestra el uso de funcion seno de math.h
#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
int main()
{    double angulo, resultado;
    printf("Ingrese un angulo en grados: ");
    scanf("%lf", &angulo);
    
    // Convertimos el ángulo de grados a radianes
    double radianes = angulo * (M_PI / 180.0);
    
    // Calculamos el seno del ángulo utilizando la función sin de math.h
    resultado = sin(radianes);
    
    printf("El seno de %.2lf grados es: %.4lf\n", angulo, resultado);
    
    return 0;
}