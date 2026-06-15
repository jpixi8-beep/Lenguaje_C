#include <stdio.h>
int main(){
    float precio, descuento, precioFinal;
    printf("Ingrese el precio original del producto: ");
    scanf("%f", &precio);
    printf("Ingrese el porcentaje de descuento: ");
    scanf("%f", &descuento); 
    precioFinal = precio - (precio * descuento / 100);
    printf("El precio final del producto es: %.2f", precioFinal);
    return 0;
}