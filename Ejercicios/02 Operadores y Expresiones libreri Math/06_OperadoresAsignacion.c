# include <stdio.h>
int main() {
    int a = 10; // Asignación simple
    printf("Valor de a: %d\n", a);

    a += 5; // Equivalente a a = a + 5
    printf("Valor de a después de += 5: %d\n", a);

    a -= 3; // Equivalente a a = a - 3
    printf("Valor de a después de -= 3: %d\n", a);

    a *= 2; // Equivalente a a = a * 2
    printf("Valor de a después de *= 2: %d\n", a);

    a /= 4; // Equivalente a a = a / 4
    printf("Valor de a después de /= 4: %d\n", a);

    return 0;
}