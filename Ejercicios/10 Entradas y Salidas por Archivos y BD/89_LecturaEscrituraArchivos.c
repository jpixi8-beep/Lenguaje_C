#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Ejercicio 70: Lectura y Escritura Básica en Archivos
 * Objetivo: Trabajar con archivos de texto de forma básica
 * Contenido: fopen, fclose, fprintf, fscanf, escritura y lectura de datos
 */

// Estructura que representa un contacto
typedef struct {
    int id;           // Identificador único del contacto
    char nombre[50];  // Nombre completo del contacto
    char email[50];   // Dirección de correo electrónico
    int edad;         // Edad del contacto
} Contacto;

/*
 * Función que guarda un contacto en un archivo de texto
 * Modo: append (agrega al final del archivo si existe)
 */
void guardarContacto(const char *archivo, Contacto contacto) {
    // Abrir archivo en modo append ("a" = agregar al final)
    FILE *fp = fopen(archivo, "a");
    
    if (fp == NULL) {
        printf("Error: No se pudo abrir el archivo\n");
        return;
    }
    
    // Escribir los datos separados por "|" (formato personalizado)
    fprintf(fp, "%d|%s|%s|%d\n", contacto.id, contacto.nombre, 
            contacto.email, contacto.edad);
    
    fclose(fp);  // Cerrar archivo
    printf("Contacto guardado correctamente\n");
}

/*
 * Función que lee y muestra todos los contactos del archivo
 * Lee línea por línea hasta el final del archivo
 */
void mostrarContactos(const char *archivo) {
    // Abrir archivo en modo lectura ("r" = read)
    FILE *fp = fopen(archivo, "r");
    
    if (fp == NULL) {
        printf("No hay contactos guardados aún\n");
        return;
    }
    
    printf("\n=== Contactos ===\n");
    // Encabezados con formato alineado
    printf("%-5s %-20s %-30s %-5s\n", "ID", "Nombre", "Email", "Edad");
    printf("---------------------------------------------------------------------------\n");
    
    Contacto contacto;
    // Leer cada línea hasta el final del archivo
    // fscanf retorna el número de elementos leídos correctamente
    while (fscanf(fp, "%d|%49[^|]|%49[^|]|%d\n", &contacto.id, contacto.nombre, 
                  contacto.email, &contacto.edad) == 4) {
        printf("%-5d %-20s %-30s %-5d\n", contacto.id, contacto.nombre, 
               contacto.email, contacto.edad);
    }
    
    fclose(fp);  // Cerrar archivo
}

/*
 * Función que busca contactos por nombre (búsqueda parcial)
 * Usa strstr para encontrar coincidencias dentro del nombre
 */
void buscarContacto(const char *archivo, const char *nombre) {
    FILE *fp = fopen(archivo, "r");
    
    if (fp == NULL) {
        printf("No hay contactos guardados\n");
        return;
    }
    
    printf("\n=== Resultados de búsqueda: %s ===\n", nombre);
    
    Contacto contacto;
    int encontrados = 0;
    
    // Leer cada contacto y buscar coincidencias
    while (fscanf(fp, "%d|%49[^|]|%49[^|]|%d\n", &contacto.id, contacto.nombre, 
                  contacto.email, &contacto.edad) == 4) {
        // strstr busca la subcadena 'nombre' dentro de contacto.nombre
        if (strstr(contacto.nombre, nombre) != NULL) {
            printf("ID: %d\nNombre: %s\nEmail: %s\nEdad: %d\n\n", 
                   contacto.id, contacto.nombre, contacto.email, contacto.edad);
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("No se encontraron contactos\n");
    }
    
    fclose(fp);
}

int main() {
    // Nombre del archivo donde se guardarán los contactos
    const char *archivo = "contactos.txt";
    int opcion;
    
    printf("=== Gestor de Contactos ===\n\n");
    
    // Bucle principal del menú
    while (1) {
        printf("\n1. Agregar contacto\n2. Mostrar contactos\n3. Buscar contacto\n4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer del teclado
        
        switch (opcion) {
            case 1: {  // Agregar nuevo contacto
                Contacto nuevo;
                printf("ID: ");
                scanf("%d", &nuevo.id);
                getchar(); // Limpiar buffer después de scanf
                
                printf("Nombre: ");
                fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
                nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0'; // Remover \n
                
                printf("Email: ");
                fgets(nuevo.email, sizeof(nuevo.email), stdin);
                nuevo.email[strcspn(nuevo.email, "\n")] = '\0'; // Remover \n
                
                printf("Edad: ");
                scanf("%d", &nuevo.edad);
                
                guardarContacto(archivo, nuevo);
                break;
            }
                
            case 2:
                mostrarContactos(archivo);
                break;
                
            case 3: {  // Buscar contacto por nombre
                char nombre[50];
                printf("Nombre a buscar: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0'; // Remover \n
                buscarContacto(archivo, nombre);
                break;
            }
                
            case 4:  // Salir del programa
                printf("¡Hasta luego!\n");
                return 0;
                
            default:
                printf("Opción inválida\n");
        }
    }
    
    return 0;
}
