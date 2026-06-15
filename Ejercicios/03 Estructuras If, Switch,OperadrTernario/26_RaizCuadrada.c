#include <stdio.h>
#include <math.h>
int main (){
    float numero, raiz;
    printf("Ingrese un numero: ");
    scanf("%f", &numero);
    if (numero < 0){
        printf("el Numero %.2f tiene Raiz imaginaria, ya que es negativo\n", numero);
    } else {
        raiz = sqrt(numero);
        printf("La raiz cuadrada de %.2f es %.2f\n", numero, raiz);
    }
    return 0;
}