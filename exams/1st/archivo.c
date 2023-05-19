/*
Este archivo se generó usando la siguiente estructura en C (struct):

typedef struct estructura{
    int codigo;
    char objeto[20];
}estructura;

Y en su interior contiene nombres de distintos objetos y un número entero asociado al objeto (números comprendidos entre 1000 y 9999).

Lo que usted debe hacer con el archivo es:

1. Descargarlo en su computadora.
2. Crear un programa en C que lea los datos del archivo y los inserte en una única lista simple según el siguiente criterio:

a) Si el código numérico (int) del objeto es PAR: insertarlo con el método "FIFO".
b) Si el código numérico (int) del objeto es IMPAR: insertarlo con el método "LIFO".
3. Descartar de la lista aquellos objetos (o nodos) cuyos códigos sean mayores o iguales a 9000.
4. Averiguar en qué posición de la lista queda el nodo con el objeto "lavadora", considerando que el primer
nodo estará en la posición 1, el segundo en la posición 2, y así sucesivamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct estructura{
    int codigo;
    char objeto[20];
}estructura;

typedef struct nodo {
    int codigo;
    char objeto[20];
    struct nodo *sig;
} nodo;

// INSERTAR LIFO
nodo *insertar_lifo (nodo *l, estructura e){
    //printf("Insertando nodo con codigo IMPAR %d modo LIFO\n", e.codigo);
    nodo *nuevo;
    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->codigo = e.codigo;
    strcpy(nuevo->objeto, e.objeto);
    nuevo->sig = l;
    return nuevo;
}

// INSERTAR FIFO
nodo *insertar_fifo(nodo *l, estructura e) {
    //printf("Insertando nodo con codigo PAR %d modo FIFO\n", e.codigo);
    nodo *nuevoNodo;
    nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->codigo = e.codigo;
    strcpy(nuevoNodo->objeto, e.objeto);
    nuevoNodo->sig = NULL;  // porque ahora es el último nodo

    if (l == NULL) {
        return nuevoNodo;
    }

    nodo *temp = l;
    while (temp->sig != NULL) {
        temp = temp->sig;
    }

    // ahora temp es el último nodo
    temp->sig = nuevoNodo;
    return l;
}

// LEER ARCHIVO E INSERTAR EN LISTA
nodo *leer (nodo *l) {
    FILE *archivo;
    estructura e;

    archivo = fopen("archivo.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    else{
        while (fread (&e, sizeof(estructura), 1, archivo) == 1) {
            if(e.codigo %2 == 0){
                l = insertar_fifo(l, e);
            }
            else{
                l = insertar_lifo(l, e);
            }

        }
        if (fclose (archivo) != 0) {
            printf("\nError al cerrar el archivo\n");
            exit (2);
        }
    }
    return l;
}

//MOSTRAR LISTA
void mostrar (nodo *l) {
    while (l != NULL) {
        printf ("\n %d - %s \n", l->codigo, l->objeto);
        l = l->sig;
    }
}

// ELIMINAR SEGUN CODIGO
nodo* eliminar(nodo* l, int c) {
    nodo* actual = l;   // Puntero para recorrer la lista
    nodo* previo = NULL;  // Puntero al nodo anterior al nodo actual

    while (actual != NULL) {
        if (actual->codigo >= c) {  // Si el código del nodo actual es mayor o igual a c
            nodo* siguiente = actual->sig;  // Guardar el siguiente nodo en un puntero temporal
            free(actual);  // Liberar la memoria del nodo actual
            if (previo != NULL) {
                previo->sig = siguiente;  // Conectar el nodo anterior al siguiente nodo
            } else {
                l = siguiente;  // Si el nodo anterior es NULL, el siguiente nodo se convierte en el nuevo primer nodo
            }
            actual = siguiente;  // Mover al siguiente nodo
        } else {
            previo = actual;  // Avanzar al siguiente nodo
            actual = actual->sig;
        }
    }

    return l;  // Devolver el puntero al primer nodo de la lista actualizada
}

// BUSCAR POR NOMBRE
void buscar (nodo *l, char nombre[20]) {
    int pos = 1;
    while (l != NULL) {
        if(strcmp(l->objeto, nombre)==0){
            printf("\nEl nodo con objeto %s esta en la posicion %d\n", l->objeto, pos);
            return;
        }
        else{
            l = l->sig;
            pos++;
        }
    }
}

// DESTRUIR
nodo *destruir (nodo *l) {
    nodo * aux;

    while (l != NULL) {
        aux = l;
        l = l->sig;
        free (aux);
    }
    printf ("\nlista destruida\n");
    return NULL;
}

int main()
{
    nodo *lista = NULL;
    lista = leer (lista);
    mostrar(lista);
    lista = eliminar(lista, 9000);

    printf("\nLista con codigos mayores o iguales a 9000 eliminados: \n");
    mostrar(lista);

    buscar(lista, "lavadora");

    destruir(lista);

    return 0;
}