/* Implemente una función que reciba un vector de números en punto flotante y un entero
que representa el tamaño del vector y devuelva el promedio.
Usar notación aritmética de punteros (no subíndices []) para recorrer el vector. */

#include <stdio.h>
#include <stdlib.h>

void promedio(float *v, int tam){
    float suma = 0;
    for(int i=0; i<tam; i++){
        suma += *(v+i);
    }
    printf("El promedio del vector es %.2f", suma/(tam));
}

int main()
{
    float v[] = {8.5, 8.5, 8.5, 8.5, 8.5, 9.5, 9.5, 9.5, 9.5, 9.5};
    int v_len = *(&v + 1) - v;

    promedio(v, v_len);
    return 0;
}
