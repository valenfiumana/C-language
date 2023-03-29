// 3.1 Distancia entre dos puntos

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coordenadas{
    int x1;
    int y1;
    int x2;
    int y2;
};

double calcularDistancia(int x1, int y1, int x2, int y2)
{
    /*
        Aplicar la fórmula que dice:
        distancia = raiz_cuadrada_de(elevar_al_cuadrado(x1-x2) + elevar_al_cuadrado(y1-y2))
        Nota: no importa el orden de los puntos ni si la distancia al restar es negativa
    */
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    struct coordenadas c;
    printf("Ingrese la coordenada x1: \n");
    scanf("%d", &c.x1);

    printf("Ingrese la coordenada x2: \n");
    scanf("%d", &c.x2);

    printf("Ingrese la coordenada y1: \n");
    scanf("%d", &c.y1);

    printf("Ingrese la coordenada y2: \n");
    scanf("%d", &c.y2);

    double distancia = calcularDistancia(c.x1, c.y1, c.x2, c.y2);
    printf("La distancia entre (%d,%d) y (%d,%d) es %lf", c.x1, c.y1, c.x2, c.y2, distancia);

    return 0;
}
