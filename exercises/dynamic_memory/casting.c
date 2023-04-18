#include <stdio.h>

int main(){
    int x = 3;
    int *p1;
    void *p2;
    int *p3;

    p1 = &x;
    printf("El valor de x es %d \n", *p1);
    p2 = &x;
    //printf("El valor de x es %d", *p2); --> error de compilación (indirección inválida)
    printf("El valor de x es %d", * (int*) p2); // Convierto puntero tipo void a tipo int
}