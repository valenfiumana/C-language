/*
Se tiene el archivo procesadores.dat conformado por registros cuya estructura es la siguiente:

Nombre: texto (menos de 40 caracteres)
Velocidad en MHz: Entero (entre 1 y 6000)
Precio: Real (con 2 decimales)
Se pide hacer un programa que realice las siguientes tareas:

Leer el archivo conformando una lista simplemente enlazada.
Presentar un menú con las siguientes opciones:
Eliminar el primer procesador encontrado que tenga una velocidad menor a un umbral ingresado por teclado. ~
Mostrar los nombres de todos los procesadores en orden inverso al que se encontraban en el archivo.
Fin del menú.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct procesadorS {
    char nombre[40];
    int velocidad;
    float precio;
} procesador;

typedef struct nodo {
    char nombre[40];
    int velocidad;
    float precio;
    struct nodo *sig;
} nodo;

// MENU
int menu (void) {
    int op;

    printf ("\n\n - - - - - - - - MENU - - - - - - - - ");
    printf ("\n1. Mostrar lista");
    printf ("\n2. Eliminar procesador");
    printf ("\n3. Mostrar lista en orden inverso");
    printf ("\n0. Salir");
    printf ("\nOpcion: ");
    scanf ("%d", &op);
    return op;
}

//MOSTRAR LISTA
void mostrar (nodo *l) {
    while (l != NULL) {
        printf ("\n %s - %d MHz - $ %.2f \n", l->nombre, l->velocidad, l->precio);
        l = l->sig;
    }
}

//MOSTRAR INVERSA
void mostrar_inverso(nodo *l) {
    // Verifico si el nodo actual no es nulo
    if (l == NULL) {
        return;
    }
    // Llamada recursiva para avanzar al siguiente nodo
    // Esta llamada recursiva sigue hasta que llega al último nodo (con l->sig nulo)
    mostrar_inverso(l->sig);

    // Imprimir el nodo actual
    // A medida que la recursión retrocede, se imprimen los nodos comenzando desde el último nodo hasta el primer nodo
    printf("\n %s - %d MHz - $ %.2f \n", l->nombre, l->velocidad, l->precio);
}

// INSERTAR
nodo *insertar_fifo(nodo *l, procesador p) {
    nodo *nuevoNodo;
    nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->velocidad = p.velocidad;
    nuevoNodo->precio = p.precio;
    strcpy(nuevoNodo->nombre, p.nombre);
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
    procesador p;

    archivo = fopen("procesadores.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    else{
        while (fread (&p, sizeof(procesador), 1, archivo) == 1) {
            l = insertar_fifo(l, p);
        }
        if (fclose (archivo) != 0) {
            printf("\nError al cerrar el archivo\n");
            exit (2);
        }
    }
    return l;
}

// ELIMINAR SEGUN VELOCIDAD
nodo *eliminar(nodo *l, int v) {
    nodo *aux, *l2;

    if (l == NULL) {
        printf("\nElemento no encontrado");
        return NULL;
    }
    else if (l->velocidad < v) {
        aux = l->sig;
        free(l);
        printf("\nElemento eliminado");
        return aux;
    }
    else {
        l2 = l;
        while (l2->sig != NULL && l2->sig->velocidad >= v) {
            l2 = l2->sig;
        }
        if (l2->sig != NULL) {
            aux = l2->sig;
            l2->sig = aux->sig;
            free(aux);
            printf("\nElemento eliminado");
        }
        else {
            printf("\nElemento no encontrado");
        }
        return l;
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

int main() {
    int op, v;
    nodo *lista = NULL;

    do{
        op = menu();
        switch(op){
            case 1:
                lista = leer (lista);
                mostrar(lista);
                break;
            case 2:
                printf("Ingrese tope de velocidad: ");
                scanf("%d", &v);
                lista = eliminar(lista, v);
                mostrar(lista);
                break;
            case 3:
                mostrar_inverso(lista);
                break;
            case 0:
                lista = destruir(lista);
                break;
            default:
                printf("Debe ser un numero del 1 al 3");

        }
    } while (op!=0);
    return 0;
}