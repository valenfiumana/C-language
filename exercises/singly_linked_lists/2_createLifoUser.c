/*
2. Escribir un programa que cree una lista tipo LIFO (pila) con datos ingresados por el usuario.
Luego mostrar los datos. Liberar la memoria que se reservó al crearla.
 */


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

    //Destruir lista
    lista = destruir (lista);

    return 0;
}

