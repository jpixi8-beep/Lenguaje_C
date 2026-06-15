//De mayusculas a minuzculaz utilizando punteros
#include <stdio.h>
#include <ctype.h>
void convertirAMinusculas(char *cadena)
{
    while(*cadena)
    {
        *cadena = tolower(*cadena);//Utilizamos la función tolower de la biblioteca ctype.h para convertir cada carácter a minúscula.
        cadena++;
    }
}
int main()
{
    char texto[100];
    printf("Ingrese un texto en mayusculas: ");
    fgets(texto, sizeof(texto), stdin);//Leemos una línea de texto ingresada por el usuario y la almacenamos en el arreglo texto.
    convertirAMinusculas(texto);//Llamamos a la función convertirAMinusculas para convertir el texto ingresado a minúsculas.
    printf("Texto en minusculas: %s\n", texto);//Imprimimos el texto convertido a minúsculas.
    return 0;
}