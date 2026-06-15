#include <stdio.h>
int main(){
    int conteo, totalnums, sum=0;
    printf("Ingrese la cantidad de numeros a sumar: ");
    scanf("%d", &totalnums);
    while (conteo <= totalnums)
    {
        sum += conteo;
        conteo++;
    }
    printf("La suma de los numeros es: %d\n", sum);
    return 0;
}