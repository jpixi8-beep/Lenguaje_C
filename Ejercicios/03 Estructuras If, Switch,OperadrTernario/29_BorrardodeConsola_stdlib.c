#include <stdio.h>
#include <stdlib.h>

int main (){
    char tecla;
    puts("Este programa borra la consola\nCuando presiones i\n Digita una tecla");
    scanf("%c", &tecla);
    if (tecla == 'i') {
        system("cls");//Borrando la consola
    }else {
        puts("presionaste una tecla diferente a i, no se borra la consola Intenta de nuevo\nborrandoBuffer de entrada");
        fflush(stdin);//Borrando el buffer de entrada
        puts("Digita una tecla");
        scanf("%c", &tecla);
        if (tecla == 'i') {
            system("cls");//Borrando la consola
        }

    }
    return 0;
}
