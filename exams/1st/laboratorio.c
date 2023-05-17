/*
En un laboratorio nuclear se tiene el archivo muestras.dat conformado por una cantidad indeterminada de números enteros. Estos números están en el rango entre
102 y 107 y representan el tiempo en segundos que tarda en desintegrarse una muestra.
No puede limitar la cantidad de números.
Se pide hacer un programa que realice las siguientes tareas:
I. Leer el archivo conformando una lista simple. Los nodos de la lista deben quedar en el mismo orden que en el archivo del que fueron leídos.
II. Presentar un menú con las siguientes opciones:
1- Agregar un nuevo elemento al principio de la lista.
2- Eliminar el primer elemento que coincida con un valor ingresado por teclado.
3- Informar el tiempo de desintegración más bajo de la lista.
4- Mostrar todos los tiempos de desintegración que son mayores a un valor ingresado por teclado e informar cuántos fueron.
5- Fin del menú.
Nota: Para cada opción del menú (excepto 5) se deberá usar al menos una función

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo *sig;
} nodo;

// MENU
int menu (void) {
    int op;

    printf ("\n\n - - - - - - - - MENU - - - - - - - - ");
    printf ("\n1. Leer archivo en lista");
    printf ("\n2. Agregar un nuevo elemento al principio");
    printf ("\n3. Eliminar elemento");
    printf ("\n4. Informar minimo");
    printf ("\n5. Informar mayores a tope");
    printf ("\n0. Salir");
    printf ("\nOpcion: ");
    scanf ("%d", &op);
    return op;
}

//MOSTRAR LISTA
void mostrar (nodo *l) {
    while (l != NULL) {
        printf (" --> %d", l->dato);
        l = l->sig;
    }
    printf ("\n");
}

// INSERTAR AL FINAL
nodo *insertar_fifo (nodo *l, int d){
    nodo *nuevo;
    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = NULL;  //bc now it's the last nodo
    if (l == NULL){
        return nuevo;
    }
    nodo *temp = l;
    while (temp->sig != NULL){
        temp = temp->sig;
    }
    temp->sig = nuevo;
    return l;
}

// LEER ARCHIVO E INSERTAR EN LISTA
nodo *leer (nodo *l) {
    FILE *archivo;
    int d;

    archivo = fopen("muestras.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    else{
        while (fread (&d, sizeof(int), 1, archivo) == 1) {
            l = insertar_fifo(l, d);
        }
        if (fclose (archivo) != 0) {
            printf("\nError al cerrar el archivo\n");
            exit (2);
        }
    }
    return l;
}

// INSERTAR AL PRINCIPIO
nodo *insertar_lifo (nodo *l, int d){
    nodo *nuevo;

    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = l;
    return nuevo;
}

// ELIMINAR SEGUN DATO INGRESADO
nodo *eliminar (nodo *l, int d) {
    nodo * aux, *l2;
    int encontrado = 0;

    if (l == NULL) {
        printf ("\nElemento no encontrado");
        return NULL;
    }
    else if (l->dato == d) {
        aux = l->sig;
        free (l);
        printf ("\nElemento eliminado");
        return aux;
    }
    else {
        l2 = l;
        while (l2->sig != NULL && !encontrado) {
            if (l2->sig->dato == d) {
                aux = l2->sig;
                l2->sig = aux->sig;
                free (aux);
                printf ("\nElemento eliminado\n");
                encontrado = 1;
            }
            else
                l2 = l2->sig;
        }
        if (encontrado == 0) printf ("\nElemento no encontrado\n");
        return l;
    }
}

// MINIMO
void minimo(nodo *l) {
    int min = l->dato;
    while (l != NULL) {
        if(l->dato < min){
            min = l->dato;
        }
        l = l->sig;
    }
    printf ("El minimo es %d \n", min);
}

// MAYOR A TOPE
void mayorTope(nodo *l, int tope) {
    int v[10], a = 0, flag = 0, cant=0;
    while (l != NULL) {
        //Si es mayor al tope
        if(l->dato > tope){
            cant++; // Sumo 1 a contador

            //Recorro vector con datos mayores a tope
            for(int i=0; i<10; i++){
                // Si el dato ya existe en el vector, no quiero agregarlo
                if(l->dato == v[i]){
                    flag = 1;
                }
            }
            // Si flag == 0 significa que el dato no existe en el vector, así que lo agrego
            if(flag==0){
                v[a] = l->dato;
                a++; // Uso la a para poder agregar valores al vector
            }
            flag = 0;
        }
        l = l->sig;
    }

    // Imprimo cantidad de datos que pasan el tope y recorro vector para mostrar valores
    printf("Los que pasan el tope de %d son %d con los valores: \n", tope, cant);
    for(int i=0; i<a; i++){
        printf(" %d  ", v[i]);
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
    int op, tope, d;
    nodo *lista = NULL;

    do{
        op = menu();
        switch(op){
            case 1:
                lista = leer(lista);
                mostrar(lista);
                break;
            case 2:
                printf("Ingrese elemento a insertar: ");
                scanf("%d", &d);
                lista = insertar_lifo(lista, d);
                mostrar(lista);
                break;
            case 3:
                printf("Ingrese elemento a eliminar: ");
                scanf("%d", &d);
                eliminar(lista, d);
                mostrar(lista);
                break;
            case 4:
                minimo(lista);
                break;
            case 5:
                printf("Ingrese tope: ");
                scanf("%d", &d);
                mayorTope(lista, d);
                break;
            case 0:
                lista = destruir(lista);
                break;
            default:
                printf("Debe ser un numero del 1 al 5");

        }
    } while (op!=0);
    return 0;
}