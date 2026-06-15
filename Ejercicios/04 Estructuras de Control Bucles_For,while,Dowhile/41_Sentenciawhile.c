#include <stdio.h>
int main(){
    int nums, i=1;
    printf("Ingrese una cantidad de numeros: ");
    scanf("%i", &nums);
    while (i<=nums)
    {
        if (i%3==0)
        {
            printf("%i ", i);
        }
        i++;
        }
        
    }
    