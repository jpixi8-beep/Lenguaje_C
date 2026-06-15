//Aplicacion de Ixa a un presio con uso de Funcion IVA
#include <stdio.h>
float calcularIVA(float precio, float iva)
{
    return precio * (iva / 100);
}
int main()
{
    float precio, iva, precioFinal;
    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);
    printf("Ingrese el IVA del producto: ");
    scanf("%f", &iva);  
    precioFinal = precio + calcularIVA(precio, iva);
    printf("El precio final del producto con IVA es: %.2f\n", precioFinal);
    return 0;
}