/*
1. Escriba una función que permita insertar un nuevo elemento antes del primer nodo de una lista enlazada de enteros.
2. Escribir un programa que cree una lista tipo LIFO (pila) con datos ingresados por el usuario.
Luego mostrar los datos. Liberar la memoria que se reservó al crearla.
3. Escriba una función que devuelva la cantidad de elementos de una lista.
4. Dada una lista enlazada, formada por números enteros, hacer un programa que la divida en dos listas: pares e impares.
5. Escribir una función que inserte un elemento después del último nodo de una lista enlazada.
6. Escribir una función que busque un elemento de la lista, por comparación con una clave e indique si se encuentra o no. Si se encuentra se informará este elemento y también el anterior (en caso de existir).
7. Se tiene una lista ordenada de números enteros y se pide hacer una función que inserte un elemento a la lista, manteniéndola ordenada.
8. Buscar un elemento numérico en una lista y eliminarlo. Considerar que puede ser el primero, último o intermedio.
*/

#include <stdio.h>
#include <stdlib.h>

// Create a node
typedef struct node {
  int data;
  struct node *next;
} node;

// Insert at the beginning (LIFO)
node *insert_lifo (node *l, int d){
    node *newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->data = d; // d == new data
    newNode->next = l; // l == head of node
    return newNode;
}

// Show list
void traverse(node *l) {
    while (l != NULL) {
        printf (" --> %d", l->data);
        l = l->next;
    }
    printf ("\n");
}

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

// Count elements
void length(node *l) {
    int cant = 0;
    while (l != NULL) {
        cant++;
        l = l->next;
    }
    printf ("\nThe list has %d elements\n", cant);
}

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

// Insert at the end
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

// Sort list
void bubbleSort(node *start) {
    int swapped, temp;
    node *ptr1;
    node *lptr = NULL;

    // Check if list is empty
    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // swap data of adjacent nodes
                temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Insert node keeping the list sorted in ascending order
void insert_sorted(node **head, int data) {
    // Allocate memory for new node
    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    // If list is empty or data of first node is greater than data to be inserted
    if (*head == NULL || (*head)->data > data) {
        // Insert new node at the beginning of the list
        new_node->next = *head; //set the next pointer of the new node to point to the old head of the list.
        *head = new_node; // update the head of the list to point to the new node
    }
    else {
        // Find the node before the point of insertion
        node *current = *head; // head node of the list
        // If current has a next node that is not NULL and if the data value in the next node is less than the data value we want to insert
        while (current->next != NULL && current->next->data < data) {
            current = current->next; //current is updated to point to the next node in the list
        }
        // Insert new node at the correct position
        new_node->next = current->next; //setting the next pointer of the new node to point to the node that is currently at the correct position (which is the node after current).
        current->next = new_node; // update the next pointer of current to point to the new node, so that the new node becomes the next node after current
    }
}

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

int main()
{
    node *list = NULL, *evenList = NULL, *oddList = NULL;
    int num;

    // 2. Create LIFO list with numbers entered by user
    printf("Enter int numbers and end with 0: \n");
    scanf("%d", &num);

    while(num != 0){
        list = insert_lifo(list, num);
        scanf("%d", &num);
    }
    printf("\n\nList created by user: \n");
    traverse(list);

    // 1. Insert element before first node
    list = insert_lifo(list, 11);
    printf("\n\nList with new element (11) in the beginning: \n");
    traverse(list);


    // 3. List length
    length(list);


    // 4. Even or odd
    separateEvenOdd(list, &evenList, &oddList);
    printf("\nEven list: ");
    traverse(evenList);
    printf("Odd list: ");
    traverse(oddList);


    //5. Insert element after last node
    insert_fifo(list, 100);
    printf("\n\nList with new element (100) in the end: \n");
    traverse(list);

    // 6. Find element and print previous one
    printf("\n\nEnter int number to search: \n");
    scanf("%d", &num);
    searchAndPrev(list, num);

    // 7. Sort list and add element
    bubbleSort(list);
    printf("\n\nSorted list: \n");
    traverse(list);

    printf("\n\nEnter int number to add: \n");
    scanf("%d", &num);
    insert_sorted(&list, num);
    printf("\nList with number added: \n");
    traverse(list);

    // 8. Find node and delete it
    printf("\n\nEnter node data to delete (int number): \n");
    scanf("%d", &num);
    search(list, num);
    traverse(list);

    destroy(list);

    return 0;
}
