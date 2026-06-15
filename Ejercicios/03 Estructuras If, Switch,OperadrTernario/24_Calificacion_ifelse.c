#include <stdio.h>
int main(){
    float promedio_final;
    puts("Ingrese el promedio final del alumno: ");
    scanf("%f",&promedio_final);
    if (promedio_final>=6.0)
        puts("¡Aprobado!");
    else
        puts("¡Reprobado!");
}