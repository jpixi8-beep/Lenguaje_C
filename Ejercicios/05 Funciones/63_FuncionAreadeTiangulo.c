#include <stdio.h>
int areaTriangulo(float base, float altura)
{
    return (base * altura) / 2;
}
int main()
{
    float base, altura, area;
    printf("Ingrese la base del triangulo: ");
    scanf("%f", &base);
    printf("Ingrese la altura del triangulo: ");
    scanf("%f", &altura);
    area = areaTriangulo(base, altura);
    printf("El area del triangulo es: %.2f\n", area);
    return 0;
}