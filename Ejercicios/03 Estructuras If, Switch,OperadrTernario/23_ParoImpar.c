#include <stdio.h>
int main() {
    int num;
    printf("Ingrese un número entero: ");
    scanf("%d", &num);
    if (num % 2 == 0)
        puts("El número es par");
    else
        puts("El número es impar");
    return 0;   
}