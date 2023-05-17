#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[20];
    float precio;
} pizza;

int main() {
    FILE *archivo;
    pizza pizzas[10];

    // Pedir al usuario que ingrese los nombres y precios de las pizzas
    printf("Ingrese los datos de las pizzas:\n");
    for (int i = 0; i < 10; i++) {
        printf("Pizza %d\n", i + 1);
        printf("Nombre: ");
        scanf("%s", pizzas[i].nombre);
        printf("Precio: ");
        scanf("%f", &pizzas[i].precio);
    }

    // Abrir el archivo en modo escritura binaria
    archivo = fopen("precioproductos.dat", "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Escribir las pizzas en el archivo
    fwrite(pizzas, sizeof(pizza), 10, archivo);

    // Cerrar el archivo
    fclose(archivo);

    printf("Archivo creado exitosamente.\n");

    return 0;
}
