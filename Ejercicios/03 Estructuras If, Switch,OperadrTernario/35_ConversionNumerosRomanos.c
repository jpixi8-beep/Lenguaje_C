#include <stdio.h>
int main(){
    int numero,unidades,decenas,centenas,millares;
    puts("Este programa te ayudará a convertir un número entero a su equivalente en números romanos.");
    printf("Ingresa un número entero entre 1 y 3999: ");
    scanf("%d", &numero);
    if (numero < 1 || numero > 3999) {
        printf("Número fuera de rango. Por favor ingresa un número entre 1 y 3999.\n");
        return 1;
    }
    unidades = numero % 10;numero /= 10;
    decenas = numero % 10;numero /= 10;
    centenas = numero % 10;numero /= 10;
    millares = numero % 10;numero /= 10;

switch (millares)
{
case 1:
    printf("M");
    break;

case 2:
    printf("MM");
    break;

case 3:
    printf("MMM");
    break;

default:
    break;
}
switch (centenas)
{
case 1:
    printf("C");
    break;

case 2:
    printf("CC");
    break;

case 3:
    printf("CCC");
    break;  
case 4:
    printf("CD");
    break;
case 5:
    printf("D");
    break;
case 6:
    printf("DC");
    break;
case 7:
    printf("DCC");
    break;
case 8:
    printf("DCCC");
    break;
case 9:
    printf("CM");
    break;
default:
    break;
}
switch (decenas)
{       
case 1:
    printf("X");
    break;

case 2:
    printf("XX");
    break;

case 3:
    printf("XXX");
    break;

case 4:
    printf("XL");
    break;

case 5:
    printf("L");
    break;

case 6:
    printf("LX");
    break;

case 7:
    printf("LXX");
    break;

case 8:
    printf("LXXX");
    break;

case 9:
    printf("XC");
    break;

default:
    break;
}
switch (unidades)
{
case 1:
    printf("I");
    break;

case 2:
    printf("II");
    break;

case 3:
    printf("III");
    break;  
case 4:
    printf("IV");
    break;
case 5:
    printf("V");
    break;
case 6:
    printf("VI");
    break;
case 7:
    printf("VII");
    break;
case 8:
    printf("VIII");
    break;
case 9:
    printf("IX");
    break;
default:
    break;
}
printf("\n");

    return 0;
}