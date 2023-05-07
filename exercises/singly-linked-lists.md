# Singly Linked Lists
### General functions

Show list
```c
// Show list
void traverse(node *l) {
    while (l != NULL) {
        printf (" --> %d", l->data);
        l = l->next;
    }
    printf ("\n");
}
```

Free space
```c
// Free space
node *destroy (node *l) {
    node * aux;
    while (l != NULL) {
        aux = l; // aux == node
        l = l->next; // l == next node
        free (aux); // frees node in aux
    }
    printf ("\n\nList was destroyed\n");
    return NULL;
}
```

## Exercises

[Solución ejercicio 1 al 8](./singly_linked_lists/operations.c)

### Ejercicio 1 - 

Escriba una función que permita insertar un nuevo elemento antes del primer nodo de una lista enlazada de enteros.

[Solución](./singly_linked_lists/1_insertLIFO.c)

Función
```c
node *insert_lifo (node *l, int d){
    node *newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->data = d; // d == new data
    newNode->next = l; // l == head of node
    return newNode;
}
```

Implementación

```c
node *list = NULL;
list = insert_lifo(list, 11);
printf("\n\nList with new element (11) in the beginning: \n");
traverse(list);
```

### Ejercicio 2 - 

Escribir un programa que cree una lista tipo LIFO (pila) con datos ingresados por el usuario.
Luego mostrar los datos. Liberar la memoria que se reservó al crearla.

[Solución](./singly_linked_lists/2_createLifoUser.c)

Función
```c
// Insert at the beginning (LIFO)
node *insert_lifo (node *l, int d){
    node *newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->data = d; // d == new data
    newNode->next = l; // l == head of node
    return newNode;
}
```

Implementación
```c
    node *list = NULL;
    int num;

    printf("Enter int numbers and end with 0: \n");
    scanf("%d", &num);
    while(num != 0){
        list = insert_lifo(list, num);
        scanf("%d", &num);
    }
    printf("\n\nList created by user: \n");
    traverse(list);
```


### Ejercicio 3 - 

Escriba una función que devuelva la cantidad de elementos de una lista.

[Solución](./singly_linked_lists/3_length.c)

Función
```c
void length(node *l) {
    int cant = 0;
    while (l != NULL) {
        cant++;
        l = l->next;
    }
    printf ("\nThe list has %d elements\n", cant);
}
```

Implementación
```c
length(list);
```

### Ejercicio 4 - 

Dada una lista enlazada, formada por números enteros, hacer un programa que la divida en dos listas: pares e impares.

[Solución](./singly_linked_lists/4_twoSublists.c)

Función
```c
// New lists: even & odd
void separateEvenOdd(node *list, node **evenList, node **oddList) {
    node *even = NULL, *odd = NULL;
    while (list != NULL) {
        if (list->data % 2 == 0) {
            even = insert_lifo(even, list->data);
        } else {
            odd = insert_lifo(odd, list->data);
        }
        list = list->next;
    }
    *evenList = even;
    *oddList = odd;
}

```

Implementación
```c
    node *evenList = NULL, *oddList = NULL;
    separateEvenOdd(list, &evenList, &oddList);
    printf("\nEven list: ");
    traverse(evenList);
    printf("Odd list: ");
    traverse(oddList);
```

### Ejercicio 5 - 

Escribir una función que inserte un elemento después del último nodo de una lista enlazada.


Función
```c
//Insert at the end
node *insert_fifo (node *l, int d){
    node *newNode;
    newNode = (node*) malloc (sizeof (node));
    newNode->data = d;
    newNode->next = NULL;  //bc now it's the last node
    if (l == NULL){
        return newNode;
    }
    node *temp = l;
    while (temp->next != NULL){
        temp = temp->next;
    }
    // now temp is the last node
    temp->next = newNode;
    return l;
}
```

Implementación
```c
node *list = NULL;
insert_fifo(list, 100);
printf("\n\nList with new element (100) in the end: \n");
traverse(list);
```

### Ejercicio 6 - 

Escribir una función que busque un elemento de la lista, por comparación con una clave e indique si se encuentra o no. Si se encuentra se informará este elemento y también el anterior (en caso de existir).

[Solución](./singly_linked_lists/6_searchElement.c)

Función
```c
// Search node and print prev one
void searchAndPrev(node* l, int value) {
    int prev, found = 0;
    if(l->data == value){
        found = 1;
        printf("\nNode found: %d, Prev: NULL", l->data);

    }
    else{
        prev = l->data;
        while (l != NULL) {
            if (l->data == value) {
                found = 1;
                printf("\nNode found: %d, Prev: %d\n", l->data, prev);
            }
            prev = l->data;
            l = l->next;
        }
    }
    if (found == 0){
            printf("\nNode not found");
        }
}

```

Implementación
```c
    printf("\n\nEnter int number to search: \n");
    scanf("%d", &num);
    searchAndPrev(list, num);
```

### Ejercicio 7 - 

Se tiene una lista ordenada de números enteros y se pide hacer una función que inserte un elemento a la lista, manteniéndola ordenada.

[Solución](./singly_linked_lists/7_addKeepingOrder.c)

Función
```c
// Insert node keeping the list sorted in ascending order
void insert_sorted(node **head, int data) {
    // Allocate memory for new node
    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    // If list is empty or data of first node is greater than data to be inserted
    if (*head == NULL || (*head)->data > data) {
        new_node->next = *head; 
        *head = new_node; 
    }
    else {
        // Find the node before the point of insertion
        node *current = *head; 
        while (current->next != NULL && current->next->data < data) {
            current = current->next; 
        }
        // Insert new node at the correct position
        new_node->next = current->next; 
        current->next = new_node; 
    }
}
```

Implementación
```c
    printf("\n\nEnter int number to add: \n");
    scanf("%d", &num);
    insert_sorted(&list, num);
    printf("\nList with number added: \n");
    traverse(list);
```

### Ejercicio 8 - 

Buscar un elemento numérico en una lista y eliminarlo. Considerar que puede ser el primero, último o intermedio.

[Solución](./singly_linked_lists/8_searchAndDelete.c)

Función
```c
// Delete
void deleteNode(node** head, int key) {
  node *temp = *head, *prev;

  // If the head node itself holds the key to be deleted
  if (temp != NULL && temp->data == key) {
      *head = temp->next; // Update the head of the list to the next node
      destroy(temp); // Free the memory of the node being deleted
      return;
  }
  // Search for the key to be deleted, keeping track of previous node as well
  while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node by linking previous node to next node
  prev->next = temp->next;

  destroy(temp);
}

// Search
void search(node* head, int data) {
    int found = 0;
    node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            deleteNode(&current, data); // Found node with given data
            found = 1;
        }
        current = current->next;
    }
    if(found == 0){ // Node with given data not found
        printf("Node wasn't found");
    }
}
```

Implementación
```c
    printf("\n\nEnter node data to delete (int number): \n");
    scanf("%d", &num);
    search(list, num);
    traverse(list);
```

### Ejercicio 9 - 

Escribir un programa que lea un archivo con registros formados por un dato entero, un float y una descripción de 30 caracteres.
* Generar una lista ordenada por el dato entero.
* Presentar un menú que permita las siguientes opciones.
    * Agregar un nodo a la lista.
    * Eliminar un nodo de la lista, habiendo sido encontrado.
    * Grabar en un nuevo archivo y salir.

[Solución](./singly_linked_lists/9_menu.c)

### Ejercicio 10 - 

Escribir un programa que lea un archivo con registros formados por un dato entero, un float y una descripción de 30 caracteres.
* Generar una lista con un vector de punteros a estructuras.
* Ordenar la lista utilizando el campo entero.
* Mostrar el contenido de la lista ordenada.
* Grabar en un archivo y finalizar.

