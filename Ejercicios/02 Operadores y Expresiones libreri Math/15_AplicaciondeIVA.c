#include <stdio.h>
int main(){
    float precio, iva, precioFinal, aumento;
    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);
    printf("Ingrese la tasa de IVA: ");
    scanf("%f", &iva);
    aumento = precio * iva / 100;
    precioFinal = precio + aumento;
    printf("El precio final del producto con IVA incluido es: %.2f\n", precioFinal);
    return 0;
}