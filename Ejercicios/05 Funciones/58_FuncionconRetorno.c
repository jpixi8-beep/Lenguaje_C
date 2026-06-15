//Funcion que multiplica parametros y retorna el resultado
#include <stdio.h>  
int multiplicar(int a, int b){
    return a * b;
}
int main(){
    int resultado = multiplicar(2, 3);
    printf("El resultado de la multiplicación es: %i\n", resultado);
    return 0;
}