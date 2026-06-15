#include <stdio.h>
int main (){
    int limit, i=0, sum=0;
    puts("Ingresa un numero limite y yo sumare sus pares y te dire la cantidad de pares");
    scanf("%i", &limit);
    for (i = 0; i < limit; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
    }
    printf("La suma de los pares es: %i\n", sum);
    printf("La cantidad de pares es: %i\n", i);
    return 0;
}