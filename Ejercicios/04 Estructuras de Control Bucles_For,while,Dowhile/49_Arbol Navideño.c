#include<stdio.h>

int main(){
 int n,x,y,e;
 printf("Digite la cantidad de filas: ");scanf("%i",&n);
 for(x=1;x<=n;x++){
  for(e=1;e<=n-x;e++){
   printf(" "); 
  }
  for(y=1;y<=x;y++){
   printf("* ");
  }printf("\n");
 } 
 return 0;
}