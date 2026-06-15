#include <stdio.h>

int main()//Lista de animales
{
    char *animales[3]={"Perro","Gato","Pajaro"};//el arreglo tipo char debe tener * cuando almacena cadenas esto debido a que cada cadena es un arreglo de caracteres y el nombre del arreglo es un puntero al primer elemento del arreglo, por lo tanto, se utiliza char * para indicar que es un puntero a una cadena de caracteres.
    printf("%s\n", animales[0]);//Imprime el primer animal del arreglo (Perro)
    printf("%s\n", animales[1]);//Imprime el segundo animal del arreglo (Gato)
    printf("%s\n", animales[2]);//Imprime el tercer animal del arreglo (Pajaro)
    return 0;
}