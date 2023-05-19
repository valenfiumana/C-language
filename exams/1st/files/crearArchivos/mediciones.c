
#include <stdio.h>
#include <stdlib.h>

typedef struct mediciones {
    int co;
    float temp;
} medicion;

int main() {
    FILE *archivo;
    medicion m;
    int i;

    archivo = fopen("mediciones.dat", "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    printf("Ingrese los datos de las mediciones (0 para terminar):\n");
    while (1) {
        printf("CO medido en ppm: ");
        scanf("%d", &m.co);
        if (m.co == 0)
            break;
        printf("Temperatura en grados Celsius: ");
        scanf("%f", &m.temp);
        fwrite(&m, sizeof(medicion), 1, archivo);
    }

    fclose(archivo);

    printf("Datos de las mediciones almacenados en el archivo mediciones.dat.\n");

    return 0;
}
