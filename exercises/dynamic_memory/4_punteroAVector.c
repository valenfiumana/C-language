/*La función int *crear_vector (int n, int valor_inicial); debe retornar un puntero a un vector de enteros
de tamaño n creado dinámicamente cuyas posiciones son inicializadas con valor_inicial.
La función debe retornar NULL si no se puede reservar la memoria.*/

#include <stdio.h>
#include <stdlib.h>

int *crear_vector(int n, int valor_inicial) {
    int *vector = (int*) malloc (sizeof(int) * n); // Reservo memoria dinámica para el vector
    if (vector == NULL) {
        printf("No se pudo reservar memoria dinámica.\n");
        return NULL;
    }

    // Inicializo posiciones del vector con valor_inicial
    for (int i = 0; i < n; i++) {
        vector[i] = valor_inicial;
    }

    return vector; // Puntero al vector creado dinámicamente
}

int main() {
    int n = 5;
    int valor_inicial = 7;
    int *vector;

    vector = crear_vector(n, valor_inicial);

    if (vector != NULL) { // Verifico que se haya creado el vector
        printf("Vector creado dinamicamente:\n");
        printf("[ ");
        for (int i = 0; i < n; i++) {
            printf("%d ", vector[i]);
        }
        printf("]\n");

        free(vector); // Libero memoria
    }

    return 0;
}