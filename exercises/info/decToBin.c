#include <stdio.h>

int main()
{
    int binary[8] = {0};  // Arreglo para almacenar los dígitos binarios
    int number, i;

    printf("Ingrese un número entero: ");
    scanf("%d", &number);

    // Conversión a binario
    for (i = 7; i >= 0; i--) { // Empiezo de atras para adelante a leer el numero
        binary[i] = number % 2; // Guardo el resto de dividir por 2
        number = number / 2; // Cuando el numero es muy pequeño guardo el 0
        //printf("\n%d", number);
    }

    printf("Número binario: ");

    // Imprimir los dígitos binarios
    for (i = 0; i < 8; i++) {
        printf("%d", binary[i]);
    }

    return 0;
}