#include <stdio.h>
#include <stdlib.h>

int main () {
	int *ptr;

	//Reservo memoria para un int
    ptr = (int*) malloc (sizeof (int));

	if (ptr != NULL) { //Verifico si la pudo reservar
		*ptr = 10; //Almaceno un valor en la memoria reservada
		printf ("ptr recibio el valor (direccion) %p \n", ptr);
		printf ("El contenido de la direccion es %d \n", *ptr);
		free (ptr); //Libero la memoria
		ptr = NULL; //Buena practica poner en NULL el puntero liberado
	}
    return 0;
}