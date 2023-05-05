/*
7. Se tiene una lista ordenada de números enteros y se pide hacer una función que inserte un
elemento a la lista, manteniéndola ordenada.
*/

#include <stdio.h>
#include <stdlib.h>

/*Declaración de la estructura para los nodos (tipo de datos)*/
typedef struct nodo{
    int dato;
    struct nodo *sig;   
} nodo;

/*Inserta en orden*/
nodo *insertar_ordenado(nodo *l, int d) {
    nodo *nuevo, *aux;
    
    nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = d;
    if (l == NULL || l->dato > d) { 
        /*Lista vacia o primer elemento > nuevo*/
        nuevo->sig = l;
        return nuevo;
    }
    /*Si llega hasta aca => lista no vacia y nuevo > primer*/
    aux = l;
    while (aux->sig != NULL && aux->sig->dato <= d)
        aux = aux->sig;
    /*Salio del ciclo => aux->sig es NULL o aux->sig->dato > d*/
    /*Inserto el nuevo entre aux y aux->sig*/
    nuevo->sig = aux->sig;
    aux->sig = nuevo;
    return l;
}

/*Muestra los elementos de la lista*/
void mostrar (nodo *l) {
    printf ("Lista");
    while (l != NULL) {
        printf (" --> %d", l->dato);
        l = l->sig;
    }
    printf ("\n");
}

/*Libera toda la memoria ocupada por la lista*/
nodo *destruir (nodo *l) {
    nodo * aux;

    while (l != NULL) {
        aux = l;
        l = l->sig;
        free (aux);
    }
    printf ("lista destruida\n");
    return NULL;
}

/*Programa principal que hace uso de las funciones definidas arriba*/
int main () {
    nodo *lista = NULL;
    int x;
    
    /*Generamos una lista con tres nodos*/
    lista = insertar_ordenado (lista, 10);
    lista = insertar_ordenado (lista, 2);
    lista = insertar_ordenado (lista, 5);
    mostrar (lista);
    
    /*Permite inserter un valor arbitrario a la lista*/
    printf ("Ingrese un valor a agregar:");
    scanf ("%d", &x);
    lista = insertar_ordenado (lista, x);
    mostrar (lista);
    
    /*Destruir lista (liberar memoria)*/
    lista = destruir(lista);
    
    return 0;
}