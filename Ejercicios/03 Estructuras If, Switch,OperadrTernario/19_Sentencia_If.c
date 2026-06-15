
#include <stdio.h>
int main() {
    int num1, num2;
    printf("Ingrese el primer número entero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número entero: ");
    scanf("%d", &num2);
    if (num1 % num2 == 0) {
        printf("%d es divisible por %d\n", num1, num2);
    } else {
        printf("%d no es divisible por %d\n", num1, num2);
    }
    return 0;   
}