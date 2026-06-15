//Hacer un programa que calcule la media aritmética de tres números ingresados por el usuario.3
#include <stdio.h>
int main()
{
    float num1, num2, num3, promedio;
    printf("Ingrese los tres números separados por espacios: ");
    scanf("%f %f %f", &num1, &num2, &num3);
    
    promedio = (num1 + num2 + num3) / 3;
    
    printf("La media aritmética de los tres números es: %.2f\n", promedio);
    
    return 0;
}