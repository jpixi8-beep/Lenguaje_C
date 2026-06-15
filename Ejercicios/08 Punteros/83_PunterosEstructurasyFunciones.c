#include <stdio.h>

struct Persona {
    char nombre[50];
    int edad;
};

void mostrar(struct Persona *p) {
    printf("Nombre: %s, Edad: %d\n", p->nombre, p->edad);
}

int main() {
    struct Persona p1 = {"Lechugas", 25};
    mostrar(&p1);  // paso puntero a la función
    return 0;
}
