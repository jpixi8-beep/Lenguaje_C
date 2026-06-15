#include <stdio.h>
int main (){
    float num;
    puts("Ingrese un número; ");
    scanf("%f",&num);
    if (num > 0)
        puts("El número es positivo");
    else if (num < 0)
        puts("El número es negativo");
    else
        puts("El número es cero");
    return 0;
    //operador ternario
    //num > 0 ? puts("El número es positivo") : num < 0 ? puts("El número es negativo") : puts("El número es cero");
}