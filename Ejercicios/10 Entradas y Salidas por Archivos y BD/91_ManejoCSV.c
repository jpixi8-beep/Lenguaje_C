#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Ejercicio 72: Manejo de Archivos CSV
 * Objetivo: Leer y escribir archivos en formato CSV (Comma-Separated Values)
 * Contenido: Parseo de líneas CSV, almacenamiento y análisis de datos
 */

// Estructura que representa una venta
typedef struct {
    int id;           // Identificador único de la venta
    char producto[50]; // Nombre del producto vendido
    float precio;     // Precio unitario del producto
    int cantidad;     // Cantidad vendida
    float total;      // Total de la venta (precio * cantidad)
} Venta;

/*
 * Función que guarda una venta en un archivo CSV
 * CSV (Comma-Separated Values) es un formato estándar para datos tabulares
 */
void guardarVentaCSV(const char *archivo, Venta venta) {
    FILE *fp = fopen(archivo, "a"); // Modo append
    
    if (fp == NULL) {
        printf("Error: No se pudo abrir el archivo\n");
        return;
    }
    
    // Escribir datos separados por comas (formato CSV)
    fprintf(fp, "%d,%s,%.2f,%d,%.2f\n", venta.id, venta.producto, 
            venta.precio, venta.cantidad, venta.total);
    
    fclose(fp);
    printf("Venta guardada en CSV\n");
}

/*
 * Función que crea el archivo CSV con encabezado si no existe
 * Los archivos CSV suelen tener una primera línea con nombres de columnas
 */
void crearEncabezado(const char *archivo) {
    // Intentar abrir en modo lectura para verificar si existe
    FILE *fp = fopen(archivo, "r");
    
    if (fp == NULL) {
        // El archivo no existe, crearlo con encabezado
        fp = fopen(archivo, "w");  // Modo escritura (crea archivo si no existe)
        fprintf(fp, "ID,Producto,Precio,Cantidad,Total\n");
        fclose(fp);
        printf("Archivo CSV creado\n");
    } else {
        // El archivo ya existe, solo cerrarlo
        fclose(fp);
    }
}

/*
 * Función que lee y muestra todas las ventas del archivo CSV
 * Parsea cada línea separada por comas usando sscanf
 */
void leerVentasCSV(const char *archivo) {
    FILE *fp = fopen(archivo, "r");
    
    if (fp == NULL) {
        printf("No hay ventas guardadas\n");
        return;
    }
    
    printf("\n=== Registro de Ventas (CSV) ===\n");
    printf("%-5s %-30s %-10s %-10s %-12s\n", "ID", "Producto", "Precio", "Cantidad", "Total");
    printf("----------------------------------------------------------------------\n");
    
    char linea[256];
    // Saltar la primera línea (encabezado)
    fgets(linea, sizeof(linea), fp);
    
    // Leer cada línea de datos
    while (fgets(linea, sizeof(linea), fp) != NULL) {
        int id, cantidad;
        char producto[50];
        float precio, total;
        
        // Parsear la línea CSV usando sscanf
        // %49[^,] significa "leer hasta 49 caracteres que no sean coma"
        sscanf(linea, "%d,%49[^,],%f,%d,%f", &id, producto, &precio, &cantidad, &total);
        printf("%-5d %-30s $%-9.2f %-10d $%-11.2f\n", id, producto, precio, cantidad, total);
    }
    
    fclose(fp);
}

/*
 * Función que genera un reporte estadístico de todas las ventas
 * Calcula totales y promedios a partir de los datos CSV
 */
void reporteVentas(const char *archivo) {
    FILE *fp = fopen(archivo, "r");
    
    if (fp == NULL) {
        printf("No hay ventas\n");
        return;
    }
    
    char linea[256];
    fgets(linea, sizeof(linea), fp); // Saltar encabezado
    
    float totalVentas = 0;    // Suma de todos los totales
    int totalProductos = 0;   // Suma de todas las cantidades
    
    // Procesar cada línea de datos
    while (fgets(linea, sizeof(linea), fp) != NULL) {
        int id, cantidad;
        char producto[50];
        float precio, total;
        
        // Parsear línea CSV
        sscanf(linea, "%d,%49[^,],%f,%d,%f", &id, producto, &precio, &cantidad, &total);
        totalVentas += total;        // Acumular total de la venta
        totalProductos += cantidad;  // Acumular cantidad vendida
    }
    
    printf("\n=== Reporte de Ventas ===\n");
    printf("Total en ventas: $%.2f\n", totalVentas);
    printf("Total de productos vendidos: %d\n", totalProductos);
    // Calcular promedio por venta (evitar división por cero)
    printf("Promedio por venta: $%.2f\n", totalProductos > 0 ? totalVentas / totalProductos : 0);
    
    fclose(fp);
}

int main() {
    const char *archivo = "ventas.csv";  // Archivo CSV para almacenar ventas
    int opcion;
    
    // Crear archivo con encabezado si no existe
    crearEncabezado(archivo);
    
    printf("=== Gestor de Ventas (CSV) ===\n\n");
    
    while (1) {
        printf("\n1. Registrar venta\n2. Ver ventas\n3. Reporte\n4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer
        
        switch (opcion) {
            case 1: {  // Registrar nueva venta
                Venta nueva;
                printf("ID de venta: ");
                scanf("%d", &nueva.id);
                getchar(); // Limpiar buffer
                
                printf("Producto: ");
                fgets(nueva.producto, sizeof(nueva.producto), stdin);
                nueva.producto[strcspn(nueva.producto, "\n")] = '\0'; // Remover \n
                
                printf("Precio: ");
                scanf("%f", &nueva.precio);
                printf("Cantidad: ");
                scanf("%d", &nueva.cantidad);
                
                // Calcular total automáticamente
                nueva.total = nueva.precio * nueva.cantidad;
                guardarVentaCSV(archivo, nueva);
                break;
            }
                
            case 2:
                leerVentasCSV(archivo);
                break;
                
            case 3:
                reporteVentas(archivo);
                break;
                
            case 4:  // Salir del programa
                printf("¡Hasta luego!\n");
                return 0;
                
            default:
                printf("Opción inválida\n");
        }
    }
    
    return 0;
}
