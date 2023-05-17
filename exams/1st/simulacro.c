
/*
1. Cargar los 10 nombres de productos (char 20) y su precios unitarios (float), contenidos en el
archivo "precioproductos.dat".
2. Permitir cargar un nuevo pedido a la lista de pedidos, por orden de llegada, con los siguientes
datos:
o numpedido (valor entero)
o numcombo (valor entero, del 1 al 10) -> los números del 1 al 10 identificarán los
distintos tipos de pizzas.
o cantidad (valor entero)
o totalapagar (valor decimal, calculado a partir de los precios que tendrá la lista o vector
de productos/precios)
3. Mostrar:
a) Los nombres (char 20) de los 10 tipos de pizzas que ofrecen para la venta y su precio unitario
(float).
b) Mostrar la lista de pedidos en curso: numpedido, numcombo, cantidad, totalapagar.
4. Permitir ingresar por teclado el nombre de un producto y de encontrarse, permitir actualizar su
precio en el vector de productos/precios.
5. Recalcular el valor del dato totalapagar de cada pedido que haya en la lista, buscando el nuevo
precio cargado luego de ejecutar la opción del punto 4.
6. Salir del programa.*/

#include <stdio.h>
#include <stdlib.h>

// STRUCT
typedef struct tiposPizza {
    char nombre[20];
    float precio;
} pizza;

// NODO
typedef struct nodo {
    int numpedido;
    int numcombo;
    int cantidad;
    float totalapagar;
    struct nodo *sig;
} nodo;


// MENU
int menu (void) {
    int op;

    printf ("\n\n - - - - - - - - MENU - - - - - - - - ");
    printf ("\n1. Cargar pizzas");
    printf ("\n2. Agregar pedido");
    printf ("\n3. Mostrar");
    printf ("\n4. Actualizar precio");
    printf ("\n5. Recalcular totalapagar");
    printf ("\n0. Salir");
    printf ("\nOpcion: ");
    scanf ("%d", &op);
    return op;
}

// CREO VECTOR
void crearVector (pizza v[10]) {
    FILE *archivo;
    pizza p;

    archivo = fopen("precioproductos.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    else{
        int c = fread(v, sizeof(pizza), 10, archivo);
        if(c!=10){
            perror("Error al leer el archivo");
            return(-2);
        }
        if (fclose (archivo) != 0) {
            printf("\nError al cerrar el archivo\n");
            exit (2);
        }
    }
}

// INSERTAR AL FINAL
nodo *insert_fifo (nodo *l, int combo, int cant, int pedido, pizza v[10]){
    nodo *nuevo;
    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->numcombo = combo;
    nuevo->cantidad = cant;
    nuevo->numpedido = pedido;
    nuevo->totalapagar = v[pedido-1].precio * cant;
    nuevo->sig = NULL;
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

// MOSTRAR VECTOR (PIZZAS)
void mostrarPizzas(pizza v[10]){
    printf("\nP I Z Z A S\n");
    for(int i=0; i<10; i++){
        printf("%d) %s  - $%.2f\n", i+1, v[i].nombre, v[i].precio);
    }
}

// MOSTRAR LISTA (PEDIDOS)
void mostrarPedidos(nodo *l) {
    while (l != NULL) {
        printf ("\n Pedido: %d - Combo n: %d - Cantidad: %d - Total: $ %.2f \n", l->numpedido ,l->numcombo, l->cantidad, l->totalapagar);
        l = l->sig;
    }
}

void actualizarPrecio (pizza v[]){
    char nombre[10];
    float precio;

    printf ("Ingrese el nombre de la pizza a buscar: ");
    scanf ("%s", nombre);

    for (int i=0; i < 10; i++) {
        if (strcmp (nombre, v[i].nombre) == 0) {
            printf ("Ingrese el nuevo precio: ");
            scanf ("%f", &v[i].precio);
            printf("\nPrecio actualizado.");
            return;
        }
    }
    printf ("Nombre no encontrado");
}

// ACTUALIZO VALOR EN SLL
void recalcularTotal (nodo *l, pizza v[]){
    while (l != NULL) {
        l->totalapagar = v[l->numcombo - 1].precio * l->cantidad;
        l = l->sig;
    }
    printf("\nPrecio total actualizado. ");
}


// DESTRUIR LISTA
nodo *destruir (nodo *l){
    nodo *aux;
    while (l != NULL) {
        aux = l->sig;
        free (l);
        l = aux;
    }
}

int main() {
    int op, o;
    nodo *lista = NULL;
    pizza v[10];
    int combo, cant, pedido = 0;

    do{
        op = menu();
        switch(op){
            case 1:
                crearVector(v);
                for(int i=0; i<10; i++){
                    printf("%s\n", v[i].nombre);
                    printf("%.2f\n", v[i].precio);
                }
                break;
            case 2:
                printf("Ingrese num combo: \n");
                for(int i=0; i<10; i++){
                    printf("%d- %s\n", i+1, v[i].nombre);
                }
                scanf("%d", &combo);
                printf("Ingrese cantidad: ");
                scanf("%d", &cant);
                pedido++;
                lista = insert_fifo(lista, combo, cant, pedido, v);
                break;
            case 3:
                do{
                    printf("Desea ver lista de pizzas y precios (1) o lista de pedidos (2)? ");
                    scanf("%d", &o);
                } while(o!=1 && o!=2);
                if(o==1){
                    mostrarPizzas(v);
                }
                else if(o==2){
                    mostrarPedidos(lista);
                }
                break;
            case 4:
                actualizarPrecio(v);
                break;
            case 5:
                recalcularTotal(lista, v);
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
