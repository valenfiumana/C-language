/* Ejemplo que pide la carga de datos de productos finalizando cuando nombre="*".
Va reservando memoria a medida que se ingresa un nuevo producto
Luego graba lo ingresado en un archivo, lo cierrra, lo lee y calcula el promedio 
de aquellos cuyo nombre empieza con "c"*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct producto 
	{
	char nombre[10];
	float precio;
	int stock;
	} prod;

/*
Esta funcion recibe un vector de productos y la cantidad, y lo graba en el archivo
*/
void grabar (prod *v, int n) {
	FILE *f;
	int w;
	
	f = fopen ("productos.dat", "w");
	if (f != NULL) {
		w = fwrite (v, sizeof (prod), n, f);
		if (w != n)
			printf ("Error grabando");
		if (fclose (f) != 0)
			printf ("Error cerrando");
	}
	else 
		printf ("Error creando");
}

/*
Esta funcion recibe un entero representando la cantidad de productos a leer 
desde un archivo, reserva memoria para esa cantidad y los lee retornando un vector
*/
prod *leer (int n) {
	FILE *f;
	int r;
	prod *v; 

	v = (prod*) malloc (sizeof (prod) * n);
	f = fopen ("productos.dat", "r");
	if (f != NULL) {
		r = fread (v, sizeof (prod), n, f);
		if (r != n)
			printf ("Error leyendo");
		if (fclose (f) != 0)
			printf ("Error cerrando");
	}
	else 
		printf ("Error abriendo");
	return v;
}

/*
Programa principal
*/
int main () {
	int n = 0, i, c = 0;
	char nombre[10];
	float total = 0;
	prod *v = NULL, *v2;

	printf ("Ingrese el nombre del producto (* finaliza):");
	scanf ("%s", nombre);
	while (strcmp (nombre, "*") != 0) { //Mientras el nombre no sea "*"
		n++;
		v = (prod*) realloc (v, sizeof (prod) * n); //Cambio el tamanio del vector a n
        //Copio los datos sobre la ultima posicion del vector (n - 1)
		strcpy (v[n - 1].nombre, nombre);
		printf ("\nIngrese el precio:");
		scanf ("%f", &v[n - 1].precio);
		printf ("\nIngrese el stock:");
		scanf ("%d", &v[n - 1].stock);

        //Solicito otro nombre de producto
		printf ("Ingrese el nombre del producto (* finaliza):");
		scanf ("%s", nombre);
	}
	
	grabar (v, n); //Grabo el vector en el archivo
	free (v); //Libero el primer vector porque ya lo grabe en el archivo
	v2 = leer (n); //Leo el archivo en un nuevo vector

	//Calculo el promedio de precio de los prod. cuyo nombre empieza con "c"
	for (i = 0; i < n; i++)
		if (v2[i].nombre[0] == 'c') {
			total += v2[i].precio;
			c++;
		}
	free (v2); //Libero el vector que use para leer del archivo

	if (c != 0)
		printf ("El promedio de los que empiezan con c es: %f\n", total / c);
	else
		printf ("No hay ninguno que empiece con c\n");
	
	return 0;
}