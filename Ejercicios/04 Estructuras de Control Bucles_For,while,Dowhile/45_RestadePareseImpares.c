#include <stdio.h>
int main() {
    int limit,cont=0,pares,impares,resta;
    printf("Ingrese el limite: ");
    scanf("%i", &limit);
    while (cont < limit) {
        (cont % 2 == 0) ? (pares += cont) : (impares += cont);
        cont++;
    }
    resta = pares - impares;
    printf("La resta de los pares menos los impares es: %i", resta);
    return 0;
}