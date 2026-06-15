
#include <stdio.h>
#include <math.h>
int main() {
    float cateto1, cateto2, hipotenusa;

    // Pedir al usuario que ingrese los valores de los catetos
    printf("Ingrese el valor los dos catetos: ");
    scanf("%f %f", &cateto1, &cateto2);

    // Calcular la hipotenusa usando el teorema de Pitágoras
    hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));

    // Mostrar el resultado
    printf("La hipotenusa es: %.2f\n", hipotenusa);

    return 0;
}