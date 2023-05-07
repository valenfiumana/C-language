/*4. El Instituto de Nanosistemas (INS), creado por la Universidad Nacional de San Martín en 2014, es un espacio de investigación
científica en el campo de la nanotecnología. Dado que trabaja con productos químicos, para soportar su sistema de información
se le a usted pide escribir un programa que implemente un menú cíclico con las siguientes opciones:
1. Leer un archivo binario con registros que tienen la siguiente estructura
    * Código de producto: entero de 16 bits
    * Nombre del producto: cadena de hasta 20 caracteres
    * Precio por unidad de masa: flotante simple precisión
    * Stock en gramos: flotante doble precisión
Los datos se deben agregar al final de una lista doblemente enlazada manteniendo el orden del archivo (lista maestra)
2. Agregar un producto ingresado por teclado a final de la lista maestra
3. Eliminar un elemento de la lista maestra dado su código
4. Generar una versión ordenada de lista, pudiendo ser el orden por cualquiera de los 4 campos según la elección del usuario
5. Mostrar la lista dando la opción de hacerlo con la maestra / ordenada en sentido directo / inverso
6. Sobrescribir en archivo con los datos de la lista maestra
7. Informar si en la lista maestra hay productos con nombre duplicado y en caso afirmativo informar los códigos de al menos el primer caso de duplicación encontrado (si lo necesita puede hacer uso de la lista ordenada)
8. Salir

Las opciones del menú deben poder usarse en cualquier orden y número de veces
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct product{
    int codigo;
    char nombre[20];
    float precio;
    double stock;
} producto;

typedef struct nodo_d {
	producto dato; /* Podría ser otro tipo de dato */
	struct nodo_d *ant, *sig;
} nodo_d;

// La lista doble esta representada por una estructura con 2 punteros: primero y ultimo
typedef struct ldoble {
	nodo_d *prim, *ult;
} lista;

lista leer_archivo(char *nombre_archivo) {
    FILE *archivo;
    producto p;
    lista l;

    archivo = fopen(nombre_archivo, "rb");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    l.prim = NULL;
    l.ult = NULL;

    while (fread(&p, sizeof(producto), 1, archivo) == 1) {
        /* Crear un nuevo nodo con el producto leído */
        nodo_d *nuevo = (nodo_d*) malloc(sizeof(nodo_d));
        nuevo->dato = p;

        /* Insertar el nuevo nodo al final de la lista */
        if (l.prim == NULL) /* Lista vacía */
            l.prim = nuevo;
        else {
            l.ult->sig = nuevo;
            nuevo->ant = l.ult;
        }
        l.ult = nuevo;
    }

    fclose(archivo);

    return l;
}

void display(lista l) {
    nodo_d* temp = l.prim;

    printf("\nContenido de la lista:\n");

    // Recorre la lista desde el principio hasta el final
    while (temp != NULL) {
        printf("Codigo: %d | Nombre: %s | Precio: %.2f | Stock: %.2f\n",
               temp->dato.codigo, temp->dato.nombre, temp->dato.precio, temp->dato.stock);
        temp = temp->sig;
    }

    printf("\n");
}

lista insertar_fifo(lista l, producto p) {
    nodo_d *nuevo;

    nuevo = (nodo_d*) malloc(sizeof(nodo_d));
    nuevo->dato = p;
    nuevo->sig = NULL;
    nuevo->ant = l.ult;

    if (l.prim == NULL) /* Lista vacia, l.prim y l.ult son NULL */
        l.prim = nuevo;
    else
        l.ult->sig = nuevo;
    l.ult = nuevo;
    return l;
}

lista eliminar(lista l, int codigo) {
    nodo_d* p = l.prim;
    while (p != NULL && p->dato.codigo != codigo) {
        p = p->sig;
    }
    if (p != NULL) { /* Se encontró el nodo */
        if (p->ant != NULL) /* El nodo a borrar no es el primero */
            p->ant->sig = p->sig;
        else  /* El nodo a borrar es el primero */
            l.prim = p->sig;
        if (p->sig != NULL) /* El nodo a borrar no es el ultimo */
            p->sig->ant = p->ant;
        else  /* El nodo a borrar es el ultimo */
            l.ult = p->ant;
        free(p);
        display(l);
    }
    else {
        printf("No se encontro el nodo con el codigo %d", codigo);
    }
    return l;
}

lista ordenar_por_codigo(lista l) {
    nodo_d *p, *q, *min;
    producto temp;

    for (p = l.prim; p != NULL; p = p->sig) {
        min = p;
        for (q = p->sig; q != NULL; q = q->sig) {
            if (min->dato.codigo > q->dato.codigo)
                min = q;
        }
        if (min != p) {
            temp = min->dato;
            min->dato = p->dato;
            p->dato = temp;
        }
    }
    return l;
}



void displayReverse(lista l) {
    nodo_d* temp = l.ult;

    printf("\nLista al reves:\n");

    // Recorre la lista desde el final hasta el principio
    while (temp != NULL && temp->ant != l.prim->ant) {
        printf("Codigo: %d | Nombre: %s | Precio: %.2f | Stock: %.2f\n",
               temp->dato.codigo, temp->dato.nombre, temp->dato.precio, temp->dato.stock);
        temp = temp->ant;
    }

    // Imprime el último nodo que no se imprimió en el while
    printf("Codigo: %d | Nombre: %s | Precio: %.2f | Stock: %.2f\n",
           temp->dato.codigo, temp->dato.nombre, temp->dato.precio, temp->dato.stock);

    printf("\n");
}


/* Destruye la lista liberando la memoria ocupada por cada nodo */
lista destruir (lista l) {
	nodo_d *p, *aux;

	p = l.prim;
	while (p != NULL) {
		aux = p;
		p = p->sig;
		free (aux);
	}
	printf ("Lista destruida\n");
	l.prim = NULL;
	l.ult = NULL;
	return l;
}

void verificar_duplicados(lista l) {
    nodo_d* temp1 = l.prim;
    nodo_d* temp2;
    int duplicado = 0;

    while (temp1 != NULL && temp1->sig != NULL) {
        temp2 = temp1->sig;
        while (temp2 != NULL) {
            if (strcmp(temp1->dato.nombre, temp2->dato.nombre) == 0) {
                printf("Se encontró un producto duplicado: %s - codigo %d\n", temp2->dato.nombre, temp2->dato.codigo);
                duplicado = 1;
            }
            temp2 = temp2->sig;
        }
        temp1 = temp1->sig;
    }
    if(duplicado == 0){
        printf("No se encontraron duplicados");
    }
}

void guardar_archivo(char* nombre_archivo, lista l) {
    FILE* archivo;
    nodo_d* temp = l.prim;

    archivo = fopen(nombre_archivo, "wb");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    while (temp != NULL) {
        fwrite(&temp->dato, sizeof(producto), 1, archivo);
        temp = temp->sig;
    }

    fclose(archivo);
    printf("\nArchivo guardado exitosamente");
}

int main() {
	int op;
	lista l; /* La lista propiamente dicha */
	producto p;
	int cod;
	int c;

	/* Inicializo la lista */
	l.prim = NULL;
	l.ult = NULL;

    char *nombre_archivo = "productos.dat";

	do{
        printf("\n- - - - - - MENU - - - - - - -\n ");
        printf("\n1. Leer un archivo binario con registros\n2. Agregar un producto ingresado por teclado a final de la lista maestra");
        printf("\n3. Eliminar un elemento dado su codigo\n4. Generar una version ordenada de lista (por codigo)");
        printf("\n5. Mostrar la lista\n6. Sobreescribir archivo");
        printf("\n7. Informar si hay duplcados\n8. Salir\n\nElija una opcion: ");
        scanf ("%d", &op);

        switch(op){
            case 1:
                /* Leer el archivo y crear la lista */
                l = leer_archivo(nombre_archivo);
                /* Mostrar la lista */
                display(l);
                break;
            case 2:
                printf("Ingrese datos de producto a agregar:\n");
                printf("Codigo: ");
                scanf("%d", &p.codigo);
                printf("Nombre: ");
                scanf("%s", p.nombre);
                printf("Precio: ");
                scanf("%f", &p.precio);
                printf("Stock: ");
                scanf("%lf", &p.stock);

                insertar_fifo(l, p);
                printf("\nProducto agregado, ahora la lista es: \n");
                display(l);
                break;
            case 3:
                printf("Ingrese codigo de producto a eliminar: ");
                scanf("%d", &cod);
                eliminar(l, cod);
                break;
            case 4:
                l = ordenar_por_codigo(l);
                display(l);
                break;
            case 5:
                printf("Mostrar en sertido directo (1) o inverso (0): \n");
                scanf("%d", &c);
                if(c == 1)
                    display(l);
                else
                    displayReverse(l);
                break;
            case 6:
                guardar_archivo(nombre_archivo,l);
                break;
            case 7:
                verificar_duplicados(l);
                break;
            case 8:
                break;
            default:
                printf("\nSeleccione una opcion del 1 al 8");
                break;
            }
	    } while (op<1 || op>8 || op!=8);

    l = destruir(l);
    return 0;
}
