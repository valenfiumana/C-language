// Dada una lista enlazada, formada por números enteros, hacer un programa que la divida en dos listas: pares e impares.


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

void paroimpar(nodo *l, nodo **pares, nodo **impares){
    nodo *par=NULL, *impar=NULL;
    while (l != NULL) {
        if(l->dato %2==0)
            par = insertar_lifo (par, l->dato);

        else
            impar = insertar_lifo (impar, l->dato);

        l = l->sig;
    }
    *pares = par;
    *impares= impar;
}

/*
OTRA VERSION
void paroimpar(nodo *l, nodo **pares, nodo **impares){
    while (l != NULL) {
        if(l->dato %2==0)
            *pares = insertar_lifo (*pares, l->dato);

        else
            *impares = insertar_lifo (*impares, l->dato);

        l = l->sig;
    }
}*/

int main(){
    nodo *lista=NULL;
    nodo *pares=NULL, *impares=NULL;
    float num;

    printf("Ingrese numeros y finalice con 0:\n");
    scanf("%f", &num);

    while (num!=0){
         lista = insertar_lifo (lista, num);
          printf("Ingrese numeros y finalice con 0:\n");
          scanf("%f", &num);
    }
    printf ("Lista");
    mostrar (lista);

    paroimpar(lista,&pares,&impares);
    printf ("Pares");
    mostrar(pares);
    printf ("Impares");
    mostrar(impares);

    //Destruir lista
    lista = destruir (lista);

    return 0;
}

