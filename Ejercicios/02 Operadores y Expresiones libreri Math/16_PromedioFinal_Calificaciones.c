#include <stdio.h>
int main(){
    float calificacionesParciales[2], calificacionExamenFinal, calificacionTrabajoFinal, calificacionFinal;
    printf("Ingrese la calificación del primer parcial: ");
    scanf("%f", &calificacionesParciales[0]);
    printf("Ingrese la calificación del segundo parcial: ");
    scanf("%f", &calificacionesParciales[1]);
    float promedio = (calificacionesParciales[0] + calificacionesParciales[1]) / 2;
    printf("El promedio de las calificaciones Parciales es: %.2f\n", promedio);
    printf("Ingrese la calificación del examen final: ");
    scanf("%f", &calificacionExamenFinal);
    printf("Ingrese la calificación del trabajo final: ");
    scanf("%f", &calificacionTrabajoFinal);
    calificacionFinal = (promedio * 0.55) + (calificacionExamenFinal * 0.30) + (calificacionTrabajoFinal * 0.15);
    printf("La calificación final es: %.2f\n", calificacionFinal);
    return 0;
}