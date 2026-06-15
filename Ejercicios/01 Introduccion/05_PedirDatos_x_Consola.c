#include <stdio.h>
int main(){
    int a;
    float b;
    char c;
    char nombre[50];
    char nombreCompleto[100];

    printf("Ingrese un numero entero: ");
    scanf("%i", &a);
    printf("Ingrese un numero decimal: ");
    scanf("%f", &b);
    printf("Ingrese un character: ");
    scanf(" %c", &c);
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    //El scanf solo lee hasta el primer espacio, por lo que si el nombre tiene espacios, solo se guardará la primera parte. Para leer nombres con espacios, se puede usar fgets() gets() en lugar de scanf().
    printf("Valor a: %i\n Valor b: %.2f\n Valor c: %c\n Nombre: %s\n", a, b, c, nombre);
    printf("Ingrese su nombre completo: ");
    gets(nombreCompleto);
    printf("Nombre completo: %s\n", nombreCompleto);
    return 0;   
}