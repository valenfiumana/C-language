/* 6. Escribir una función que busque un elemento de la lista, por comparación con una clave e
indique si se encuentra o no. Si se encuentra se informará este elemento y también el anterior
(en caso de existir).*/


#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
        int dato;
        struct nodo *sig;
} nodo;

nodo *insertar_lifo (nodo *l, int d)
    {
    nodo *nuevo;

    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = l;
    return nuevo;
    }

    void mostrar (nodo *l) {
    printf ("Lista");
    while (l != NULL) {
        printf (" --> %d", l->dato);
        l = l->sig;
    }
    printf ("\n");
}

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

nodo *buscar (nodo* l, int d) {
    nodo *ret = l, *aux;

    if (l == NULL) { /* 1er caso: Si la lista es nula no hay que hacer nada */
        printf ("La lista esta vacia\n");
    }
    else { /* La no lista es nula */
        if (l->dato == d){ /* 2do caso: el nodo es el primero */
            printf ("Elemento encontrado: %d\n", l->dato);
        }
        else { /* 3er caso: el nodo no es el primero */
            while (l->sig != NULL && l->sig->dato != d)
                l = l->sig;
            if (l->sig != NULL) { /* Si l->sig es NULL es porque el dato no existe en l */
                aux = l->sig;
                l->sig = aux->sig;
                printf ("Dato %d encontrado\n", d);
            }
            else { /* Si l->sig es NULL */
                printf ("El dato %d no se encuentra en la lista\n", d);
            }
        }
    }
    return ret; /* Va a ser el nuevo principio de la lista */
}

int main(){
    nodo *lista=NULL;
    float num;

    printf("Ingrese numeros y finalice con 0:\n");
    scanf("%f", &num);

    while (num!=0){
         lista = insertar_lifo (lista, num);
          printf("Ingrese numeros y finalice con 0:\n");
          scanf("%f", &num);
    }

    mostrar (lista);
    buscar(lista, 5);

    //Destruir lista
    lista = destruir (lista);

    return 0;
}
