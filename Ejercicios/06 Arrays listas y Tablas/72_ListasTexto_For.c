#include <stdio.h>

int main()//Lista de animales impresión con for
{
    char *animales[3]={"Perro","Gato","Pajaro"};
    int i;
    for(i=0; i<3; i++)
    {
        printf("%s\n", animales[i]);//Imprime el primer animal del arreglo (Perro)
    }
    return 0;
}