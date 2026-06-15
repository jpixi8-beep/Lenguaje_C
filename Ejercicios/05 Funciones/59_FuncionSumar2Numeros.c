#include <stdio.h>
void sumar(int a, int b){
    printf("La suma de %i y %i es: %i\n", a, b, a + b);
}
int main(){
    sumar(1, 2);// 3
    sumar(3, 4);// 7
    return 0;
}