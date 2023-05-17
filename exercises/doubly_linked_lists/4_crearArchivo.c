
#include <stdio.h>
#include <stdlib.h>

typedef struct product {
    int codigo;
    char nombre[20];
    float precio;
    double stock;
} producto;

int main() {
    FILE *archivo;
    producto p;

    // Abrir el archivo en modo escritura binaria
    archivo = fopen("productos.dat", "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Ingresar datos de los productos y escribirlos en el archivo
    printf("Ingrese los datos de los productos (0 para terminar):\n");
    while (1) {
        printf("Codigo: ");
        scanf("%d", &p.codigo);
        if (p.codigo == 0) break;
        printf("Nombre: ");
        scanf("%s", p.nombre);
        printf("Precio: ");
        scanf("%f", &p.precio);
        printf("Stock: ");
        scanf("%lf", &p.stock);
        fwrite(&p, sizeof(producto), 1, archivo);
    }

    // Cerrar el archivo
    fclose(archivo);

    printf("Archivo creado exitosamente.\n\n");

    archivo = fopen("productos.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    printf("Contenido del archivo: \n");
    while (fread(&p, sizeof(producto), 1, archivo) == 1) {
        printf("Codigo: %d\n", p.codigo);
        printf("Nombre: %s\n", p.nombre);
        printf("Precio: %.2f\n", p.precio);
        printf("Stock: %.2lf\n\n", p.stock);
    }

    fclose(archivo);

    return 0;
}