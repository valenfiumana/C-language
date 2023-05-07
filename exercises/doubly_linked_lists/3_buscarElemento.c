/*3. Para una lista doblemente enlazada, escribir una función para localizar un elemento:
* Si se lo encuentra mostrar su contenido y devolver 1.
* Si no se encuentra devolver 0.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_d {
	float dato; /* Podría ser otro tipo de dato */
	struct nodo_d *ant, *sig;
} nodo_d;

// La lista doble esta representada por una estructura con 2 punteros: primero y ultimo
typedef struct ldoble {
	nodo_d *prim, *ult;
} lista;

/* mostrar lista */
void display(lista l) {
    nodo_d* temp = l.prim;

    printf("\nContenido de la lista:\n");

    // Recorre la lista desde el principio hasta el final
    while (temp->sig != NULL) {
        printf("%.2f -> ", temp->dato);
        temp = temp->sig;
    }
    printf("%.2f ", temp->dato);

    printf("\n");
}


// Buscar elemento
void buscarElemento(lista l, float d){
    nodo_d *p;
    p = l.prim;

    while(p != NULL && p->dato!=d){
        p = p->sig;
    }

    if(p!=NULL){ //Se encontro el nodo
        printf("\nNodo con dato = %.2f encontrado\n", p->dato);
    } else { //No se encontro el nodo
        printf("\nNodo con dato = %.2f no encontrado\n", d);
    }
}

// Inserta al final del la lista
lista insertar_fifo(lista l, float d) {
	nodo_d *nuevo;

	nuevo = (nodo_d*) malloc(sizeof(nodo_d));
	nuevo->dato = d;
	nuevo->sig = NULL;
	nuevo->ant = l.ult;

	if (l.prim == NULL) /* Lista vacia, l.prim y l.ult son NULL */
		l.prim = nuevo;
	else
		l.ult->sig = nuevo;
	l.ult = nuevo;
	return l;
}

// Destruir la lista liberando la memoria ocupada por cada nodo
lista destruir (lista l) {
	nodo_d *p, *aux;

	p = l.prim;
	while (p != NULL) {
		aux = p;
		p = p->sig;
		free (aux);
	}
	printf ("\nLista destruida\n");
	l.prim = NULL;
	l.ult = NULL;
	return l;
}

int main() {
	float f;
	lista l; /* La lista propiamente dicha */

	/* Inicializo la lista */
	l.prim = NULL;
	l.ult = NULL;

	printf("Ingrese los datos (0 para terminar): ");
	scanf("%f", &f);
	while (f != 0) {
        l = insertar_fifo(l, f);
        printf("Ingrese los datos (0 para terminar): ");
        scanf("%f", &f);
    }


    display(l);

    printf("\nIngrese valor a buscar: ");
    scanf("%f", &f);
    buscarElemento(l, f);

    l = destruir (l);

    return 0;
}