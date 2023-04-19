/*Escriba las líneas necesarias para que p apunte a una estructura rectangulo
válida que tenga (10,25) como esquina superior izquierda y (20,15) como esquina
inferior derecha.*/

#include <stdio.h>
#include <stdlib.h>

struct punto {
    int x;
    int y;
};

struct rectangulo {
    struct punto superior_izq;
    struct punto inferior_der;
};

int main() {
    struct rectangulo *p;
    p = malloc(sizeof(struct rectangulo));
    p->superior_izq.x = 10; // pointer to struct ->
    p->superior_izq.y = 25; // struct to variable .
    p->inferior_der.x = 20;
    p->inferior_der.y = 15;

    printf("Esquina superior izquierda: (%d,%d)\n", p->superior_izq.x, p->superior_izq.y);
    printf("Esquina inferior derecha: (%d,%d)\n", p->inferior_der.x, p->inferior_der.y);

    free(p);

    return 0;
}
