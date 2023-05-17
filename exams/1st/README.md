# Tests

## Simulacro examen
En particular, lo que necesita es un programa que le permita, mediante un menú repetitivo de opciones, hacer lo siguiente:
1. Cargar los 10 nombres de productos (char 20) y su precios unitarios (float), contenidos en el archivo "precioproductos.dat".
    * Aclaración: Usted deberá cargarlos en una estructura de datos apropiada, la que usted crea conveniente.
    * Aclaración sobre el archivo: Los datos se guardaron en el archivo en el orden mencionado: producto: char [20], precio: float.
2. Permitir cargar un nuevo pedido a la lista de pedidos, por orden de llegada, con los siguientes datos:
    * numpedido (valor entero)
    * numcombo (valor entero, del 1 al 10) -> los números del 1 al 10 identificarán los distintos tipos de pizzas.
    * cantidad (valor entero)
    * totalapagar (valor decimal, calculado a partir de los precios que tendrá la lista o vector de productos/precios)

3. Mostrar:
    * Los nombres (char 20) de los 10 tipos de pizzas que ofrecen para la venta y su precio unitario (float).
    * Mostrar la lista de pedidos en curso: numpedido, numcombo, cantidad, totalapagar.

4. Permitir ingresar por teclado el nombre de un producto y de encontrarse, permitir actualizar su precio en el vector de productos/precios.

5. Recalcular el valor del dato totalapagar de cada pedido que haya en la lista, buscando el nuevo precio cargado luego de ejecutar la opción del punto 4.

6. Salir del programa.

[Solución mía](./simulacro.c)

[Solución profesor](./simulacroProfesor.c)

Para generar el archivo (10 struct) : 
* [Guardando los 10 juntos](./files/crearArchivos/precioproductos-carga10.c)

* [Guardando 1 por vez](./files/crearArchivos/precioproductos-cargaUnidad.c)

## 30 de junio de 2018

Sugerencia: lea atentamente todos los puntos antes de empezar a escribir.
Se tiene el archivo [procesadores.dat](./files/procesadores.dat) conformado por registros cuya estructura es la siguiente:
* Nombre: texto (menos de 40 caracteres)
* Velocidad en MHz: Entero (entre 1 y 6000)
* Precio: Real (con 2 decimales)

Se pide hacer un programa que realice las siguientes tareas:

1. Leer el archivo conformando una lista simplemente enlazada.
2. Presentar un menú con las siguientes opciones:
    * Eliminar el primer procesador encontrado que tenga una velocidad menor a un
umbral ingresado por teclado. ~
    * Mostrar los nombres de todos los procesadores en orden inverso al que se
encontraban en el archivo.
    * Fin del menú.

[Solución](./procesadores(30-06-2018).c)

Para generar el archivo (varios struct, cantidad indeterminada) : 
[Generar archivo procesadores.dat](./files/crearArchivos/procesadores.c)

## Examen
En un laboratorio nuclear se tiene el archivo [muestras.dat](./files/muestras.dat) conformado por una cantidad indeterminada de números enteros. Estos números están en el rango entre 102 y 107 y representan el tiempo en segundos que tarda en desintegrarse una muestra.
No puede limitar la cantidad de números.
Se pide hacer un programa que realice las siguientes tareas:
* Leer el archivo conformando una lista simple. Los nodos de la lista deben quedar en el mismo orden que en el archivo del que fueron leídos.
* Presentar un menú con las siguientes opciones:
    1. Agregar un nuevo elemento al principio de la lista.
    2. Eliminar el primer elemento que coincida con un valor ingresado por teclado.
    3. Informar el tiempo de desintegración más bajo de la lista.
    4. Mostrar todos los tiempos de desintegración que son mayores a un valor ingresado por teclado e informar cuántos fueron.
    5. Fin del menú.


[Solución](./laboratorio.c)

Para generar el archivo (numeros random del 102 al 107) :
[Generar archivo muestras.dat](./files/crearArchivos/muestras.c)