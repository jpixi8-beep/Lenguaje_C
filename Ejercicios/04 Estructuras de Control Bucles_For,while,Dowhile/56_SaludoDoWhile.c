//manda saludo hasta que el usuario digite algo diferente a S con dowhile
#include <stdio.h>
int main(){
    char resp;
    do    {
        fflush(stdin);
        printf("Hola, quieres que te salude? (S/N): ");
        scanf(" %c", &resp);
    } while (resp == 'S' || resp == 's');
    return 0;
}
