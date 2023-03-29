// 3. Escribir una función que reciba las coordenadas cartesianas de 2 puntos en el espacio y devuelva la distancia euclídea.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int x;
    int y;
    int z;
}tvector;

float distanciaEuclidea(tvector v, tvector w){
    float temp = pow(v.x - w.x, 2) + pow(v.y - w.y, 2) + pow(v.z - w.z, 2);
    return sqrt(temp);
}

int main()
{
    tvector v, w;
    v.x = 0;
    v.y = 0;
    v.z = 0;

    w.x = 1;
    w.y = 1;
    w.z = 0;

    printf("Distancia: %f\n", distanciaEuclidea(v, w));
    return 0;
}
