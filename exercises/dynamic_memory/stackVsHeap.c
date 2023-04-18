#include <stdio.h>
#include <stdlib.h>

//Tipo de estructura para poder almacenar 2 punteros en una sola variable
typedef struct dosPunteros {
    int *p1;
    int *p2;
} dosPunteros;
        
//Funcion que devuelve 2 punteros: uno a su stack y otro al heap
dosPunteros prueba () {
    int x; //reserva memoria en el stack
    dosPunteros dp;
    
    x = 10;
    dp.p1 = &x;
    dp.p2 = (int*) malloc(sizeof(int)); //reserva en el heap
    *(dp.p2) = 20;
    return dp;
}

//Funcion que reserva memoria en el stack
//Se usa solo para hacer evidente la falla
void usaStack () {
    int v[10000], i;

    for (i = 0; i < 10000; i++)
        v[i] = 666;
}

int main () {
    dosPunteros d;

    d = prueba ();
    usaStack ();
    printf ("%p %d\n", d.p1, *d.p1); //Imprime basura
    printf ("%p %d\n", d.p2, *d.p2); //Imprime 20
    
    free(d.p2);
    return 0;
}
