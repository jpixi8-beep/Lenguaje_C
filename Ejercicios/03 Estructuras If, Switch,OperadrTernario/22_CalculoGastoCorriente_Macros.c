/* Calculo de Gasto Corriente 
Tarifas
1 Gasto menor a 1000: => 1.2
2 Gasto entre 1000 y 1.850: => 1.0
3 Gasto mayor a 1.850: => 0.9
*/

#include <stdio.h>
//Macros
#define TARIFA1 1.2
#define TARIFA2 1.0
#define TARIFA3 0.9

int main(){
    float gasto_Energy,tasa;
    puts("Ingrese el gasto corriente de energía: ");
    scanf("%f",&gasto_Energy);
    if (gasto_Energy<1000)
    {
        tasa=TARIFA1;
    }
    if (gasto_Energy>=1000 && gasto_Energy<=1850)
    {
        tasa=TARIFA2;
    }
    if (gasto_Energy>1850)
    {
        tasa=TARIFA3;
    }
    printf("El gasto corriente de energía es: %.2f\n", tasa);
    return 0;
}