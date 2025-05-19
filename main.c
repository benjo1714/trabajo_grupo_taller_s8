#include <stdio.h>
#include "funciones.h"

// Recursos
int tornillos, polimeros, cables, plastico, metal;
int totalProductos = 0;

// Definición de la estructura Producto
struct Producto {
    char nombre[50];
    int codigo;
    int tiempo;
    int tornillos;
    int polimeros;
    int cables;
    int plastico;
    int metal;
};

// Arreglo para almacenar productos
struct Producto productos[5];

// Declaración de funciones
void ingresarProductos();
void aumentarRecursos();
void fabricarProducto();
void buscarProductoPorID();
void eliminarProductoPorID();

int main() {
    int opcion;

    // Entrada inicial de recursos
    PORO:
    printf("Ingrese los recursos iniciales del inventario (solo numeros positivos):\n");
    printf("Tornillos: "); scanf("%d", &tornillos);
    printf("Polímeros: "); scanf("%d", &polimeros);
    printf("Cables: "); scanf("%d", &cables);
    printf("Plástico: "); scanf("%d", &plastico);
    printf("Metal: "); scanf("%d", &metal);

    if (tornillos < 0 || polimeros < 0 || cables < 0 || plastico < 0 || metal < 0) {
        printf("Ingrese solo números positivos.\n");
        goto PORO;
    }

    // Menú principal
    do {
        printf("\n¿Qué desea hacer?\n");
        printf("1. Ingreso de productos\n");
        printf("2. Eliminar producto\n");
        printf("3. Fabricar productos\n");
        printf("4. Aumentar recursos\n");
        printf("5. Buscar producto por código\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: ingresarProductos(); break;
            case 2: eliminarProductoPorID(); break;
            case 3: fabricarProducto(); break;
            case 4: aumentarRecursos(); break;
            case 5: buscarProductoPorID(); break;
            case 6: printf("Gracias por preferirnos.\n"); break;
            default: printf("Opción no válida.\n"); break;
        }

    } while (opcion != 6);

    return 0;
}