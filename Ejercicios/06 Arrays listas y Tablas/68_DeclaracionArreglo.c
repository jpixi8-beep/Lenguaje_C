//Declaracion de arreglo sintaxis basica y es de frutas
#include <stdio.h>

int main()
{
    char *frutas[3]={"Manzana","Banana","Naranja"};//Declaramos un arreglo de punteros a caracteres llamado frutas, que puede almacenar 3 cadenas de texto. Cada elemento del arreglo es un puntero a una cadena de caracteres (string).
    for(int i=0; i<3; i++)
    {
        printf("%s\n", frutas[i]);//Imprime cada fruta del arreglo utilizando un bucle for para iterar a través de los elementos del arreglo.
    }
    return 0;
}