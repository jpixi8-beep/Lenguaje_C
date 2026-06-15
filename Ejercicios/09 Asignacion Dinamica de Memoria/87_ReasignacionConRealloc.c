#include <stdio.h>
#include <stdlib.h>

/*
 * Ejercicio 68: Reasignación de Memoria con realloc
 * Objetivo: Usar realloc para redimensionar bloques de memoria previamente asignados
 * Contenido: malloc, realloc, free, manejo dinámico de arrays
 */

int main() {
    int *numeros = NULL;
    int capacidad = 0;
    int cantidad = 0;
    int opcion, valor;
    
    printf("=== Gestor Dinámico de Números ===\n\n");
    
    while (1) {
        printf("\n1. Agregar número\n2. Mostrar números\n3. Expandir capacidad\n4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                if (cantidad >= capacidad) {
                    // Expandir capacidad
                    int nuevaCapacidad = (capacidad == 0) ? 5 : capacidad * 2;
                    int *temp = (int *)realloc(numeros, nuevaCapacidad * sizeof(int));
                    
                    if (temp == NULL) {
                        printf("Error: No se pudo reasignar memoria\n");
                        free(numeros);
                        return 1;
                    }
                    
                    numeros = temp;
                    capacidad = nuevaCapacidad;
                    printf("Capacidad expandida a %d\n", capacidad);
                }
                
                printf("Ingrese el número: ");
                scanf("%d", &valor);
                numeros[cantidad] = valor;
                cantidad++;
                printf("Número agregado. Cantidad: %d/%d\n", cantidad, capacidad);
                break;
                
            case 2:
                if (cantidad == 0) {
                    printf("No hay números agregados\n");
                } else {
                    printf("Números almacenados: ");
                    for (int i = 0; i < cantidad; i++) {
                        printf("%d ", numeros[i]);
                    }
                    printf("\nCapacidad: %d, Cantidad: %d\n", capacidad, cantidad);
                }
                break;
                
            case 3: {
                printf("Nueva capacidad: ");
                int nuevaCap;
                scanf("%d", &nuevaCap);
                
                if (nuevaCap < cantidad) {
                    printf("Error: La nueva capacidad no puede ser menor que %d\n", cantidad);
                    break;
                }
                
                int *temp = (int *)realloc(numeros, nuevaCap * sizeof(int));
                if (temp == NULL) {
                    printf("Error: No se pudo reasignar memoria\n");
                    break;
                }
                
                numeros = temp;
                capacidad = nuevaCap;
                printf("Capacidad ajustada a %d\n", capacidad);
                break;
            }
                
            case 4:
                free(numeros);
                printf("Memoria liberada. ¡Hasta luego!\n");
                return 0;
                
            default:
                printf("Opción inválida\n");
        }
    }
    
    return 0;
}
