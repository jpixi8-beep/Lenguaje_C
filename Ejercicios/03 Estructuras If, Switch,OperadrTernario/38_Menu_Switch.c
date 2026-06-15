#include <stdio.h>
int main()
{
    int opc, num, RES;
    puts("Menu:\n1.Cubo de un numero Par\n2. NumeroPar o Impar\n3. Terminar\nIngrese una opcion: ");
    scanf("%i", &opc);
    puts("Ok, AhoraIngrese un numero: ");
    scanf("%i", &num);
    switch (opc)
    {
    case 1:
        RES = num * num * num;
        printf("El cubo de %i es: %i", num, RES);
        break;
    case 2:
        if (num % 2 == 0)
        {
            printf("El numero es par");
        }
        else
        {
            printf("El numero es impar");
        }
        break;
    case 3:
        printf("Saliendo del programa...");
        break;
    default:
        printf("Opcion no valida");
        break;
    }
    return 0;
}