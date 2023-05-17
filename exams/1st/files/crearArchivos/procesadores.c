/*
Se tiene el archivo procesadores.dat conformado por registros cuya estructura es la siguiente:

Nombre: texto (menos de 40 caracteres)
Velocidad en MHz: Entero (entre 1 y 6000)
Precio: Real (con 2 decimales)
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct procesadorS {
    char nombre[40];
    int velocidad;
    float precio;
} procesador;

int main() {
    FILE *archivo;
    procesador p;

    // Abrir el archivo en modo escritura binaria
    archivo = fopen("procesadores.dat", "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Ingresar datos de los procesadores y escribirlos en el archivo
    printf("Ingrese los datos de los procesadores (0 para terminar):\n");
    while (1) {
        printf("Velocidad: ");
        scanf("%d", &p.velocidad);
        if (p.velocidad == 0)
            break;
        printf("Nombre: ");
        scanf("%s", p.nombre);
        printf("Precio: ");
        scanf("%f", &p.precio);
        fwrite(&p, sizeof(procesador), 1, archivo);
    }

    // Cerrar el archivo
    fclose(archivo);

    printf("Archivo creado exitosamente.\n\n");

    archivo = fopen("procesadores.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    printf("Contenido del archivo: \n");
    while (fread(&p, sizeof(procesador), 1, archivo) == 1) {
        printf("Nombre: %s\n", p.nombre);
        printf("Velocidad: %d\n", p.velocidad);
        printf("Precio: %.2f\n", p.precio);
    }

    fclose(archivo);

    return 0;
}