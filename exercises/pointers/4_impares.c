// 4. Escribir una funci�n que reciba un vector de enteros y su tama�o, y devuelva la cantidad de n�meros impares que contiene.

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
