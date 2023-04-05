/*
Escriba un programa que permita al usuario ingresar valores enteros en una matriz de 3x3 y luego imprima los elementos de la diagonal principal.
Usar notación aritmética de punteros (no subíndices []) para recorrer la matriz.
*/

#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 3

void ingresarMatriz(int matrix[][COL], int rows, int cols){
    printf("Ingresa elementos en matriz %dx%d\n", rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            // (*(matrix + i) + j == &matrix[i][j]
            scanf("%d", (*(matrix + i) + j));
        }
    }
}

void imprimirMatriz(int (*matrix)[COL], int rows, int cols){
    printf("\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            // *(*(matrix + i) + j) == matrix[i][j]
            printf("\t%d", *(*(matrix + i) + j));
        }
        printf("\n\n");
    }
}

void diagonalPrincipal(int (*matrix)[COL], int rows, int cols){
    printf("Diagonal principal:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(i==j){
                printf("\t%d", *(*(matrix + i) + j));
            }
        }
        printf("\n\n");
    }
}


int main()
{
    int m[ROW][COL];
    int *p;

    ingresarMatriz(m, ROW, COL);
    imprimirMatriz(m, ROW, COL);
    diagonalPrincipal(m, ROW, COL);
    return 0;
}