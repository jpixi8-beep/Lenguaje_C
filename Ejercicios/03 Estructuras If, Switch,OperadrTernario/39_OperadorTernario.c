//Par o impar Operador Ternario
#include <stdio.h>
int main()
{
    int num;
    puts("Ingrese un numero: ");
    scanf("%i", &num);
    (num % 2 == 0) ? printf("El numero es par") : printf("El numero es impar");
    return 0;
}