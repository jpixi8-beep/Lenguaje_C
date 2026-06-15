#include <stdio.h>

int main (){
    char signo;
    printf("Ingrese un signo: ");
    gets(signo);
    if (strcmp(signo,"aries")==0)
    {
        printf("El signo es Aries\n");
    } else if (strcmp(signo,"tauro")==0)
    {
        printf("El signo es Tauro\n");
    } else if (strcmp(signo,"geminis")==0)
    {
        printf("El signo es Geminis\n");
    } else if (strcmp(signo,"cancer")==0)
    {
        printf("El signo es Cancer\n");
    } else if (strcmp(signo,"leo")==0)
    {
        printf("El signo es Leo\n");
    } else if (strcmp(signo,"virgo")==0)
    {
        printf("El signo es Virgo\n");
    } else if (strcmp(signo,"libra")==0)
    {
        printf("El signo es Libra\n");
    } else if (strcmp(signo,"escorpio")==0)
    {
        printf("El signo es Escorpio\n");
    } else if (strcmp(signo,"sagitario")==0)
    {
        printf("El signo es Sagitario\n");
    } else if (strcmp(signo,"capricornio")==0)
    {
        printf("El signo es Capricornio\n");
    } else if (strcmp(signo,"acuario")==0)
    {
        printf("El signo es Acuario\n");
    }
        else
        {
            printf("El signo no es valido\n");
        }
    return 0;
  
    
}