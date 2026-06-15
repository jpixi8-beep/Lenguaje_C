#include <stdio.h>

struct Persona {
    char nombre[50];
    int edad;
};

int main() {
    struct Persona p1 = {"Lechugas", 25};
    struct Persona *ptr = &p1;  // puntero a la estructura

    // Acceso a miembros con -> cuando usas puntero
    printf("Nombre: %s\n", ptr->nombre);
    printf("Edad: %d\n", ptr->edad);

    return 0;
}
