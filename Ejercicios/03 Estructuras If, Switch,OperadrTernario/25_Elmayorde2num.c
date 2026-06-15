#include <stdio.h>
int main() {
    int num1,num2;
    puts("Este programa te a el mayor de dos numeros\n");
    puts("Ingrese ambos numeros separados por un espacio: ");
    scanf("%d %d",&num1,&num2);
    /*If´s anidados*/
    if (num1 > num2)
        printf("El mayor es: %d\n", num1);
    else if (num2 > num1)
        printf("El mayor es: %d\n", num2);
    else
        printf("Ambos números son iguales\n");
    return 0;   
}