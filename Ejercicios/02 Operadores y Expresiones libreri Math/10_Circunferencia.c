
#include <stdio.h>
#define PI 3.14159265359
int main() {
    float radio, diametro, circunferencia;
    int opcion; 
    printf("¿Desea ingresar el radio (1) o el diámetro (2)? ");
    scanf("%d", &opcion);
    if (opcion == 1) {
        printf("Ingrese el radio: ");
        scanf("%f", &radio);
        circunferencia = 2 * PI * radio;
    } else if (opcion == 2) {
        printf("Ingrese el diámetro: ");
        scanf("%f", &diametro);
        circunferencia = PI * diametro;
    } else {
        printf("Opción no válida.\n");
        return 1; // Salir con error
    }
    printf("La circunferencia es: %.2f\n", circunferencia);
    return 0;
}