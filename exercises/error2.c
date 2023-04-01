/* Suponga que primero, ultimo y medio son punteros del mismo tipo y
primero y ultimo apuntan al primer y último elemento de un vector. Si quiere
que medio apunte al elemento que está en la mitad del vector ¿por qué la siguiente
instrucción es inválida y cómo se podría solucionar?*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = {5, 15, 34, 54, 14, 2, 52, 72};
    int* primero, medio, ultimo;

    primero = &a[1];
    return 0;
}
