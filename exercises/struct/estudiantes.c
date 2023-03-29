// 1. Leer por teclado los detalles (legajo, nombre, promedio) de n estudiantes (n < 100) y almacenarlo en el archivo estudiantes.dat.
//2. Leer el archivo estudiantes.dat y mostrar el estudiante con el mayor promedio

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct estudiante{
    int legajo;
    char nombre[10];
    float promedio;
};


void grabar(struct estudiante v[], int i){
    int n;
    FILE* fp = fopen("estudiantes.dat", "wb");
    if(fp != NULL) {
        n = fwrite (v, sizeof(v[0]), i, fp); //sizeof(struct estudiante)
        if(n != i){
            printf("Error al grabar\n");
            fclose(fp);
            exit(4);
        }
        if( fclose(fp) != 0){
            printf("Error al cerrar\n");
            exit(5);
        }
    }
    else {
        printf("Error al abrir el archivo para escritura\n");
        exit(6);
    }

}

void mostrar(struct estudiante v[], int cant){
    for(int i=0; i<cant; i++){
        printf("Legajo: %d - Nombre: %s - Promedio %.2f \n", v[i].legajo, v[i].nombre, v[i].promedio);
    }
}

void mayorPromedio(struct estudiante v[], int cant){
    float max = 0;
    char name[10];
    for(int i=0; i<cant; i++){
        if(v[i].promedio > max){
            max = v[i].promedio;
            strcpy(name, v[i].nombre);
        }
    }
    printf("El estudiante con mayor promedio es %s con %.2f ", name, max);
}

void leerArchivo(struct estudiante v[], int i){
    int n;
    FILE *fp = fopen("estudiantes.dat", "rb");
    if(fp == NULL){
        perror("Error al abrir el archivo");
        exit(1);
    }
    n = fread(v, sizeof(v[0]), i, fp);

    if( fclose(fp) != 0){
        printf("Error al cerrar\n");
        exit(5);
    }
}

int main()
{
    struct estudiante v[MAX]; //vector de struct estudiante
    struct estudiante v2[MAX];
    int i=0, legajo;

    printf("Ingrese un numero de legajo y finalice con 0:\n");
    scanf("%d", &legajo);

    while(legajo != 0 && i<MAX){
        v[i].legajo = legajo;
        printf("Ingrese un nombre:\n");
        scanf("%s", v[i].nombre);
        printf("Ingrese un promedio:\n");
        scanf("%f", &v[i].promedio);

        i++;

        printf("Ingrese un numero de legajo y finalice con 0:\n");
        scanf("%d", &legajo);
    }

    grabar(v, i);
    leerArchivo(v2, i);
    mostrar(v2, i);
    mayorPromedio(v2, i);
    return 0;
}
