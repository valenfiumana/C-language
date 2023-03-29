//El programa permite ingresar apellido, tipo y nro de documento de una persona, usando el
//tipo de datos adecuado para el nro segun el tipo de documento

#include <stdio.h>

/* Tipo de datos para almacenar un codigo de identificacion que puede tener distintos tipos */
union identidad {
    int dni; /* Ejemplo 40123456 (4 bytes) */
    long cuil; /* Ejemplo 20401234560 (8 bytes en sistema operativo de 64 bits) */
    char pasaporte[10]; /* Ejemplo "XDD123456" (10 bytes) */
};

/* Tipo de datos para almacenar apellido e identificacion de una persona */
struct persona {
    char apellido[20]; /* Ejemplo "Perez" */
    char tipo_documento; /* 1=dni / 2=cuil / 3=pasaporte */
    union identidad nro_documento;
};


/* Funcion que recibe una persona y muestra sus datos */
void mostrar(struct persona p)
{
    printf("Apellido: %s\n", p.apellido);

    switch(p.tipo_documento) {
        case 1:
            printf("Numero de DNI: %d\n", p.nro_documento.dni);
            break;
        case 2:
            printf("Numero de CUIL: %ld\n", p.nro_documento.cuil);
            break;
        case 3:
            printf("Numero de pasaporte: %s\n", p.nro_documento.pasaporte);
            break;
        default:
            printf("Tipo invalido\n");
            break;
    }
}

int main()
{
    struct persona p1; /* Declaro una variable de tipo struct persona*/

    printf("Ingrese apellido: ");
    scanf("%s", p1.apellido);

    printf("Ingrese tipo de identificacion (1=dni / 2=cuil / 3=pasaporte): ");
    scanf("%hhd", &p1.tipo_documento);
    printf("Ingrese nro de identificacion: ");
    switch(p1.tipo_documento) {
        case 1:
            scanf("%d", &p1.nro_documento.dni);
            break;
        case 2:
            scanf("%ld", &p1.nro_documento.cuil);
            break;
        case 3:
            scanf("%s", p1.nro_documento.pasaporte);
            break;
        default:
            printf("Tipo invalido\n");
            break;
    }

    /* Muestro los datos de la persona */
    mostrar (p1);

    return 0;
}
