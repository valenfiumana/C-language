/*
1- leer archivo conformando lista simple
2- MENU:
        1- Agregar un alumno a la lista
        2- Calcular promedio e informar alumnos con calificaciones superiores al promedio
        3- Modificar la calificacion de un alumno conociendo su legajo
        4- FIN DEL MENU
3- Grabar los nuevos datos en un archivo y finalizar.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct alumnos {
    char nombre[20];
    int legajo;
    float calificacion;
} alumno;

typedef struct nodo {
    char nombre[20];
    int legajo;
    float calificacion;
    struct nodo *sig;
} nodo;

// INSERTAR
nodo *insertar_fifo(nodo *l, alumno a) {
    nodo *nuevoNodo;
    nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->legajo = a.legajo;
    nuevoNodo->calificacion = a.calificacion;
    strcpy(nuevoNodo->nombre, a.nombre);
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
    alumno a;

    archivo = fopen("alumnos.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    else{
        while (fread (&a, sizeof(alumno), 1, archivo) == 1) {
            l = insertar_fifo(l, a);
        }
        if (fclose (archivo) != 0) {
            printf("\nError al cerrar el archivo\n");
            exit (2);
        }
    }
    return l;
}

// MENU
int menu (void) {
    int op;

    printf ("\n\n - - - - - - - - MENU - - - - - - - - ");
    printf ("\n1. Agregar un alumno a la lista");
    printf ("\n2. Calcular promedio e informar alumnos con calificaciones superiores al promedio");
    printf ("\n3. Modificar la calificacion de un alumno conociendo su legajo");
    printf ("\n4. Mostrar");
    printf ("\n0. Salir");
    printf ("\nOpcion: ");
    scanf ("%d", &op);
    return op;
}

//MOSTRAR LISTA
void mostrar (nodo *l) {
    while (l != NULL) {
        printf ("\n%d - %s - %.2f \n", l->legajo, l->nombre, l->calificacion);
        l = l->sig;
    }
}

// MAYOR A TOPE
void mayorATope (nodo *l, float tope) {
    while (l != NULL) {
        if(l->calificacion > tope){
            printf("%s - %.2f \n", l->nombre, l->calificacion);
        }
        l = l->sig;
    }
}

//PROMEDIO
float promedio (nodo *l) {
    float suma = 0;
    int n=0;
    while (l != NULL) {
        suma+= l->calificacion;
        n++;
        l = l->sig;
    }
    printf("El promedio de los alumnos es %.2f\n", suma/n);
    return suma/n;

}

nodo* buscar(nodo* l) {
    int d;
    float nota;

    printf("Inserte legajo a buscar: \n");
    scanf("%d", &d);

    printf("Inserte nota nueva:\n");
    scanf("%f", &nota);

    nodo* ret = l; // Puntero al principio de la lista

    if (l == NULL) { // 1er caso: Si la lista está vacía, no hay que hacer nada
        printf("La lista está vacía\n");
    }
    else { // La lista no está vacía
        nodo* aux = l;
        while (aux != NULL) {
            if (aux->legajo == d) { // Encontrar el nodo con el legajo deseado
                aux->calificacion = nota; // Modificar la nota del nodo encontrado
                break; // Salir del bucle
            }
            aux = aux->sig; // Avanzar al siguiente nodo
        }
        if (aux == NULL) { // Si se recorrió toda la lista y no se encontró el legajo
            printf("El legajo %d no se encuentra en la lista\n", d);
        }
    }
    return ret; // Retornar el nuevo principio de la lista
}

// LEER ARCHIVO E INSERTAR EN LISTA
void guardar(nodo* l) {
    FILE* archivo;
    archivo = fopen("alumnos.dat", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    nodo* aux = l;
    while (aux != NULL) {
        alumno a;
        strcpy(a.nombre, aux->nombre);
        a.legajo = aux->legajo;
        a.calificacion = aux->calificacion;
        fwrite(&a, sizeof(alumno), 1, archivo);
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
    int op, v;
    nodo *lista = NULL;
    alumno a;
    float prom;
    lista = leer (lista);
    mostrar(lista);

    do{
        op = menu();
        switch(op){
            case 1:
                printf("\nIngrese los datos del alumno a agregar:\n");
                printf("Legajo: ");
                scanf("%d", &a.legajo);
                printf("Nombre: ");
                scanf("%s", a.nombre);
                printf("Calificacion: ");
                scanf("%f", &a.calificacion);
                lista = insertar_fifo(lista, a);
                break;
            case 2:
                prom = promedio(lista);
                mayorATope(lista, prom);
                break;
            case 3:
                buscar(lista);
                break;
            case 4:
                mostrar(lista);
                break;
            case 0:
                guardar(lista);
                lista = destruir(lista);
                break;
            default:
                printf("Debe ser un numero del 1 al 5");
        }
    } while (op!=0);
    return 0;
}
