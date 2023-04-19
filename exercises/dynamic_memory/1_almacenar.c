/*
Escribir un programa en el que el usuario informa la cantidad de elementos que va a
ingresar y luego los valores de los elementos (enteros).
Los elementos deben almacenarse en un vector y luego en el archivo vector.dat. No
se debe limitar la cantidad de elementos.
*/

#include <stdio.h>
#include <stdlib.h>

// Grabar vector en archivo
void grabar(int* vector, int n) {
    FILE* fp;
    int w, c;

    // Abrir
    fp = fopen("vector.dat", "wb");
    if (fp == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    // Escribir
    w = fwrite(vector, sizeof(int), n, fp);
    if (w != n){
        printf ("Error grabando");
    }

    // Cerrar
    c = fclose(fp);
    if (c != 0){
        printf ("Error cerrando");
    }

    printf("El vector se ha guardado correctamente en el archivo vector.dat.\n");
}
int main()
{
    int cant;
    int* v; //Puntero al vector dinámico

    printf("Ingrese cantidad de elementos a ingresar: \n");
    scanf("%d", &cant);

    // Asigno memoria dinámica para el vector
    v = (int*) malloc (sizeof(int) * cant);
    if (v == NULL){
        printf("ERROR: no se pudo asignar memoria dinamica. \n");
        return -1;
    }

    // Le pido valores al usuario
    printf("Ingrese valores para cada elemento: \n");
    for (int i=0; i<cant; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &v[i]);
    }

    // Guardo vector
    grabar(v, cant);

    // Libero memoria dinamica
    free(v);
    v = NULL;

    return 0;
}
