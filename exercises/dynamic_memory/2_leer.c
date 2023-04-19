/*Escribir un programa para leer el archivo vector.dat del ejercicio anterior y almacenarlo en un vector.
No se conoce la cantidad de elementos y no se puede limitar.*/

#include <stdio.h>
#include <stdlib.h>

// Función para cargar el vector desde un archivo
int* cargar(int* n) {
    FILE* archivo;
    int* vector;

    // Abrir el archivo
    archivo = fopen("vector.dat", "rb");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo.\n");
        exit(1);
    }

    // Obtener el tamaño del archivo (cantidad de elementos)
    fseek(archivo, 0, SEEK_END); // Muevo el puntero al final del archivo
    long size = ftell(archivo); // Consigo la posición actual del puntero (tamaño del archivo en bytes)
    *n = size / sizeof(int); // Calculo cantidad de elementos (tamaño del archivo dividido el tamaño de un entero)

    // Asignar memoria dinámica para el vector
    vector = (int*)malloc((*n) * sizeof(int));
    if (vector == NULL) {
        printf("Error: No se pudo asignar memoria dinámica.\n");
        fclose(archivo);
        exit(1);
    }

    // Volver al principio del archivo
    // Con fseek me fui para abajo de todo, tengo que subir
    rewind(archivo);

    // Leer archivo y almacenar en vector
    fread(vector, sizeof(int), *n, archivo);

    // Cerrar el archivo
    fclose(archivo);

    return vector;
}

int main() {
    int n; // Cant elementos
    int* vector;

    vector = cargar(&n); // Le paso direccion de memoria de n para que pueda modificar el valor de n dentro de la función
    //y que el cambio se refleje también en la variable n en la función main


    // Mostrar
    printf("[  ");
    for (int i = 0; i < n; i++) {
        printf("%d  ", vector[i]);
    }
    printf("]");

    // Liberar memoria dinámica
    free(vector);

    return 0;
}
