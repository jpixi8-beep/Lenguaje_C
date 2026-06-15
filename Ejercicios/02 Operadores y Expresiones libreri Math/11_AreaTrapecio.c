
#include <stdio.h>
int main() {
    float baseMayor, baseMenor, altura, area;
    printf("Ingrese la base mayor: ");
    scanf("%f", &baseMayor);
    printf("Ingrese la base menor: ");
    scanf("%f", &baseMenor);
    printf("Ingrese la altura: ");
    scanf("%f", &altura);
    area = ((baseMayor + baseMenor) * altura) / 2;
    printf("El area del trapecio es: %.2f", area);
    return 0;
}