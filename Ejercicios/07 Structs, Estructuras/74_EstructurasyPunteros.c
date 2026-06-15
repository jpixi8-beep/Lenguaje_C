// Programa que muestra el uso de structs y punteros en C
#include <stdio.h>

struct Alumno {
    char nombre[50];
    int edad;
    float promedio;
};

// Función que recibe un puntero a Alumno y muestra sus datos
void mostrarAlumno(struct Alumno *a) {
    printf("Nombre: %s\n", a->nombre);
    printf("Edad: %d\n", a->edad);
    printf("Promedio: %.2f\n", a->promedio);
}

int main() {
    struct Alumno alumno1 = {"Lechugas", 30, 9.3};

    // Puntero a la estructura
    struct Alumno *ptr = &alumno1;

    // Acceso a miembros con ->
    printf("Accediendo con puntero:\n");
    printf("Nombre: %s\n", ptr->nombre);
    printf("Edad: %d\n", ptr->edad);
    printf("Promedio: %.2f\n", ptr->promedio);

    // Pasar puntero a función
    printf("\nUsando función mostrarAlumno:\n");
    mostrarAlumno(ptr);
    /* mejorado
    mostrarAlumno(&alumno1); también se puede pasar la dirección directamente  */
    return 0;
}
