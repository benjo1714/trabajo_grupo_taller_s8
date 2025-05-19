#include <stdio.h>
#include <string.h>

// Función para ingresar productos
void ingresarProductos() {
    int p;
    printf("\n¿Cuántos productos va a ingresar? (máximo 5 en total): ");
    scanf("%d", &p);

    if (totalProductos + p > 5) {
        printf("Solo se pueden tener hasta 5 productos en total.\n");
        return;
    }

    for (int i = totalProductos; i < totalProductos + p; i++) {
        getchar();  // Limpiar buffer
        printf("\nIngrese el nombre del producto %d: ", i + 1);
        fgets(productos[i].nombre, 50, stdin);
        strtok(productos[i].nombre, "\n");  // Eliminar salto de línea

        printf("Ingrese el código del producto: ");
        scanf("%d", &productos[i].codigo);
        printf("Ingrese el tiempo de elaboración (horas): ");
        scanf("%d", &productos[i].tiempo);
        printf("Tornillos necesarios: ");
        scanf("%d", &productos[i].tornillos);
        printf("Polímeros necesarios: ");
        scanf("%d", &productos[i].polimeros);
        printf("Cables necesarios: ");
        scanf("%d", &productos[i].cables);
        printf("Plástico necesario: ");
        scanf("%d", &productos[i].plastico);
        printf("Metal necesario: ");
        scanf("%d", &productos[i].metal);
    }

    totalProductos += p;
}

// Función para aumentar recursos
void aumentarRecursos() {
    int extra;
    printf("\nIngrese recursos adicionales:\n");

    printf("Tornillos: "); scanf("%d", &extra); tornillos += extra;
    printf("Polímeros: "); scanf("%d", &extra); polimeros += extra;
    printf("Cables: "); scanf("%d", &extra); cables += extra;
    printf("Plástico: "); scanf("%d", &extra); plastico += extra;
    printf("Metal: "); scanf("%d", &extra); metal += extra;

    printf("Recursos actualizados.\n");
}

// Función para fabricar productos
void fabricarProducto() {
    if (totalProductos == 0) {
        printf("No hay productos disponibles para fabricar.\n");
        return;
    }

    printf("\nProductos disponibles:\n");
    for (int i = 0; i < totalProductos; i++) {
        printf("Código: %d | Nombre: %s\n", productos[i].codigo, productos[i].nombre);
    }

    int codigo, cantidad;
    printf("\nIngrese el código del producto a fabricar: ");
    scanf("%d", &codigo);
    printf("Ingrese la cantidad a fabricar: ");
    scanf("%d", &cantidad);

    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].codigo == codigo) {
            int tornillosNecesarios = productos[i].tornillos * cantidad;
            int polimerosNecesarios = productos[i].polimeros * cantidad;
            int cablesNecesarios = productos[i].cables * cantidad;
            int plasticoNecesario = productos[i].plastico * cantidad;
            int metalNecesario = productos[i].metal * cantidad;
            int tiempoTotal = productos[i].tiempo * cantidad;

            if (tornillos < tornillosNecesarios || polimeros < polimerosNecesarios ||
                cables < cablesNecesarios || plastico < plasticoNecesario || metal < metalNecesario) {
                printf("No hay suficientes recursos para fabricar %d unidad(es) de %s.\n", cantidad, productos[i].nombre);
                return;
            }

            printf("\nResumen de fabricación:\n");
            printf("Producto: %s\n", productos[i].nombre);
            printf("Cantidad: %d\n", cantidad);
            printf("Tornillos: %d\n", tornillosNecesarios);
            printf("Polímeros: %d\n", polimerosNecesarios);
            printf("Cables: %d\n", cablesNecesarios);
            printf("Plástico: %d\n", plasticoNecesario);
            printf("Metal: %d\n", metalNecesario);
            printf("Tiempo estimado total: %d horas\n", tiempoTotal);

            char confirmacion;
            printf("¿Desea continuar con la fabricación? (s/n): ");
            scanf(" %c", &confirmacion);

            if (confirmacion == 's' || confirmacion == 'S') {
                tornillos -= tornillosNecesarios;
                polimeros -= polimerosNecesarios;
                cables -= cablesNecesarios;
                plastico -= plasticoNecesario;
                metal -= metalNecesario;
                printf("Fabricación completada con éxito.\n");
            } else {
                printf("Fabricación cancelada.\n");
            }
            return;
        }
    }

    printf("Producto con código %d no encontrado.\n", codigo);
}

// Función para buscar producto por código
void buscarProductoPorID() {
    int codigo;
    printf("Ingrese el código del producto que desea buscar: ");
    scanf("%d", &codigo);
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].codigo == codigo) {
            printf("\nProducto encontrado:\n");
            printf("Código: %d\n", productos[i].codigo);
            printf("Nombre: %s\n", productos[i].nombre);
            return;
        }
    }
    printf("No se encontró ningún producto con el código: %d\n", codigo);
}

// Función para eliminar producto por código
void eliminarProductoPorID() {
    int codigo;
    printf("Ingrese el código del producto que desea eliminar: ");
    scanf("%d", &codigo);
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].codigo == codigo) {
            for (int j = i; j < totalProductos - 1; j++) {
                productos[j] = productos[j + 1];
            }
            totalProductos--;
            printf("El producto con código %d ha sido eliminado.\n", codigo);
            return;
        }
    }
    printf("No se encontró ningún producto con el código: %d\n", codigo);
}