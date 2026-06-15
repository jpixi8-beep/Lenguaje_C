//Determinar si es primo o no
#include <stdio.h>
int main(){
 int n,x,e=0;
 printf("Digite un numero: ");scanf("%i",&n);
 for(x=1;x<=n;x++){
  if(n%x==0){
   e++;
  }
 }
 if(e==2){
  printf("El numero es primo");
 }else{
  printf("El numero no es primo");
 }
 return 0;
}