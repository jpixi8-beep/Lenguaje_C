#include <stdio.h>

// 🔹 Variable global: declarada fuera de cualquier función, accesible en todo el programa
int variableGlobal = 100;

// 🔹 Constante global: valor fijo que no puede cambiar
const double PI = 3.14159;

int main() {
    // 🔹 Variable local: declarada dentro de una función, solo existe en ese ámbito
    int variableLocal = 42;

    // 🔹 Constante local: valor fijo dentro de la función
    const char LETRA = 'A';

    // 🔹 Otros tipos de datos básicos
    char c = 'e';
    short s = -15;
    int i = 1024;
    unsigned int ui = 128;
    long l = 123456;
    float f = 15.678;
    double d = 123123.123123;
    long double ld = 1e-8;

    printf("=== VARIABLES Y CONSTANTES EN C ===\n\n");

    // Variables globales
    printf("Variable Global -> Declarada fuera de main, accesible en todo el programa\n");
    printf("Tipo: int\tTamaño: %zu bytes\tContenido: %d\n\n", sizeof(variableGlobal), variableGlobal);

    // Constantes globales
    printf("Constante Global -> Declarada fuera de main, valor fijo\n");
    printf("Tipo: double\tTamaño: %zu bytes\tContenido: %.5lf\n\n", sizeof(PI), PI);

    // Variables locales
    printf("Variable Local -> Declarada dentro de main, solo existe en este ámbito\n");
    printf("Tipo: int\tTamaño: %zu bytes\tContenido: %d\n\n", sizeof(variableLocal), variableLocal);

    // Constantes locales
    printf("Constante Local -> Declarada dentro de main, valor fijo\n");
    printf("Tipo: char\tTamaño: %zu bytes\tContenido: %c\n\n", sizeof(LETRA), LETRA);

    // Tipos básicos
    printf("Tipo: char\t\tTamaño: %zu bytes\tContenido: %c\n", sizeof(c), c);
    printf("Tipo: short\t\tTamaño: %zu bytes\tContenido: %i\n", sizeof(s), s);
    printf("Tipo: int\t\tTamaño: %zu bytes\tContenido: %i\n", sizeof(i), i);
    printf("Tipo: unsigned int\tTamaño: %zu bytes\tContenido: %u\n", sizeof(ui), ui);
    printf("Tipo: long\t\tTamaño: %zu bytes\tContenido: %li\n", sizeof(l), l);
    printf("Tipo: float\t\tTamaño: %zu bytes\tContenido: %.3f\n", sizeof(f), f);
    printf("Tipo: double\t\tTamaño: %zu bytes\tContenido: %.6lf\n", sizeof(d), d);
    printf("Tipo: long double\tTamaño: %zu bytes\tContenido: %.10Lf\n", sizeof(ld), ld);

    return 0;
}
