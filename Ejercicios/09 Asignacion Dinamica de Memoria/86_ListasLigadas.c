#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Ejercicio 67: Listas Ligadas Simples
 * Objetivo: Implementar una estructura de datos dinámica (lista ligada)
 * Contenido: Crear nodos, insertar, recorrer y liberar memoria
 */

typedef struct Nodo {
    int datos;
    struct Nodo *siguiente;
} Nodo;

// Función para crear un nuevo nodo
Nodo *crearNodo(int valor) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo != NULL) {
        nuevoNodo->datos = valor;
        nuevoNodo->siguiente = NULL;
    }
    return nuevoNodo;
}

// Función para insertar al inicio
Nodo *insertarInicio(Nodo *cabeza, int valor) {
    Nodo *nuevoNodo = crearNodo(valor);
    if (nuevoNodo != NULL) {
        nuevoNodo->siguiente = cabeza;
        return nuevoNodo;
    }
    return cabeza;
}

// Función para recorrer la lista
void recorrerLista(Nodo *cabeza) {
    printf("Lista: ");
    Nodo *temp = cabeza;
    while (temp != NULL) {
        printf("%d -> ", temp->datos);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

// Función para liberar toda la lista
void liberarLista(Nodo *cabeza) {
    Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    Nodo *lista = NULL;
    int opcion, valor;
    
    printf("=== Gestor de Listas Ligadas ===\n\n");
    
    while (1) {
        printf("\n1. Insertar valor\n2. Mostrar lista\n3. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                printf("Ingrese el valor: ");
                scanf("%d", &valor);
                lista = insertarInicio(lista, valor);
                printf("Valor %d insertado\n", valor);
                break;
            case 2:
                recorrerLista(lista);
                break;
            case 3:
                liberarLista(lista);
                printf("Lista liberada. ¡Hasta luego!\n");
                return 0;
            default:
                printf("Opción inválida\n");
        }
    }
    
    return 0;
}
