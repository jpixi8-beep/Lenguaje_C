#include <stdio.h>
#define HondaCivicDescuento 0.05
#define YamahaR15Descuento 0.08
#define SuzukiSwiftDescuento 0.10
#define OtrasMarcasDescuento 0.02

int main (){
    puts("Este programa te ayudará a calcular el precio final de un vehículo después de aplicar un descuento basado en su marca.");
    char marca;
    float precio, descuento, precioFinal;
    printf("Ingresa la marca del vehículo: ");
    gets(marca);
    printf("Ingresa el precio del vehículo: ");
    scanf("%f", &precio);
    if(strcmp(marca, "Honda Civic") == 0){
        descuento = precio * HondaCivicDescuento;
    } else if (strcmp(marca, "Yamaha R15") == 0){
        descuento = precio * YamahaR15Descuento;
    } else if (strcmp(marca, "Suzuki Swift") == 0){
        descuento = precio * SuzukiSwiftDescuento;
    } else {
        descuento = precio * OtrasMarcasDescuento;
    }
    precioFinal = precio - descuento;
    printf("El precio final del vehículo es: %.2f\n", precioFinal);
    return 0;
}