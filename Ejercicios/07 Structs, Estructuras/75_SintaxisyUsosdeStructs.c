//Sintaxis y uso de Structs en c
#include <stdio.h>

//Definicion de un struct
struct Persona {
    char nombre[50];
    int edad;
    float altura;
};

int main() {
    //Creacion de una variable de tipo struct Persona
    struct Persona persona1;

    //Asignacion de valores a los campos del struct
    printf("Ingrese el nombre: ");
    fgets(persona1.nombre, sizeof(persona1.nombre), stdin);
    printf("Ingrese la edad: ");
    scanf("%d", &persona1.edad);
    printf("Ingrese la altura: ");
    scanf("%f", &persona1.altura);

    //Impresion de los valores almacenados en el struct
    printf("\nDatos de la persona:\n");
    printf("Nombre: %s", persona1.nombre);
    printf("Edad: %d\n", persona1.edad);
    printf("Altura: %.2f\n", persona1.altura);

    return 0;
}