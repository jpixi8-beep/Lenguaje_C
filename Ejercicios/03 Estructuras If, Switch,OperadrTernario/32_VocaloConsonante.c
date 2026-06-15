#include <stdio.h>
int main (){
    char letra;
    puts("Este programa te ayudará a determinar si una letra es una vocal o una consonante.\nIngresa una letra: ");
    scanf(" %c", &letra);
    switch (letra)
    {
    case 'a':
        printf("Vocal a");
        break;
    case 'e':
        printf("Vocal e");
        break;
    case 'i':
        printf("Vocal i");
        break;
    case 'o':
        printf("Vocal o");
        break;
    case 'u':
        printf("Vocal u");
        break;
    default:
        printf("Consonante,Número o Digito");
        break;
    }
    return 0;
}