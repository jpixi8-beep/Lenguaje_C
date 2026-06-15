#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Ejercicio 65: Asignación Básica con malloc y free
 * Objetivo: Comprender la asignación dinámica de memoria
 * Contenido: Usar malloc para crear espacios en memoria y free para liberar
 */

typedef struct {
    int id;
    char nombre[50];
    float salario;
} Empleado;

int main() {
    // Asignación de un empleado dinámicamente
    Empleado *emp = (Empleado *)malloc(sizeof(Empleado));
    
    if (emp == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return 1;
    }
    
    // Asignación de datos
    emp->id = 1;
    strcpy(emp->nombre, "Juan Pérez");
    emp->salario = 2500.50;
    
    printf("=== Empleado ===\n");
    printf("ID: %d\n", emp->id);
    printf("Nombre: %s\n", emp->nombre);
    printf("Salario: $%.2f\n", emp->salario);
    
    // Liberar memoria
    free(emp);
    emp = NULL;
    
    printf("\nMemoria liberada correctamente\n");
    
    return 0;
}
