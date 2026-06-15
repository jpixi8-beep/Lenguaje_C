#include <stdio.h>
int main(){
    int anos, meses, dias, horas, minutos, segundos, totalSegundos;
    printf("Ingrese el número de años, meses, días, horas, minutos y segundos: ");
    scanf("%d %d %d %d %d %d", &anos, &meses, &dias, &horas, &minutos, &segundos);
    totalSegundos = (anos * 365 * 24 * 60 * 60) + (meses * 30 * 24 * 60 * 60) + (dias * 24 * 60 * 60) + (horas * 60 * 60) + (minutos * 60) + segundos;
    printf("El total de segundos es: %d\n", totalSegundos);
    return 0;
}