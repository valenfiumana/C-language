// Definir un tipo de dato que tenga dos campos: tipo (1, 2, o 3) y un segundo campo para el valor.
// El valor dependiendo del tipo debe permitir almacenar un int, un float o un double pero sólo uno simultáneamente.

#include <stdio.h>
#include <stdlib.h>

union valor{
    int lote;
    float precio;
    char nombre[10];
};

struct producto{
    int tipo_dato;
    union valor v;

};

void mostrar(struct producto p){
    switch(p.tipo_dato) {
        case 1:
            printf("\nNumero de lote: %d\n", p.v.lote);
            break;
        case 2:
            printf("\nPrecio: %ld\n", p.v.precio);
            break;
        case 3:
            printf("\nNombre: %s\n", p.v.nombre);
            break;
        default:
            printf("\nTipo invalido\n");
            break;
    }
}


int main()
{
    struct producto p;

    printf("Ingrese tipo de dato a guardar: \n(1 - lote\t 2 - precio\t 3 - nombre) \n\n");
    scanf("%d", &p.tipo_dato);

    switch(p.tipo_dato) {
        case 1:
            printf("Ingrese nro de lote: \n");
            scanf("%d", &p.v.lote);
            break;
        case 2:
            printf("Ingrese precio: \n");
            scanf("%f", &p.v.precio);
            break;
        case 3:
            printf("Ingrese nombre: \n");
            scanf("%s", p.v.nombre);
            break;
        default:
            printf("Tipo invalido\n");
            break;
    }

    mostrar(p);

    return 0;
}
