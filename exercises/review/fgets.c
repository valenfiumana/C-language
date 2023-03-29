/*Ejemplo de uso de la funci�n fgets() para leer caracteres de un archivo
Este programa permite ingresar una cadena que contiene espacios.
*/

#include <stdio.h>

int main()
{
    char nombre_y_ape[100];

    printf("Ingres� tu nombre y apellido:");

    /*Los tres argumentos de fgets() son:
        cadena de destino
        cantidad m�xima de caracters a leer (para no pasarse del tama�o del string)
        archivo de origin stdin representa la entrada estandar (teclado) */
    fgets(nombre_y_ape, sizeof(nombre_y_ape), stdin);

    printf("Hola %s\n", nombre_y_ape);

    return 0;
}
