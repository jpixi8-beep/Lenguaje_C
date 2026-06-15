#include <stdio.h>
int main(){
    float horasTrabajadas, salarioPorHora, salarioTotal;
    printf("Ingrese las horas trabajadas: ");
    scanf("%f", &horasTrabajadas);
    printf("Ingrese el salario por hora: ");
    scanf("%f", &salarioPorHora);
    salarioTotal = horasTrabajadas * salarioPorHora;
    printf("El salario total del empleado es: %.2f", salarioTotal);
    return 0;
}