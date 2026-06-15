//Quicksort para ordenar lista de numeros
#include <stdio.h>
void quicksort(int lista[], int n){
    int pivote = lista[0];
    int izq[n], der[n];
    int i=0, j = 0, k = 0;
    if (n<=1) return 0;
    for (int i = 1; i < n; i++){
    if (lista[i]<pivote) 
        izq[j++] = lista[i];
    else 
        der[k++] = lista[i];    
    }
    quicksort(izq, j);
    quicksort(der, k);
    for (i = 0; i < j; i++) lista[i] = izq[i];
    lista[j] = pivote;
    for (i = i+1; i < n; i++) lista[i] = der[i-j-1];
}
int main (){
    int nums[]={23,45,16,37,3};
    int n= sizeof(nums)/sizeof(nums[0]);

    quicksort(nums,n);

    int i;
    for ( i = 0; i < n; i++) printf("%d",nums[i]);
    return 0;    
}