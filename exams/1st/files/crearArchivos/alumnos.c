/*
archivo: "alumnos.dat"
estructura:
char nombre[20];
int legajo;
float calificacion;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct alumnos {
    char nombre[20];
    int legajo;
    float calificacion;
} alumno;

int main() {
    FILE *archivo;
    alumno a;
    int i;

    archivo = fopen("alumnos.dat", "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    printf("Ingrese los datos de los alumnos (0 para terminar):\n");
    while (1) {
        printf("Legajo: ");
        scanf("%d", &a.legajo);
        if (a.legajo == 0)
            break;
        printf("Nombre: ");
        scanf("%s", a.nombre);
        printf("Calificacion: ");
        scanf("%f", &a.calificacion);
        fwrite(&a, sizeof(alumno), 1, archivo);
    }

    fclose(archivo);

    printf("Datos de los alumnos almacenados en el archivo alumnos.dat.\n");

    return 0;
}
