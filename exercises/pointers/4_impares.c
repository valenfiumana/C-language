// 4. Escribir una función que reciba un vector de enteros y su tamaño, y devuelva la cantidad de números impares que contiene.

#include <stdio.h>

int impares (int *v, int tam){
    int imp = 0;
    for (int i = 0; i < tam ; i++){
        if(*(v+i) % 2 != 0){
            imp++;
        }
    }
    printf("El vector tiene %d impares", imp);
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    int *p = a;
    impares(p, 9);
    return 0;
}
