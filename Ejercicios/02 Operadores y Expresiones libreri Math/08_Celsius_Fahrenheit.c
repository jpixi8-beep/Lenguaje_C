//De celsius a farenheit
#include <stdio.h>
int main(){
    float celsius, farenheit;
    printf("Ingrese la temperatura en celsius: ");
    scanf("%f", &celsius);
    farenheit = (celsius * 9/5) + 32;
    printf("La temperatura en farenheit es: %.2f", farenheit);
    return 0;
}