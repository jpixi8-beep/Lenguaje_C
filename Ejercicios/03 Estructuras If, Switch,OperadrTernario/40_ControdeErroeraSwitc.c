//Control de errores con switch
#include <stdio.h>
int main(){
    int opc;
    puts("Menu:\n1.Error 1\n2.Error 2\n3.Error 3\n");
    scanf("%i",&opc);   
    switch (opc)
    {
    case 1:
        puts("Error 1: No se pudo conectar a la base de datos");
        break;
    case 2:
        puts("Error 2: No se pudo encontrar el archivo");
        break;
    case 3:
        puts("Error 3: No se pudo abrir el archivo");
        break;
    default:
        puts("Opcion no valida");
        break;
    }
    return 0;
}