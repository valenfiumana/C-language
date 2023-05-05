/* 
8. Buscar un elemento numérico en una lista y eliminarlo. 
Considerar que puede ser el primero, último o intermedio.
 */

#include <stdio.h>
#include <stdlib.h>

/* Declaración de la estructura para los nodos (tipo de datos) */
typedef struct nodo {
    int dato;
    struct nodo *sig;
} nodo;

/* Inserta al principio */
nodo *insertar_lifo (nodo *l, int d) {
    nodo *nuevo;
    
    nuevo = (nodo *) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = l;
    return nuevo;
}

/* Muestra los elementos de la lista */
void mostrar (nodo *l) {
    printf ("Lista");
    while (l != NULL) {
        printf (" --> %d", l->dato);
        l = l->sig;
    }
    printf ("\n");
}

/* Libera toda la memoria ocupada por la lista */
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

/* Elimina un nodo de la lista */
nodo *eliminar (nodo* l, int d) {
    nodo *ret = l, *aux;

    if (l == NULL) { /* 1er caso: Si la lista es nula no hay que hacer nada */
        printf ("La lista esta vacia\n");
    }
    else { /* La no lista es nula */
        if (l->dato == d){ /* 2do caso: el nodo a borrar es el primero */
            ret = l->sig;
            free (l);
            printf ("Elemento eliminado\n");
        } 
        else { /* 3er caso: el nodo a borrar no es el primero */
            while (l->sig != NULL && l->sig->dato != d)
                l = l->sig;
            if (l->sig != NULL) { /* Si l->sig es NULL es porque el dato no existe en l */
                aux = l->sig;
                l->sig = aux->sig;
                free (aux);
                printf ("Dato %d eliminado\n", d);
            }
            else { /* Si l->sig es NULL */
                printf ("El dato %d no se encuentra en la lista\n", d);
            }
        }
    }
    return ret; /* Va a ser el nuevo principio de la lista */
}

/* Pide entros hasta que se ingrese cero y los inserta en la lista */
nodo *ingresa_usuario (nodo *lista) {
    int temp;

    printf ("Ingrese un nro entero (cero finaliza):");
    scanf ("%d", &temp);
    while (temp != 0) {
        lista = insertar_lifo (lista, temp);
        printf ("\nIngrese otro nro entero (cero finaliza):");
        scanf ("%d", &temp);
    }
    return lista;   
}

int main() {
    nodo *lista = NULL;
    int x; 

    /* Inserta en la lista general los valores que ingrese el usuario */
    lista = ingresa_usuario (lista);
    mostrar (lista);

    /* Busqueda pedida en el enunciado */
    printf ("Ingrese un valor a eliminar:");
    scanf ("%d", &x);
    lista = eliminar (lista, x);
    mostrar (lista);
    
    /* Destruir lista (liberar memoria) */
    lista = destruir (lista);
    
    return 0;
}