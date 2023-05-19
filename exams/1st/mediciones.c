/* Dos estudiantes de la univseridad nacional del sur desarrollaron un detector de monoxido de carbono
CO, que sule ser generado por el mal funcionamiento de estufas y calderas.
Diseñaron la electronica desde cero y puede hacer llamados telefonicos antes una emergencia.
Supongamos que para si pureba necesitan las ultimas mediciones  de CO medido en ppm y temperatura en c .
Ejemplos de estas mediciones son (130, 20.10); (59, 18.93); etc.
Estas mediciones se encuentran grabadas en un archivo binario, una a continuacion de la otra, en el orden que fueron tomadas.
Se pide hacer un menu repetitivo con la siguientes opciones:
1- leer las mediciones del marchivo mediciones.dat y almacenarlas en una lista de forma tal que la primera medicion en la lista sea la mas reciente y asi sucesivamente
2- agregar una nueva medicion (ppm y temp) por teclado al final de la lista
3- encontrar y mostrar la maxima y minima contaminacion ppm  en la lista de mediciones
4- eliminar de la lista la medicion que tenga minimaa conentracion y tambien la que tenga la maxima
5- salir del programa
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mediciones {
    int co;
    float temp;
} medicion;

typedef struct nodo {
    int co;
    float temp;
    struct nodo *sig;
} nodo;

// MENU
int menu (void) {
    int op;

    printf ("\n\n - - - - - - - - MENU - - - - - - - - ");
    printf ("\n1. Leer archivo e insertar LIFO en SLL");
    printf ("\n2. Agregar FIFO una nueva medicion");
    printf ("\n3. Maxima y minima contaminacion de CO en ppm");
    printf ("\n4. Eliminar minima y maxima contaminacion de CO");
    printf ("\n5. Guardar archivo");
    printf ("\n0. Salir");
    printf ("\nOpcion: ");
    scanf ("%d", &op);
    return op;
}


//MOSTRAR LISTA
void mostrar (nodo *l) {
    while (l != NULL) {
        printf ("\n %d ppm - %.2f grados\n", l->co, l->temp);
        l = l->sig;
    }
}


// INSERTAR
nodo *insertar_fifo(nodo *l, medicion m) {
    nodo *nuevoNodo;
    nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->co = m.co;
    nuevoNodo->temp = m.temp;
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



// INSERTAR LIFO
nodo *insertar_lifo (nodo *l, medicion m){
    //printf("Insertando nodo con codigo IMPAR %d modo LIFO\n", e.codigo);
    nodo *nuevo;
    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->temp = m.temp;
    nuevo->co = m.co;
    nuevo->sig = l;
    return nuevo;
}

// LEER ARCHIVO E INSERTAR EN LISTA
nodo *leer (nodo *l) {
    FILE *archivo;
    medicion m;

    archivo = fopen("mediciones.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    else{
        while (fread (&m, sizeof(medicion), 1, archivo) == 1) {
            l = insertar_lifo(l, m);
        }
        if (fclose (archivo) != 0) {
            printf("\nError al cerrar el archivo\n");
            exit (2);
        }
    }
    return l;
}

//MAXIMO
int maximo (nodo *l) {
    int max = l->co;
    while (l != NULL) {
        if(l->co > max){
            max = l->co;
        }
        l = l->sig;
    }
    return max;
}

//MINIMO
int minimo (nodo *l) {
    int min = l->co;
    while (l != NULL) {
        if(l->co < min){
            min = l->co;
        }
        l = l->sig;
    }
    return min;
}

// ELIMINAR CO
nodo* eliminar(nodo* l, int c) {
    nodo* actual = l;   // Puntero para recorrer la lista
    nodo* previo = NULL;  // Puntero al nodo anterior al nodo actual

    while (actual != NULL) {
        if (actual->co == c) {  // Si el código del nodo actual es igual a c
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

// LEER ARCHIVO E INSERTAR EN LISTA
void guardar(nodo* l) {
    FILE* archivo;
    archivo = fopen("mediciones.dat", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    nodo* aux = l;
    while (aux != NULL) {
        medicion m;
        m.co = aux->co;
        m.temp = aux->temp;
        fwrite(&m, sizeof(medicion), 1, archivo);
        aux = aux->sig;
    }

    if (fclose(archivo) != 0) {
        printf("Error al cerrar el archivo.\n");
        exit(2);
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
    int op;
    medicion m;
    nodo *lista = NULL;
    do{
        op = menu();
        switch(op){
            case 1:
                lista = leer(lista);
                mostrar(lista);
                break;
            case 2:
                printf("CO medido en ppm: ");
                scanf("%d", &m.co);
                printf("Temperatura en grados Celsius: ");
                scanf("%f", &m.temp);
                insertar_fifo(lista, m);
                mostrar(lista);
                break;
            case 3:
                printf("La maxima concentracion de Co es %d y la minima %d\n", maximo(lista), minimo(lista));
                break;
            case 4:
                eliminar(lista, maximo(lista));
                eliminar(lista, minimo(lista));
                mostrar(lista);
                break;
            case 5:
                guardar(lista);
                break;
            case 0:
                lista = destruir(lista);
                break;
            default:
                printf("Debe ser un numero del 1 al ");

        }
    } while (op!=0);
    return 0;
}
