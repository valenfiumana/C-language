// Genero archivo con datos ingresados por usuario de 10 pizzas (struct)

#include <stdio.h>
#include <stdlib.h>

typedef struct pizzas {
    char nombre[20];
    float precio;
} pizza;

int main() {
    FILE *archivo;
    pizza p;
    int i;

    archivo = fopen("precioproductos.dat", "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    printf("Ingrese los datos de las pizzas:\n");
    for (i = 0; i < 10; i++) {
        printf("Nombre: ");
        scanf("%s", p.nombre);
        printf("Precio: ");
        scanf("%f", &p.precio);

        fwrite(&p, sizeof(pizza), 1, archivo);
    }

    fclose(archivo);

    printf("Datos de las pizzas almacenados en el archivo precioproductos.dat.\n");

    return 0;
}
