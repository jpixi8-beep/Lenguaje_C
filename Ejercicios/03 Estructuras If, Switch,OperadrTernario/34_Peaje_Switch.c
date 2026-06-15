//Peajes

#include <stdio.h>
#define Peaje_Turismo 500
#define Peaje_Autobus 3000
#define Peaje_Moto 5000

int main (){
    puts("Este programa te ayudará a calcular el costo del peaje según el tipo de vehículo.");
    char tipoVehiculo;
    printf("Ingresa el tipo de vehículo (T para Turismo, A para Autobús, M para Moto): ");
    scanf(" %c", &tipoVehiculo);
    switch (tipoVehiculo)
    {
    case 'T':
        printf("El costo del peaje para Turismo es: %d\n", Peaje_Turismo);
        break;
    case 'A':
        printf("El costo del peaje para Autobús es: %d\n", Peaje_Autobus);
        break;
    case 'M':
        printf("El costo del peaje para Moto es: %d\n", Peaje_Moto);
        break;
    default:
        printf("Tipo de vehículo no válido. Por favor ingresa T, A o M.\n");
        break;
    }
    return 0;
}