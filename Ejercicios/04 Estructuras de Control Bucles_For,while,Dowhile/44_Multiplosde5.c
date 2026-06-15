#include <stdio.h>
int main(){
    int i=1, num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    while (i<=num)
    {
        if (i%5==0)
        {
            printf("%d ", i);
        }
        i++;
    }
    return 0;

}