#include <stdio.h>

int main() {
    char nombre;
    int edad;
    puts("Ingrese su nombre: ");
    gets(nombre);
    puts("Ingrese su edad: ");
    scanf("%d", &edad);
 if (edad >= 18) {
     printf("Hola, %s! Eres mayor de edad.\n", nombre);
 }
  return 0;
}