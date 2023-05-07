# Exercises: Doubly Linked Lists

## Ejercicio 1
Escribir funciones que inserten un elemento numérico en una lista doblemente enlazada:
* Al principio de la lista (insertar_lifo)
* Al final de la lista (insertar_fifo)
* En un lugar intermedio (insertar_antes & insertar_despues).
Extras:
* Mostrar lista (display)
* Destruir lista (destroy)

[Solución](./doubly_linked_lists/1_funciones.c)

## Ejercicio 2
Escribir un programa que genere una lista doble y ordenada. Generar un listado en pantalla de la misma comenzando desde cada extremo.

[Solución](./doubly_linked_lists/2_listaOrdenada.c)

## Ejercicio 3
Para una lista doblemente enlazada, escribir una función para localizar un elemento:
* Si se lo encuentra mostrar su contenido y devolver 1.
* Si no se encuentra devolver 0.

[Solución](./doubly_linked_lists/3_buscarElemento.c)

## Ejercicio 4
El Instituto de Nanosistemas (INS), creado por la Universidad Nacional de San Martín en 2014, es un espacio de investigación científica en el campo de la nanotecnología. Dado que trabaja con productos químicos, para soportar su sistema de información se le a usted pide escribir un programa que implemente un menú cíclico con las siguientes opciones:
1. Leer un archivo binario con registros que tienen la siguiente estructura
    * Código de producto: entero de 16 bits
    * Nombre del producto: cadena de hasta 20 caracteres
    * Precio por unidad de masa: flotante simple precisión
    * Stock en gramos: flotante doble precisión
Los datos se deben agregar al final de una lista doblemente enlazada manteniendo el orden del archivo (lista maestra)
2. Agregar un producto ingresado por teclado a final de la lista maestra
3. Eliminar un elemento de la lista maestra dado su código
4.  Generar una versión ordenada de lista, pudiendo ser el orden por cualquiera de los 4 campos según la elección del usuario
5. Mostrar la lista dando la opción de hacerlo con la maestra / ordenada en sentido directo / inverso
6. Sobrescribir en archivo con los datos de la lista maestra
7. Informar si en la lista maestra hay productos con nombre duplicado y en caso afirmativo informar los códigos de al menos el primer caso de duplicación encontrado (si lo necesita puede hacer uso de la lista ordenada)
8. Salir

Las opciones del menú deben poder usarse en cualquier orden y número de veces

[Solución](./doubly_linked_lists/4_menu.c)