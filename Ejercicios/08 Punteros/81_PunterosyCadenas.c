#include <stdio.h>

int main(void)
{
    char str[] = "Hola mundo!";
    char *ptr = str;//El puntero ptr apunta al primer elemento del arreglo str, que es el caracter 'H'.

    printf("Caracteres de la cadena: ");
    while (*ptr != '\0')
    {//El bucle while continúa hasta que se encuentra el carácter nulo '\0', que indica el final de la cadena.
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");
    return 0;
}
