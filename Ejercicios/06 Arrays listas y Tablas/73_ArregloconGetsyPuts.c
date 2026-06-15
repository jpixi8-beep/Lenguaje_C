//Pide nombre y saluda utilizando arreglo puts y gets
#include <stdio.h>

int main()
{
    char nombre[50];//Declaramos un arreglo de caracteres para almacenar el nombre del usuario, con un tamaño de 50 caracteres.
    printf("Ingrese su nombre: ");//Solicitamos al usuario que ingrese su nombre.
    gets(nombre);//Utilizamos la función gets para leer la entrada del usuario y almacenarla en el arreglo nombre. (Nota: gets es inseguro y no se recomienda su uso en programas reales debido a posibles desbordamientos de búfer).
    printf("Hola,");//Imprimimos un saludo utilizando el nombre ingresado por el usuario.
    puts(nombre);//Utilizamos la función puts para imprimir el nombre del usuario seguido de un salto de línea.
    return 0;
}