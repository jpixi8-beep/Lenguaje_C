#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Ejercicio 71: Archivos Binarios
 * Objetivo: Trabajar con archivos binarios para almacenar datos estructurados
 * Contenido: fopen en modo binario, fwrite, fread, fseek
 */

// Estructura que representa una cuenta bancaria
typedef struct {
    int id;           // Identificador único de la cuenta
    char nombre[50];  // Nombre del titular
    float saldo;      // Saldo actual de la cuenta
    int activo;       // Estado de la cuenta (1=activa, 0=inactiva)
} CuentaBancaria;

/*
 * Función que guarda una cuenta en un archivo binario
 * Los archivos binarios almacenan los bytes exactos de la estructura
 */
void guardarCuentaBinaria(const char *archivo, CuentaBancaria cuenta) {
    // Abrir archivo en modo append binario ("ab")
    FILE *fp = fopen(archivo, "ab");
    
    if (fp == NULL) {
        printf("Error: No se pudo abrir el archivo\n");
        return;
    }
    
    // fwrite escribe los bytes de la estructura directamente al archivo
    // Parámetros: dirección de datos, tamaño de cada elemento, cantidad de elementos, archivo
    fwrite(&cuenta, sizeof(CuentaBancaria), 1, fp);
    fclose(fp);
    printf("Cuenta guardada correctamente\n");
}

/*
 * Función que lee y muestra todas las cuentas del archivo binario
 * Los archivos binarios permiten acceso directo a estructuras completas
 */
void leerCuentasBinarias(const char *archivo) {
    // Abrir archivo en modo lectura binaria ("rb")
    FILE *fp = fopen(archivo, "rb");
    
    if (fp == NULL) {
        printf("No hay cuentas guardadas aún\n");
        return;
    }
    
    printf("\n=== Cuentas Bancarias ===\n");
    printf("%-5s %-30s %-15s %-10s\n", "ID", "Nombre", "Saldo", "Estado");
    printf("--------------------------------------------------------------------\n");
    
    CuentaBancaria cuenta;
    // fread lee los bytes del archivo y los copia directamente a la estructura
    // Retorna el número de elementos leídos correctamente
    while (fread(&cuenta, sizeof(CuentaBancaria), 1, fp) == 1) {
        printf("%-5d %-30s $%-14.2f %s\n", cuenta.id, cuenta.nombre, 
               cuenta.saldo, cuenta.activo ? "Activa" : "Inactiva");
    }
    
    fclose(fp);
}

/*
 * Función que actualiza el saldo de una cuenta específica
 * Usa fseek para posicionarse en el registro correcto dentro del archivo
 */
void actualizarSaldo(const char *archivo, int id, float nuevoSaldo) {
    // Abrir archivo en modo lectura/escritura binaria ("r+b")
    FILE *fp = fopen(archivo, "r+b");
    
    if (fp == NULL) {
        printf("Error: Archivo no encontrado\n");
        return;
    }
    
    CuentaBancaria cuenta;
    int encontrada = 0;
    
    // Leer cada cuenta secuencialmente
    while (fread(&cuenta, sizeof(CuentaBancaria), 1, fp) == 1) {
        if (cuenta.id == id) {
            cuenta.saldo = nuevoSaldo;
            
            // Retroceder el puntero de archivo al inicio del registro actual
            // SEEK_CUR significa "desde la posición actual"
            fseek(fp, -sizeof(CuentaBancaria), SEEK_CUR);
            
            // Sobrescribir el registro con los datos actualizados
            fwrite(&cuenta, sizeof(CuentaBancaria), 1, fp);
            encontrada = 1;
            printf("Saldo actualizado a $%.2f\n", nuevoSaldo);
            break;  // Salir del bucle una vez encontrada
        }
    }
    
    if (!encontrada) {
        printf("Cuenta no encontrada\n");
    }
    
    fclose(fp);
}

/*
 * Función que calcula estadísticas de todas las cuentas
 * Lee todos los registros y realiza cálculos
 */
void estadisticas(const char *archivo) {
    FILE *fp = fopen(archivo, "rb");
    
    if (fp == NULL) {
        printf("No hay cuentas\n");
        return;
    }
    
    CuentaBancaria cuenta;
    int totalCuentas = 0;
    float saldoTotal = 0, saldoPromedio = 0;
    int cuentasActivas = 0;
    
    // Leer todas las cuentas y acumular estadísticas
    while (fread(&cuenta, sizeof(CuentaBancaria), 1, fp) == 1) {
        totalCuentas++;
        saldoTotal += cuenta.saldo;
        if (cuenta.activo) cuentasActivas++;
    }
    
    // Calcular promedio si hay cuentas
    if (totalCuentas > 0) {
        saldoPromedio = saldoTotal / totalCuentas;
    }
    
    printf("\n=== Estadísticas ===\n");
    printf("Total de cuentas: %d\n", totalCuentas);
    printf("Cuentas activas: %d\n", cuentasActivas);
    printf("Saldo total: $%.2f\n", saldoTotal);
    printf("Saldo promedio: $%.2f\n", saldoPromedio);
    
    fclose(fp);
}

int main() {
    // Archivo binario donde se almacenarán las cuentas
    const char *archivo = "cuentas.bin";
    int opcion;
    
    printf("=== Banco - Gestión de Cuentas (Archivos Binarios) ===\n\n");
    
    while (1) {
        printf("\n1. Crear cuenta\n2. Ver cuentas\n3. Actualizar saldo\n");
        printf("4. Estadísticas\n5. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer
        
        switch (opcion) {
            case 1: {  // Crear nueva cuenta bancaria
                CuentaBancaria nueva;
                printf("ID de cuenta: ");
                scanf("%d", &nueva.id);
                getchar(); // Limpiar buffer
                
                printf("Nombre del titular: ");
                fgets(nueva.nombre, sizeof(nueva.nombre), stdin);
                nueva.nombre[strcspn(nueva.nombre, "\n")] = '\0'; // Remover \n
                
                printf("Saldo inicial: ");
                scanf("%f", &nueva.saldo);
                nueva.activo = 1;  // Nueva cuenta siempre activa
                
                guardarCuentaBinaria(archivo, nueva);
                break;
            }
                
            case 2:
                leerCuentasBinarias(archivo);
                break;
                
            case 3: {  // Actualizar saldo de cuenta existente
                int id;
                float nuevoSaldo;
                printf("ID de cuenta: ");
                scanf("%d", &id);
                printf("Nuevo saldo: ");
                scanf("%f", &nuevoSaldo);
                actualizarSaldo(archivo, id, nuevoSaldo);
                break;
            }
                
            case 4:
                estadisticas(archivo);
                break;
                
            case 5:  // Salir del programa
                printf("¡Hasta luego!\n");
                return 0;
                
            default:
                printf("Opción inválida\n");
        }
    }
    
    return 0;
}
