#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Ejercicio 74: Sistema de Logging en Archivo
 * Objetivo: Crear un sistema de registros (logs) con timestamp
 * Contenido: Escritura de archivos, manejo de fechas/horas, búsqueda y filtrado
 */

// Estructura que representa una entrada de log
typedef struct {
    char timestamp[30];  // Fecha y hora del evento (formato YYYY-MM-DD HH:MM:SS)
    char nivel[10];      // Nivel del log: INFO, WARNING, ERROR
    char mensaje[256];   // Mensaje descriptivo del evento
    int linea;           // Número de línea donde ocurrió el evento
} LogEntry;

/*
 * Función que obtiene la fecha y hora actual del sistema
 * Usa las funciones time.h para manejo de timestamps
 */
void obtenerTimestamp(char *buffer, size_t size) {
    time_t t = time(NULL);              // Obtener tiempo actual en segundos
    struct tm tm = *localtime(&t);      // Convertir a estructura tm (local)
    // Formatear como string legible
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", &tm);
}

/*
 * Función que registra un evento en el archivo de logs
 * Cada entrada incluye timestamp automático y metadatos
 */
void registrarLog(const char *archivo, const char *nivel, 
                  const char *mensaje, int linea) {
    FILE *fp = fopen(archivo, "a");  // Abrir en modo append
    
    if (fp == NULL) {
        printf("Error: No se pudo abrir el archivo de log\n");
        return;
    }
    
    LogEntry log;
    // Generar timestamp automáticamente
    obtenerTimestamp(log.timestamp, sizeof(log.timestamp));
    strcpy(log.nivel, nivel);
    strcpy(log.mensaje, mensaje);
    log.linea = linea;
    
    // Escribir entrada formateada al archivo
    fprintf(fp, "[%s] %s - Línea %d: %s\n", 
            log.timestamp, log.nivel, log.linea, log.mensaje);
    
    fclose(fp);
}

/*
 * Función que muestra todos los logs del archivo
 * Lee línea por línea y las imprime tal cual
 */
void mostrarLogs(const char *archivo) {
    FILE *fp = fopen(archivo, "r");
    
    if (fp == NULL) {
        printf("No hay registros de logs\n");
        return;
    }
    
    printf("\n=== Registro de Logs ===\n");
    printf("------------------------------------------------------------------------\n");
    
    char linea[500];
    // Leer e imprimir cada línea del archivo
    while (fgets(linea, sizeof(linea), fp) != NULL) {
        printf("%s", linea);
    }
    
    fclose(fp);
}

/*
 * Función que filtra y muestra solo logs de un nivel específico
 * Usa strstr para buscar el patrón "] NIVEL " en cada línea
 */
void filtrarPorNivel(const char *archivo, const char *nivel) {
    FILE *fp = fopen(archivo, "r");
    
    if (fp == NULL) {
        printf("No hay registros\n");
        return;
    }
    
    printf("\n=== Logs de Nivel: %s ===\n", nivel);
    printf("------------------------------------------------------------------------\n");
    
    char linea[500];
    int encontrados = 0;
    
    while (fgets(linea, sizeof(linea), fp) != NULL) {
        char busqueda[50];
        // Crear patrón de búsqueda: "] NIVEL "
        sprintf(busqueda, "] %s ", nivel);
        
        // Buscar el patrón en la línea
        if (strstr(linea, busqueda) != NULL) {
            printf("%s", linea);
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("No hay logs de este nivel\n");
    }
    
    fclose(fp);
}

/*
 * Función que calcula estadísticas de los logs por nivel
 * Cuenta ocurrencias de cada tipo de log
 */
void estadisticasLogs(const char *archivo) {
    FILE *fp = fopen(archivo, "r");
    
    if (fp == NULL) {
        printf("No hay logs\n");
        return;
    }
    
    int totalLogs = 0;
    int infoCount = 0, warningCount = 0, errorCount = 0;
    
    char linea[500];
    while (fgets(linea, sizeof(linea), fp) != NULL) {
        totalLogs++;
        
        // Contar por tipo de log usando strstr
        if (strstr(linea, "] INFO ") != NULL) {
            infoCount++;
        } else if (strstr(linea, "] WARNING ") != NULL) {
            warningCount++;
        } else if (strstr(linea, "] ERROR ") != NULL) {
            errorCount++;
        }
    }
    
    printf("\n=== Estadísticas de Logs ===\n");
    printf("Total de registros: %d\n", totalLogs);
    printf("Informativos: %d\n", infoCount);
    printf("Advertencias: %d\n", warningCount);
    printf("Errores: %d\n", errorCount);
    
    fclose(fp);
}

/*
 * Función que simula el ciclo de vida de una aplicación
 * Registra diferentes tipos de eventos para demostrar el sistema de logging
 * Parámetros:
 *   - archivo: ruta del archivo de log donde se registrarán los eventos
 */
void simularAplicacion(const char *archivo) {
    printf("\n=== Simulación de Aplicación ===\n");

    // Inicio de la aplicación
    registrarLog(archivo, "INFO", "Aplicación iniciada", 1);
    printf("✓ Aplicación iniciada\n");

    // Simulación de conexión a base de datos
    registrarLog(archivo, "INFO", "Conectando a base de datos", 5);
    printf("✓ Conexión establecida\n");

    // Carga de configuración del sistema
    registrarLog(archivo, "INFO", "Cargando configuración", 10);
    printf("✓ Configuración cargada\n");

    // Advertencia por rendimiento lento
    registrarLog(archivo, "WARNING", "Conexión lenta detectada", 15);
    printf("⚠ Advertencia: Conexión lenta\n");

    // Operación exitosa de sincronización
    registrarLog(archivo, "INFO", "Datos sincronizados", 20);
    printf("✓ Sincronización completada\n");

    // Error en operación de archivo
    registrarLog(archivo, "ERROR", "Error al guardar archivo", 25);
    printf("✗ Error encontrado\n");

    // Finalización normal de la aplicación
    registrarLog(archivo, "INFO", "Aplicación finalizada", 30);
    printf("✓ Aplicación finalizada\n");
}

/*
 * Función principal del programa
 * Implementa un menú interactivo para gestionar el sistema de logging
 * Permite al usuario ver logs, filtrar por nivel, obtener estadísticas,
 * simular una aplicación y registrar logs manualmente
 */
int main() {
    const char *archivo = "aplicacion.log";  // Archivo donde se guardarán los logs
    int opcion;
    
    printf("=== Sistema de Logging ===\n\n");
    
    while (1) {
        printf("\n1. Ver todos los logs\n2. Ver por nivel\n3. Estadísticas\n");
        printf("4. Simular aplicación\n5. Registrar log manual\n6. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer
        
        switch (opcion) {
            case 1:
                mostrarLogs(archivo);
                break;
                
            case 2: {  // Filtrar logs por nivel específico
                printf("Nivel (INFO/WARNING/ERROR): ");
                char nivel[20];
                fgets(nivel, sizeof(nivel), stdin);
                nivel[strcspn(nivel, "\n")] = '\0'; // Remover \n
                filtrarPorNivel(archivo, nivel);
                break;
            }
                
            case 3:
                estadisticasLogs(archivo);
                break;
                
            case 4:
                simularAplicacion(archivo);
                break;
                
            case 5: {  // Registrar log manualmente
                char nivel[20], mensaje[256];
                int linea;
                
                printf("Nivel (INFO/WARNING/ERROR): ");
                fgets(nivel, sizeof(nivel), stdin);
                nivel[strcspn(nivel, "\n")] = '\0';
                
                printf("Mensaje: ");
                fgets(mensaje, sizeof(mensaje), stdin);
                mensaje[strcspn(mensaje, "\n")] = '\0';
                
                printf("Número de línea: ");
                scanf("%d", &linea);
                
                registrarLog(archivo, nivel, mensaje, linea);
                printf("Log registrado\n");
                break;
            }
                
            case 6:  // Salir del programa
                printf("¡Hasta luego!\n");
                return 0;
                
            default:
                printf("Opción inválida\n");
        }
    }
    
    return 0;
}
