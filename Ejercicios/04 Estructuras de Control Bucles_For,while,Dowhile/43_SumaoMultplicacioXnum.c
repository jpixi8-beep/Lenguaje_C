#include <stdio.h>
int main()
{
    int n, res, cont=0;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    if (n < 10)
    {
        while (cont < 10)
        {
            res+=cont;
            cont++;
        }
    }
    else
    {
        while (cont < 10)
        {
            res*=cont;
            cont++;
        }
    }
    printf("El resultado es: %d", res);
    return 0;
}
 