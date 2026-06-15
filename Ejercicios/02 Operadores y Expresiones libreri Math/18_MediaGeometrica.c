//Programa para sacar la media geométrica de una cantidad desconocida de números
#include <stdio.h>
#include <math.h>
int main() {
    int n, i;
    double num, producto = 1.0, mediaGeometrica;
    printf("Ingrese la cantidad de números: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Ingrese el número %d: ", i + 1);
        scanf("%lf", &num);
        producto *= num; // Multiplicamos cada número al producto total
    }
    mediaGeometrica = pow(producto, 1.0 / n); // Calculamos la raíz n-ésima del producto
    printf("La media geométrica es: %.2lf\n", mediaGeometrica);
    return 0;
}