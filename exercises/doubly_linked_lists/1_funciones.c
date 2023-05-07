//1. Programa que permite agregar elementos al final o al principio de una lista doble y la recorre en ambos sentidos


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

/* Inserta al principio del la lista */
lista insertar_lifo(lista l, float d) {
	nodo_d *nuevo;

	nuevo = (nodo_d*) malloc(sizeof(nodo_d));
	nuevo->dato = d;
	nuevo->ant = NULL;
	nuevo->sig = l.prim;

	if (l.prim == NULL) /* Lista vacia, l.prim y l.ult son NULL */
		l.ult = nuevo;
	else
		l.prim->ant = nuevo;
	l.prim = nuevo;
	return l;
}

/* Inserta al final del la lista, muy similar a insertar_lifo:
/* solo cambia ant por sig,y viceversa, prim por ult y viceversa */
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

// Dado un nodo, agregar uno nuevo antes
lista insertar_antes(lista l, nodo_d* nodo_despues, float valor) {
    // Verificar si el nodo_despues es NULL
    if (nodo_despues == NULL) {
        printf("el nodo dado no puede ser NULL");
        return l;
    }

    // Creo nuevo nodo y le asigno valor
    nodo_d* nuevo_nodo = (nodo_d*)malloc(sizeof(nodo_d));
    nuevo_nodo->dato = valor;

    // Le asigno el puntero "sig" del nuevo nodo al nodo_despues
    // y el puntero "ant" del nuevo nodo al nodo antes de nodo_despues
    nuevo_nodo->sig = nodo_despues;
    nuevo_nodo->ant = nodo_despues->ant;

    // Asigno el puntero "ant" del nodo_despues al nuevo nodo
    nodo_despues->ant = nuevo_nodo;

    // Actualizo el puntero "sig" del nodo anterior al nuevo nodo
    if (nuevo_nodo->ant != NULL) {
        nuevo_nodo->ant->sig = nuevo_nodo;
    } else {
        l.prim = nuevo_nodo; // Si el nuevo nodo se inserta al principio de la lista
    }

    return l;
}
// Dado un nodo, agregar uno nuevo despues
lista insertar_despues(lista l, nodo_d* nodo_antes, float valor) {

    // Verificar si el nodo_antes es NULL
    if (nodo_antes == NULL) {
        printf("el nodo dado no puede ser NULL");
        return l;
    }

    // Creo nuevo nodo y le asigno valor
    nodo_d* nuevo_nodo = (nodo_d*)malloc(sizeof(nodo_d));
    nuevo_nodo->dato = valor;

    // Le asigno el puntero "ant" del nuevo nodo al nodo_antes
    // y el puntero "sig" del nuevo nodo al nodo después de nodo_antes
    nuevo_nodo->ant = nodo_antes;
    nuevo_nodo->sig = nodo_antes->sig;

    // Asigno el puntero "sig" del nodo_antes al nuevo nodo
    nodo_antes->sig = nuevo_nodo;

    // Actualizo el puntero "ant" del nodo siguiente al nuevo nodo
    if (nuevo_nodo->sig != NULL) {
        nuevo_nodo->sig->ant = nuevo_nodo;
    } else {
        l.ult = nuevo_nodo; // Si el nuevo nodo se inserta al final de la lista
    }

    return l;
}

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

/* Destruye la lista liberando la memoria ocupada por cada nodo */
lista destruir (lista l) {
	nodo_d *p, *aux;

	p = l.prim;
	while (p != NULL) {
		aux = p;
		p = p->sig;
		free (aux);
	}
	printf ("Lista destruida\n");
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
	while (f != 0) {
	    do{
            printf ("\n1- LIFO (ppio) \n2- FIFO (final) \n3- MEDIO (Antes de nodo) \n4- MEDIO (Despues de nodo)\nEija opcion: ");
            scanf ("%d", &modo);

            switch(modo){
            case 1:
                l = insertar_lifo(l, f);
                break;
            case 2:
                l = insertar_fifo(l, f);
                break;
            case 3:
                printf("\nIngrese el valor del nodo posterior al que desea insertar: ");
                scanf("%f", &nodo);
                p = l.prim;
                while (p != NULL && p->dato != nodo) {
                    p = p->sig;
                }
                if (p == NULL) {
                    printf("El valor ingresado no se encuentra en la lista\n");
                } else {
                    l = insertar_antes(l, p, f);
                }
                break;
            case 4:
                printf("\nIngrese el valor del nodo anterior al que desea insertar: ");
                scanf("%f", &nodo);
                p = l.prim;
                while (p != NULL && p->dato != nodo) {
                    p = p->sig;
                }
                if (p == NULL) {
                    printf("El valor ingresado no se encuentra en la lista\n");
                } else {
                    l = insertar_despues(l, p, f);
                }
                break;
            }
	    } while (modo!=1 && modo!=2 && modo!=3 && modo!=4);

	    printf("\nIngrese los datos (0 para terminar): ");
	    scanf("%f", &f);
	}

	display(l);

	printf("\nMuestro en orden ingresado\n"); /* Al derecho, desde el principio */
	for (p = l.prim; p != NULL; p = p->sig)
	    printf("Dato = %6.2f\n", p->dato);

	printf("Muestro en orden inverso\n"); /* Al reves, desde el final */
	for (p = l.ult; p != NULL; p = p->ant)
	    printf("Dato = %6.2f\n", p->dato);

	l = destruir (l);
	return 0;
}