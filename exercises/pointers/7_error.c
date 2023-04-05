/* Suponga que primero, ultimo y medio son punteros del mismo tipo y
primero y ultimo apuntan al primer y �ltimo elemento de un vector. Si quiere
que medio apunte al elemento que est� en la mitad del vector �por qu� la siguiente
instrucci�n es inv�lida y c�mo se podr�a solucionar?*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *primero, *ultimo, *medio;

    primero = &a[0];
    int a_len = *(&a + 1) - a -1;
    ultimo = &a[a_len];

    medio = primero + a_len/2;

    printf("Address: %p, Value: %d \n", primero, *primero);
    printf("Address: %p, Value: %d \n", ultimo, *ultimo);
    printf("Address: %p, Value: %d \n", medio, *medio);
    return 0;
}