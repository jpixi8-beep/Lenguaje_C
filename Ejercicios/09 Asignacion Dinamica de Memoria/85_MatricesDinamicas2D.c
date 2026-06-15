#include <stdio.h>
#include <stdlib.h>

/*
 * Ejercicio 66: Matrices Dinámicas 2D
 * Objetivo: Crear y manipular matrices bidimensionales de forma dinámica
 * Contenido: malloc para filas, malloc para columnas, acceso y liberación
 */

int main() {
    int filas, columnas;
    
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);
    
    // Crear matriz dinámica
    int **matriz = (int **)malloc(filas * sizeof(int *));
    if (matriz == NULL) {
        printf("Error: No se pudo asignar memoria para las filas\n");
        return 1;
    }
    
    // Asignar memoria para cada fila
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Error: No se pudo asignar memoria para la fila %d\n", i);
            return 1;
        }
    }
    
    // Llenar la matriz
    printf("\nIngrese los valores de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Mostrar la matriz
    printf("\n=== Matriz Ingresada ===\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%5d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Liberar memoria (importante: primero filas, luego el array de filas)
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    printf("\nMemoria de la matriz liberada correctamente\n");
    
    return 0;
}
