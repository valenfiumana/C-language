// Creo archivo con numeros enteros entre 102 y 107 random

#include <stdio.h>
#include <stdlib.h> //para rand() y srand(seed)
#include <time.h> //para time()


int main(){
    int num, maximo=107, minimo=102;
    FILE *archivo;

    archivo = fopen("muestras.dat", "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    srand(time(0));
    for(int i=0; i<15; i++){
        num = rand() % (maximo-minimo+1) + minimo;
        fwrite(&num, sizeof(int), 1, archivo);
    }

    // Cerrar el archivo
    fclose(archivo);

    printf("Archivo creado exitosamente.\n\n");

    archivo = fopen("muestras.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    printf("Contenido del archivo: \n");
    while (fread(&num, sizeof(int), 1, archivo) == 1) {
        printf("%d\n", num);
    }

    fclose(archivo);

    return 0;
}
