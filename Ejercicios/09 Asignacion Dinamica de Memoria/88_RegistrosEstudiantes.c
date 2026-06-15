#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Ejercicio 69: Gestión de Registros de Estudiantes
 * Objetivo: Combinar estructuras, arrays dinámicos y manejo de memoria
 * Contenido: malloc para arrays, structs, funciones de gestión, liberación de memoria
 */

// Estructura que representa a un estudiante
typedef struct {
    int id;              // Identificador único del estudiante
    char nombre[50];     // Nombre completo del estudiante
    char carrera[50];    // Carrera que estudia
    float promedio;      // Promedio académico
} Estudiante;

// Estructura que maneja la base de datos completa
typedef struct {
    Estudiante *datos;   // Puntero al array dinámico de estudiantes
    int cantidad;        // Número actual de estudiantes registrados
    int capacidad;       // Capacidad máxima actual del array (se expande dinámicamente)
} BaseDatos;

/*
 * Función que crea una nueva base de datos con capacidad inicial
 * Retorna: Puntero a la BaseDatos creada, o NULL si hay error
 */
BaseDatos *crearBaseDatos(int capacidadInicial) {
    // 1. Reservar memoria para la estructura BaseDatos
    BaseDatos *bd = (BaseDatos *)malloc(sizeof(BaseDatos));
    
    if (bd != NULL) {
        // 2. Reservar memoria para el array de estudiantes
        bd->datos = (Estudiante *)malloc(capacidadInicial * sizeof(Estudiante));
        
        if (bd->datos == NULL) {
            // Si falla la reserva del array, liberar la estructura BaseDatos
            free(bd);
            return NULL;
        }
        
        // 3. Inicializar contadores
        bd->cantidad = 0;           // Aún no hay estudiantes
        bd->capacidad = capacidadInicial;  // Capacidad inicial
    }
    
    return bd;  // Retornar la base de datos creada
}

/*
 * Función que agrega un nuevo estudiante a la base de datos
 * Si la capacidad se agota, expande automáticamente el array
 */
void agregarEstudiante(BaseDatos *bd, int id, const char *nombre, 
                       const char *carrera, float promedio) {
    // Verificar si necesitamos expandir la capacidad
    if (bd->cantidad >= bd->capacidad) {
        // Duplicar la capacidad actual
        bd->capacidad *= 2;
        
        // Intentar reasignar memoria con la nueva capacidad
        Estudiante *temp = (Estudiante *)realloc(bd->datos, 
                                                  bd->capacidad * sizeof(Estudiante));
        
        if (temp != NULL) {
            bd->datos = temp;  // Actualizar el puntero si realloc fue exitoso
        } else {
            printf("Error al expandir memoria\n");
            return;  // Salir sin agregar el estudiante
        }
    }
    
    // Agregar el estudiante en la posición actual (bd->cantidad)
    bd->datos[bd->cantidad].id = id;
    strcpy(bd->datos[bd->cantidad].nombre, nombre);
    strcpy(bd->datos[bd->cantidad].carrera, carrera);
    bd->datos[bd->cantidad].promedio = promedio;
    
    bd->cantidad++;  // Incrementar el contador de estudiantes
}

/*
 * Función que muestra todos los estudiantes registrados
 * Formato tabular con encabezados
 */
void mostrarEstudiantes(BaseDatos *bd) {
    if (bd->cantidad == 0) {
        printf("No hay estudiantes registrados\n");
        return;
    }
    
    printf("\n=== Lista de Estudiantes ===\n");
    // Encabezados con formato alineado
    printf("%-5s %-20s %-25s %-10s\n", "ID", "Nombre", "Carrera", "Promedio");
    printf("------------------------------------------------------------------\n");
    
    // Recorrer y mostrar cada estudiante
    for (int i = 0; i < bd->cantidad; i++) {
        printf("%-5d %-20s %-25s %.2f\n", 
               bd->datos[i].id,
               bd->datos[i].nombre,
               bd->datos[i].carrera,
               bd->datos[i].promedio);
    }
}

/*
 * Función que busca estudiantes por carrera específica
 */
void buscarPorCarrera(BaseDatos *bd, const char *carrera) {
    printf("\n=== Estudiantes de %s ===\n", carrera);
    int encontrados = 0;
    
    // Recorrer todos los estudiantes
    for (int i = 0; i < bd->cantidad; i++) {
        // Comparar la carrera usando strcmp (retorna 0 si son iguales)
        if (strcmp(bd->datos[i].carrera, carrera) == 0) {
            printf("%d. %s (Promedio: %.2f)\n", 
                   bd->datos[i].id, 
                   bd->datos[i].nombre, 
                   bd->datos[i].promedio);
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("No hay estudiantes de esta carrera\n");
    }
}

/*
 * Función que libera toda la memoria utilizada por la base de datos
 * IMPORTANTE: Liberar en orden correcto (primero el array, luego la estructura)
 */
void liberarBaseDatos(BaseDatos *bd) {
    if (bd != NULL) {
        free(bd->datos);  // Liberar el array de estudiantes
        free(bd);         // Liberar la estructura BaseDatos
    }
}

int main() {
    // Crear base de datos con capacidad inicial de 5 estudiantes
    BaseDatos *bd = crearBaseDatos(5);
    
    if (bd == NULL) {
        printf("Error: No se pudo crear la base de datos\n");
        return 1;
    }
    
    // Agregar estudiantes de ejemplo
    agregarEstudiante(bd, 1, "Juan Pérez", "Ingeniería en Sistemas", 8.5);
    agregarEstudiante(bd, 2, "María García", "Ingeniería en Sistemas", 9.0);
    agregarEstudiante(bd, 3, "Carlos López", "Administración", 7.8);
    agregarEstudiante(bd, 4, "Ana Rodríguez", "Ingeniería en Sistemas", 8.9);
    agregarEstudiante(bd, 5, "Fernando Torres", "Administración", 8.2);
    
    int opcion;
    
    printf("=== Gestor de Base de Datos de Estudiantes ===\n\n");
    
    // Bucle principal del menú
    while (1) {
        printf("\n1. Mostrar todos\n2. Buscar por carrera\n3. Agregar estudiante\n4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer del teclado (carácter de nueva línea)
        
        switch (opcion) {
            case 1:
                mostrarEstudiantes(bd);
                break;
                
            case 2: {
                char carrera[50];
                printf("Ingrese la carrera: ");
                // Usar fgets para leer strings con espacios
                fgets(carrera, sizeof(carrera), stdin);
                // Remover el carácter de nueva línea del final
                carrera[strcspn(carrera, "\n")] = '\0';
                buscarPorCarrera(bd, carrera);
                break;
            }
                
            case 3: {
                int id;
                char nombre[50], carrera[50];
                float promedio;
                
                printf("ID: ");
                scanf("%d", &id);
                getchar(); // Limpiar buffer
                
                printf("Nombre: ");
                //fgets(donde_guardar, cuánto_espacio, de_dónde_sacarlo);
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                
                printf("Carrera: ");
                //fgets(donde_guardar, cuánto_espacio, de_dónde_sacarlo);
                fgets(carrera, sizeof(carrera), stdin);
                carrera[strcspn(carrera, "\n")] = '\0';
                
                printf("Promedio: ");
                scanf("%f", &promedio);
                
                agregarEstudiante(bd, id, nombre, carrera, promedio);
                printf("Estudiante agregado correctamente\n");
                break;
            }
                
            case 4:
                liberarBaseDatos(bd);  // Liberar memoria antes de salir
                printf("Memoria liberada. ¡Hasta luego!\n");
                return 0;
                
            default:
                printf("Opción inválida\n");
        }
    }
    
    return 0;
}
