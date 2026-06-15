//Factorial de un numero con Fro
#include <stdio.h>
int main(){
 int i,num,fact=1;
 printf("Digite un numero: ");scanf("%i",&num);
 for(i=1;i<=num;i++){
  fact*=i;
 }
 printf("El factorial de %i es: %i",num,fact);
 return 0;
}