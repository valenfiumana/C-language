// 2. Escribir un programa que genere una lista doble y ordenada. Generar un listado en pantalla de la misma comenzando desde cada extremo.


#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_d {
	float dato; /* Podría ser otro tipo de dato */
	struct nodo_d *ant, *sig;
} nodo_d;

/* La lista doble esta representada por una estructura con 2 punteros: primero y ultimo */
typedef struct ldoble {
	nodo_d *prim, *ult;
} lista;

void insertar_ordenado(lista *l, float dato) {
    //Creo un nuevo nodo
    nodo_d *nuevo_nodo = (nodo_d*) malloc(sizeof(nodo_d));
    nuevo_nodo->dato = dato;
    nuevo_nodo->ant = NULL;
    nuevo_nodo->sig = NULL;

    // Si la lista está vacía, nuevo_nodo es el primer y último nodo
    if (l->prim == NULL) {
        l->prim = nuevo_nodo;
        l->ult = nuevo_nodo;
        return;
    }

    // Si el dato ingresado es <= primer dato, nuevo_nodo se convierte en el primer nodo
    if (dato <= l->prim->dato) {
        nuevo_nodo->sig = l->prim;
        l->prim->ant = nuevo_nodo;
        l->prim = nuevo_nodo;
        return;
    }

    // Si el dato ingresado es  >= último dato, nuevo_nodo se convierte en último nodo
    if (dato >= l->ult->dato) {
        nuevo_nodo->ant = l->ult;
        l->ult->sig = nuevo_nodo;
        l->ult = nuevo_nodo;
        return;
    }

    // Busco la posición en la lista para insertar nuevo_nodo
    nodo_d *nodo_actual = l->prim;
    while (nodo_actual != NULL && nodo_actual->dato < dato) { //mientras dato ingresado sea mayor al del nodo actual, me sigo moviendo en la lista
        nodo_actual = nodo_actual->sig;
    }

    // Inserto nuevo_nodo antes del nodo actual
    nuevo_nodo->sig = nodo_actual;
    nuevo_nodo->ant = nodo_actual->ant;
    nodo_actual->ant->sig = nuevo_nodo;
    nodo_actual->ant = nuevo_nodo;
}

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

void displayReverse(lista l) {
    nodo_d* temp = l.ult;

    printf("\nLista al reves:\n");

    // Recorre la lista desde el final hasta el principio
    while (temp->ant != NULL) {
        printf("%.2f -> ", temp->dato);
        temp = temp->ant;
    }
    printf("%.2f ", temp->dato);

    printf("\n");
}

/* Destruye la lista liberando la memoria ocupada por cada nodo */
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
	nodo_d *p; /* Puntero para recorrer la lista */
	float f;
	float nodo;
	lista l; /* La lista propiamente dicha */
	int modo; /* Como quiero insertar: lifo o fifo */

	/* Inicializo la lista */
	l.prim = NULL;
	l.ult = NULL;

    printf("Ingrese los datos (0 para terminar): ");
	scanf("%f", &f);
	do{
	    // Paso un puntero a la lista porque necesito modificar los punteros de la lista
        insertar_ordenado(&l, f);
        printf("Ingrese los datos (0 para terminar): ");
        scanf("%f", &f);
	} while (f!=0);



	display(l);
	displayReverse(l);

	l = destruir (l);
	return 0;
}
