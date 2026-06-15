//Programa para ejemplificar el uso fe funciones de distintas blibiotecas de c 
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main()
{    double numero, raiz;
    printf("Ingrese un numero para calcular su raiz cuadrada: ");
    scanf("%lf", &numero);
    
    if (numero < 0) {
        printf("Error: No se puede calcular la raiz cuadrada de un numero negativo.\n");
    } else {
        raiz = sqrt(numero); // Utilizamos la función sqrt de la biblioteca math.h para calcular la raíz cuadrada del número ingresado.
        printf("La raiz cuadrada de %.2lf es %.2lf\n", numero, raiz);
    }
    char letra;
    printf("Ingrese una letra para convertirla a mayuscula: ");
    scanf(" %c", &letra);
    char letraMayuscula = toupper(letra); // Utilizamos la función toupper de la biblioteca ctype.h para convertir la letra ingresada a mayúscula.
    printf("La letra en mayuscula es: %c\n", letraMayuscula);
    
    return 0;
}
