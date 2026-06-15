#include <stdio.h>
float sumar(float a, float b)
{
    return a + b;
}
float restar(float a, float b)
{
    return a - b;
}
float multiplicar(float a, float b)
{
    return a * b;
}
float dividir(float a, float b)
{
    return a / b;
}
int main()
{
    float num1, num2;
    char operador;
    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese el operador (+, -, *, /): ");
    scanf(" %c", &operador);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
    
    switch(operador)
    {
        case '+':
            printf("Resultado: %.2f\n", sumar(num1, num2));
            break;
        case '-':
            printf("Resultado: %.2f\n", restar(num1, num2));
            break;
        case '*':
            printf("Resultado: %.2f\n", multiplicar(num1, num2));
            break;
        case '/':
            if(num2 != 0)
                printf("Resultado: %.2f\n", dividir(num1, num2));
            else
                printf("Error: Division por cero no permitida.\n");
            break;
        default:
            printf("Operador no valido.\n");
    }
    
    return 0;
}