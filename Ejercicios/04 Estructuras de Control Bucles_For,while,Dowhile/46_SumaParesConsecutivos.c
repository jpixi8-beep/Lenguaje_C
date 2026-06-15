#include <stdio.h>
int main (){
    int ini, fin, sum;
    printf("Ingresa el inicio;");
    scanf("%i", &ini);
    printf("Ingresa limite: ");
    scanf("%i", &fin);
    while(ini<fin){
        if(ini%2==0){
            sum += ini;
        }
        ini++;
    }
    printf("La suma de los pares consecutivos es: %i", sum);
    return 0;
}