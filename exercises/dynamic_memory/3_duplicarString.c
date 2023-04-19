/*
Escriba la función duplicar que reserve memoria dinámicamente para duplicar un string que se le pasa como argumento.
Por ejemplo, la llamada: p = duplicar (str); debe reservar memoria para un string de la misma longitud que str,
copiar los datos y retornar un puntero a la nueva cadena de caracteres.
Si la reserva de memoria falla, entonces duplicar debe retornar un puntero nulo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* duplicar(char* str) {
    char* p = (char*) malloc (strlen(str) + 1); // Reservo memoria dinámica (longitud str original + '\0') para el nuevo string

    if (p == NULL) {
        return NULL; // Puntero nulo si la reserva de memoria falla
    }

    strcpy(p, str); // Copio la cadena original al nuevo string

    return p; // Puntero al nuevo string
}

int main() {
    char str[] = "Buenas mundo!"; // Cadena a duplicar
    char* p = duplicar(str); // Duplicar cadena y guardar el puntero al nuevo string

    if (p == NULL) {
        printf("Puntero nulo: No se pudo duplicar la cadena.\n");
        return 1;
    }

    printf("Cadena original: %s\n", str);
    printf("Cadena duplicada: %s\n", p);

    free(p); // Liberar memoria dinámica

    return 0;
}
