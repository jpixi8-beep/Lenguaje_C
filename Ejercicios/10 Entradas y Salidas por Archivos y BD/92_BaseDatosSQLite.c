#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

/*
 * Ejercicio 73: Base de Datos SQLite
 * Objetivo: Integrar C con SQLite para operaciones CRUD
 * Contenido: sqlite3, preparación de consultas, ejecución, manejo de resultados
 *
 * NOTA: Requiere compilación con sqlite3
 * Compilar: gcc -o programa 73_BaseDatosSQLite.c -lsqlite3
 * Para ello puedes instalar el "Source Code" (amalgamation) de la página oficial de SQLite.
 * Descomprime el ZIP y busca estos dos archivos:
* sqlite3.h
* sqlite3.c
* Cópialos y pégalos en la misma carpeta donde tienes tu archivo  92_BaseDatosSQLite.c.

 */

// Estructura que representa un producto
typedef struct
{
    int id;             // Identificador único (autoincremental en BD)
    char nombre[100];   // Nombre del producto
    char categoria[50]; // Categoría del producto
    float precio;       // Precio del producto
    int stock;          // Cantidad en inventario
} Producto;

// Variable global para la conexión a la base de datos SQLite
sqlite3 *db;

/*
 * Función que crea la tabla de productos si no existe
 * Usa SQL DDL (Data Definition Language) para crear la estructura
 */
int crearTabla()
{
    char *errMsg = 0; // Puntero para mensajes de error

    // SQL para crear tabla con restricciones
    const char *sql = "CREATE TABLE IF NOT EXISTS productos("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT," // ID único automático
                      "nombre TEXT NOT NULL,"                 // Nombre obligatorio
                      "categoria TEXT NOT NULL,"              // Categoría obligatoria
                      "precio REAL NOT NULL,"                 // Precio obligatorio
                      "stock INTEGER NOT NULL);";             // Stock obligatorio

    // Ejecutar consulta SQL
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        printf("Error SQL: %s\n", errMsg);
        sqlite3_free(errMsg); // Liberar memoria del mensaje de error
        return 0;             // Error
    }

    return 1; // Éxito
}

/*
 * Función que inserta un nuevo producto en la base de datos
 * Usa SQL INSERT con parámetros formateados en la cadena
 */
int insertarProducto(Producto p)
{
    char sql[500];    // Buffer para la consulta SQL
    char *errMsg = 0; // Puntero para mensajes de error

    // Construir consulta SQL INSERT con formato
    sprintf(sql, "INSERT INTO productos (nombre, categoria, precio, stock) "
                 "VALUES ('%s', '%s', %.2f, %d);",
            p.nombre, p.categoria, p.precio, p.stock);

    // Ejecutar consulta de inserción
    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        printf("Error al insertar: %s\n", errMsg);
        sqlite3_free(errMsg);
        return 0; // Error
    }

    printf("Producto insertado correctamente\n");
    return 1; // Éxito
}

/*
 * Función que muestra todos los productos usando prepared statements
 * Los prepared statements son más seguros y eficientes para consultas repetidas
 */
void mostrarProductos()
{
    sqlite3_stmt *stmt; // Statement preparado
    const char *sql = "SELECT * FROM productos;";

    // Preparar la consulta SQL
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc != SQLITE_OK)
    {
        printf("Error en preparación de consulta\n");
        return;
    }

    printf("\n=== Catálogo de Productos ===\n");
    printf("%-5s %-30s %-20s %-10s %-10s\n", "ID", "Nombre", "Categoría", "Precio", "Stock");
    printf("------------------------------------------------------------------------------------\n");

    // Ejecutar consulta y procesar resultados fila por fila
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        // Extraer valores de cada columna
        int id = sqlite3_column_int(stmt, 0);                          // Columna 0: id
        const unsigned char *nombre = sqlite3_column_text(stmt, 1);    // Columna 1: nombre
        const unsigned char *categoria = sqlite3_column_text(stmt, 2); // Columna 2: categoria
        float precio = sqlite3_column_double(stmt, 3);                 // Columna 3: precio
        int stock = sqlite3_column_int(stmt, 4);                       // Columna 4: stock

        printf("%-5d %-30s %-20s $%-9.2f %-10d\n", id, (char *)nombre,
               (char *)categoria, precio, stock);
    }

    sqlite3_finalize(stmt); // Liberar el statement preparado
}

/*
 * Función que busca productos por categoría específica
 * Usa consulta SQL con cláusula WHERE
 */
void buscarPorCategoria(const char *categoria)
{
    sqlite3_stmt *stmt;
    char sql[256];

    // Construir consulta con filtro por categoría
    sprintf(sql, "SELECT * FROM productos WHERE categoria = '%s';", categoria);

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc != SQLITE_OK)
    {
        printf("Error en consulta\n");
        return;
    }

    printf("\n=== Productos de %s ===\n", categoria);
    int encontrados = 0;

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *nombre = sqlite3_column_text(stmt, 1);
        float precio = sqlite3_column_double(stmt, 3);
        int stock = sqlite3_column_int(stmt, 4);

        printf("%d. %s - $%.2f (Stock: %d)\n", id, (char *)nombre, precio, stock);
        encontrados++;
    }

    if (encontrados == 0)
    {
        printf("No hay productos en esta categoría\n");
    }

    sqlite3_finalize(stmt);
}

/*
 * Función que actualiza el stock de un producto específico
 * Usa SQL UPDATE con cláusula WHERE
 */
void actualizarStock(int id, int nuevoStock)
{
    char sql[256];
    char *errMsg = 0;

    // Construir consulta UPDATE
    sprintf(sql, "UPDATE productos SET stock = %d WHERE id = %d;", nuevoStock, id);

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        printf("Error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("Stock actualizado\n");
    }
}

/*
 * Función que obtiene estadísticas usando funciones agregadas de SQL
 * COUNT, SUM, AVG son funciones de agregación
 */
void obtenerEstadisticas()
{
    sqlite3_stmt *stmt;
    // Consulta con funciones agregadas
    const char *sql = "SELECT COUNT(*), SUM(stock), AVG(precio) FROM productos;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc != SQLITE_OK)
    {
        printf("Error en consulta\n");
        return;
    }

    // Solo esperamos una fila de resultado (agregados)
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int totalProductos = sqlite3_column_int(stmt, 0);      // COUNT(*)
        int totalStock = sqlite3_column_int(stmt, 1);          // SUM(stock)
        float precioPromedio = sqlite3_column_double(stmt, 2); // AVG(precio)

        printf("\n=== Estadísticas ===\n");
        printf("Total de productos: %d\n", totalProductos);
        printf("Stock total: %d\n", totalStock);
        printf("Precio promedio: $%.2f\n", precioPromedio);
    }

    sqlite3_finalize(stmt);
}

int main()
{
    // Abrir conexión a base de datos SQLite (crea archivo si no existe)
    int rc = sqlite3_open("tienda.db", &db);

    if (rc)
    {
        printf("Error al abrir base de datos\n");
        return 1;
    }

    // Crear tabla si no existe
    if (!crearTabla())
    {
        printf("Error al crear tabla\n");
        sqlite3_close(db); // Cerrar conexión antes de salir
        return 1;
    }

    int opcion;
    printf("=== Tienda - Base de Datos SQLite ===\n\n");

    while (1)
    {
        printf("\n1. Agregar producto\n2. Ver productos\n3. Buscar por categoría\n");
        printf("4. Actualizar stock\n5. Estadísticas\n6. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion)
        {
        case 1:
        { // Agregar nuevo producto
            Producto nuevo;
            printf("Nombre: ");
            fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
            nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0'; // Remover \n

            printf("Categoría: ");
            fgets(nuevo.categoria, sizeof(nuevo.categoria), stdin);
            nuevo.categoria[strcspn(nuevo.categoria, "\n")] = '\0'; // Remover \n

            printf("Precio: ");
            scanf("%f", &nuevo.precio);
            printf("Stock: ");
            scanf("%d", &nuevo.stock);

            insertarProducto(nuevo);
            break;
        }

        case 2:
            mostrarProductos();
            break;

        case 3:
        { // Buscar productos por categoría
            char categoria[50];
            printf("Categoría: ");
            scanf("\n%49[^\n]", categoria); // Leer string con espacios
            buscarPorCategoria(categoria);
            break;
        }

        case 4:
        {
            int id, stock;
            printf("ID del producto: ");
            scanf("%d", &id);
            printf("Nuevo stock: ");
            scanf("%d", &stock);
            actualizarStock(id, stock);
            break;
        }

        case 5:
            obtenerEstadisticas();
            break;

        case 6:                // Cerrar conexión y salir
            sqlite3_close(db); // Cerrar conexión a base de datos
            printf("¡Hasta luego!\n");
            return 0;

        default:
            printf("Opción inválida\n");
        }
    }

    return 0;
}
