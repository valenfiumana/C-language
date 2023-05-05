/*
9. Se tienen registros formados por un dato entero, un float y un nombre de hasta 30 caracteres. Escribir un programa que presente un menú repetitivo que permita las siguientes opciones:
a.  Leer un archivo binario insertando los datos en una lista ordenada por el dato entero.
b.  Agregar un nodo a la lista, ingresando los valores por teclado.
c.  Eliminar un nodo de la lista buscándolo por su clave (el valor entero).
d.  Mostrar la lista.
e.  Grabar la lista en un nuevo archivo binario (ingresar nombre por teclado)
f.  Salir.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estructura para guardar/leer los datos en el archivo */
typedef struct dato {
    int clave;
    float frac;
    char texto [30];
} dato;

/* Estructura para los nodos de la lista */
typedef struct nodo {
    int clave;
    float frac;
    char texto [30];
    struct nodo *sig;
} nodo;

/* Funcion que para insertar un nodo en forma ordenada por el entero */
nodo *insertar (nodo *l, dato d) {
    nodo *nuevo, *aux;

    nuevo = (nodo *) malloc (sizeof (nodo));
    nuevo->clave = d.clave;
    nuevo->frac = d.frac;
    strcpy (nuevo->texto, d.texto);
    if (l == NULL) {
       /* Lista vacia */
        nuevo->sig = NULL;
        return nuevo;
    }
    else if (l->clave > d.clave) {
        /* Primer elemento existente > nuevo */
        nuevo->sig = l;
        return nuevo;
    }
    else {
        /* Lista no vacia y nuevo > primero */
        aux = l;
        while (aux->sig != NULL && aux->sig->clave < d.clave)
            aux = aux->sig;
        /* Salio del ciclo => aux->sig es NULL o aux->sig->dato > d */
        /* Inserto el nuevo entre aux y aux->sig */
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
        return l;
    }
}

/* Funcion para mostrar la lista*/
void mostrar (nodo *l) {
    while (l != NULL) {
        printf ("\n%6d  %10.3f  %s", l->clave, l->frac, l->texto);
        l = l->sig;
    }
}

/* Funcion que lee el archivo e inserta los datos en la lista */
nodo *leer (nodo *l) {
    FILE *f;
    char nombre [30];
    dato d;

    printf ("\nNombre del arch: ");
    scanf ("%s", nombre);
    f = fopen (nombre, "rb");
    if (f != NULL) {
        while (fread (&d, sizeof (dato), 1, f) == 1) {
            l = insertar (l, d);
        }
        if (fclose (f) != 0) {
            printf("\nError al cerrar el archivo\n");
            exit (2);
        }
    }
    else {
        printf("\nError al abrir el archivo\n");
        exit (1);
    }
    return l;
}

/* Funcion para guardar los datos en el archivo */
void guardar (nodo *l) {
    FILE *f;
    char nombre [30];
    dato d;

    printf ("\nGuardar como: ");
    scanf ("%s", nombre);
    //Falta agregar las verificaciones !!
    f = fopen (nombre, "wb");
    if (f != NULL) {
        while (l != NULL) {
            d.clave = l->clave;
            d.frac =l->frac;
            strcpy (d.texto, l->texto);
            if (fwrite (&d, sizeof (dato), 1, f) != 1){
                printf("\nError al grabar en el archivo\n");
                exit (5);
            }
            l = l->sig;
        }
        if (fclose (f) != 0) {
            printf("\nError al cerrar el archivo\n");
            exit (4);
        }
        printf ("Lista guardada");
    }
    else {
        printf("\nError al crear el archivo\n");
        exit (3);
    }
}

/* Funcion para liberar la memoria de los nodos */
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

/* Funcion para mostar el menu y leer la opcion */
int menu (void) {
    int op;

    printf ("\n=======================================");
    printf ("\n1. Leer archivo");
    printf ("\n2. Nuevo nodo");
    printf ("\n3. Eliminar nodo");
    printf ("\n4. Mostrar lista");
    printf ("\n5. Grabar");
    printf ("\n6. Salir");
    printf ("\nOpcion: ");
    scanf ("%d", &op);
    printf ("=======================================");
    return op;
}

/* Funcion para eliminar el nodo buscado */
nodo *eliminar (nodo *l, int d) {
    nodo * aux, *l2;
    int encontrado = 0;

    if (l == NULL) {
        printf ("\nElemento no encontrado");
        return NULL;
    }
    else if (l->clave == d) {
        aux = l->sig;
        free (l);
        printf ("\nElemento eliminado");
        return aux;
    }
    else {
        l2 = l;
        while (l2->sig != NULL && !encontrado) {
            if (l2->sig->clave == d) {
                aux = l2->sig;
                l2->sig = aux->sig;
                free (aux);
                printf ("\nElemento eliminado");
                encontrado = 1;
            }
            else
                l2 = l2->sig;
        }
        if (encontrado == 0) printf ("\nElemento no encontrado");
        return l;
    }
}

/* Programa principal */
int main(void) {
    int op, clave;
    dato temp;
    nodo *lista = NULL;

    do {
        op = menu ();
        switch (op) {
            case 1:
                lista = leer (lista);
                break;
            case 2:
                printf ("\nIngrese: clave frac texto: ");
                scanf ("%d %f %s", &temp.clave, &temp.frac, temp.texto);
                lista = insertar (lista, temp);
                break;
            case 3:
                printf ("\nIngrese clave a borrar: ");
                scanf ("%d", &clave);
                lista = eliminar (lista, clave);
                break;
            case 4:
                mostrar (lista);
                break;
            case 5:
                guardar (lista);
                break;
            case 6:
                lista = destruir (lista);
                break;
            default:
                printf("\nIngrese una opcino valida");
        }
    } while (op != 6);
    return 0;
}