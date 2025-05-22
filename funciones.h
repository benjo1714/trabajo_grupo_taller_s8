#include <stdio.h>
#include <string.h>

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

int tornillos, polimeros, cables, plastico, metal;
int totalProductos;
struct Producto productos[5];

// Función para ingresar productos
void ingresarProductos() {
    int p;
    printf("\n¿Cuantos productos va a ingresar? (maximo 5 en total): ");
    scanf("%d", &p);

    if (p <= 0) {
        printf("Debe ingresar al menos un producto.\n");
        return;
    }

    if (totalProductos + p > 5) {
        printf("Solo se pueden tener hasta 5 productos en total.\n");
        return;
    }

    for (int i = totalProductos; i < totalProductos + p; i++) {
        getchar();  // Limpiar buffer
        printf("\nIngrese el nombre del producto %d: ", i + 1);
        fgets(productos[i].nombre, 50, stdin);
        strtok(productos[i].nombre, "\n");  // Eliminar salto de línea

         int codigoRepetido;
         do {
            codigoRepetido = 0;
              printf("Ingrese el codigo del producto: ");
            scanf("%d", &productos[i].codigo);
            if (productos[i].codigo < 0) {
                  printf("El codigo no puede ser negativo.\n");
                codigoRepetido = 1;
                continue;
            }
           for (int j = 0; j < i; j++) {
    if (productos[j].codigo == productos[i].codigo) {
        printf("Codigo ya existente. Ingrese uno diferente.\n");
        codigoRepetido = 1;
        break;
    }
}
        } while (codigoRepetido);

        do {
            printf("Ingrese el tiempo de elaboracion (horas): ");
             scanf("%d", &productos[i].tiempo);
        } while (productos[i].tiempo < 0);

        do {
            printf("Tornillos necesarios: ");
            scanf("%d", &productos[i].tornillos);
         } while (productos[i].tornillos < 0);

        do {
            printf("Polimeros necesarios: ");
            scanf("%d", &productos[i].polimeros);
        } while (productos[i].polimeros < 0);

          do {
            printf("Cables necesarios: ");
            scanf("%d", &productos[i].cables);
        } while (productos[i].cables < 0);

           do {
            printf("Plastico necesario: ");
            scanf("%d", &productos[i].plastico);
        } while (productos[i].plastico < 0);

        do {
            printf("Metal necesario: ");
             scanf("%d", &productos[i].metal);
        } while (productos[i].metal < 0);
    }

    totalProductos += p;
}

// Función para aumentar recursos
void aumentarRecursos() {
    int extra;
    printf("\nIngrese recursos adicionales:\n");

    printf("Tornillos: "); scanf("%d", &extra); tornillos += extra;
       printf("Polimeros: "); scanf("%d", &extra); polimeros += extra;
    printf("Cables: "); scanf("%d", &extra); cables += extra;
     printf("Plastico: "); scanf("%d", &extra); plastico += extra;
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
        printf("Codigo: %d | Nombre: %s\n", productos[i].codigo, productos[i].nombre);
    }

    int codigo, cantidad;
    printf("\nIngrese el codigo del producto a fabricar: ");
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
            printf("Polimeros: %d\n", polimerosNecesarios);
            printf("Cables: %d\n", cablesNecesarios);
            printf("Plastico: %d\n", plasticoNecesario);
                printf("Metal: %d\n", metalNecesario);
            printf("Tiempo estimado total: %d horas\n", tiempoTotal);

            char confirmacion;
            printf("¿Desea continuar con la fabricacion? (s/n): ");
            scanf(" %c", &confirmacion);

            if (confirmacion == 's' || confirmacion == 'S') {
                tornillos -= tornillosNecesarios;
                polimeros -= polimerosNecesarios;
                cables -= cablesNecesarios;
                plastico -= plasticoNecesario;
                metal -= metalNecesario;
                printf("Fabricacion completada con exito.\n");
            } else {
                printf("Fabricacion cancelada.\n");
            }
            return;
        }
    }

    printf("Producto con codigo %d no encontrado.\n", codigo);
}

// Función para buscar producto por código
void buscarProductoPorID() {
    if (totalProductos == 0) {
        printf("No hay productos para buscar.\n");
        return;
    }
    printf("\nProductos disponibles:\n");
    for (int i = 0; i < totalProductos; i++) {
        printf("Codigo: %d\n", productos[i].codigo);
    }

    int codigo;
    printf("Ingrese el codigo del producto que desea buscar: ");
    scanf("%d", &codigo);
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].codigo == codigo) {
            printf("\nProducto encontrado:\n");
            printf("Codigo: %d\n", productos[i].codigo);
            printf("Nombre: %s\n", productos[i].nombre);
            return;
        }
    }
    printf("No se encontro ningun producto con el codigo: %d\n", codigo);
}

// Función para eliminar producto por código
void eliminarProductoPorID() {
    if (totalProductos == 0) {
        printf("No hay productos para eliminar.\n");
        return;
    }
    printf("\nProductos disponibles:\n");
    for (int i = 0; i < totalProductos; i++) {
        printf("Codigo: %d\n", productos[i].codigo);
    }

    int codigo;
    printf("Ingrese el codigo del producto que desea eliminar: ");
    scanf("%d", &codigo);
    for (int i = 0; i < totalProductos; i++) {
        if (productos[i].codigo == codigo) {
            for (int j = i; j < totalProductos - 1; j++) {
                productos[j] = productos[j + 1];
            }
            totalProductos--;
            printf("El producto con codigo %d ha sido eliminado.\n", codigo);
            return;
        }
    }
    printf("No se encontro ningun producto con el codigo: %d\n", codigo);
}
