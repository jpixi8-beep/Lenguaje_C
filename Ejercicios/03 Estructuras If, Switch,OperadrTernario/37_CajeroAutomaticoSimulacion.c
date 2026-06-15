//Menu de cajero
#include <stdio.h>
int main(){
    int opc,saldo=1000, retiro, deposito;
    printf("Bienvenido al cajero automatico\n");
    printf("1. Consultar saldo\n");
    printf("2. Retirar dinero\n");
    printf("3. Depositar dinero\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        printf("Su saldo es: %d\n", saldo);
        break;
    case 2:
        printf("Ingrese la cantidad a retirar: ");
        scanf("%d", &retiro);
        if (retiro > saldo)
        {
            printf("No tiene suficiente saldo\n");
        }
        else
        {
            saldo -= retiro;
            printf("Su saldo actual es: %d\n", saldo);
        }
        break;
    case 3:
        printf("Ingrese la cantidad a depositar: ");
        scanf("%d", &deposito);
        saldo += deposito;
        printf("Su saldo actual es: %d\n", saldo);
        break;  
    case 4:
        printf("Gracias por usar el cajero automatico\n");
        break;
    default:
        printf("Opción no válida\n");
        break;
    }
    return 0;
}