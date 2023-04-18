# Dynamic Memory Exercises

## Ejemplos

### Casting
[Ejemplo](./dynamic_memory/casting.c)

### Uso de malloc
Ejemplo simple de memoria dinámica

[Ejemplo](./dynamic_memory/ejemplo_malloc.c)

### Stack vs Heap

[Ejemplo](./dynamic_memory/stackVsHeap.c)
### Carga de productos (struct)
Se pide la carga de datos de productos finalizando cuando nombre="*" y se reserva memoria a medida que se ingresa un nuevo producto. Luego graba lo ingresado en un archivo, lo cierrra, lo lee y calcula el promedio 
de aquellos cuyo nombre empieza con "c".

[Ejemplo](./dynamic_memory/ejemplo_realloc_struct_archivo.c)

## Ejercicios
### Ejercicio 1 - Almacenar elementos

Escribir un programa en el que el usuario informa la cantidad de elementos que va a ingresar y luego los valores de los elementos (enteros).
Los elementos deben almacenarse en un vector y luego en el archivo vector.dat. No se debe limitar la cantidad de elementos.

[Solución](./dynamic_memory/1_almacenar.c)



### Ejercicio 2 - Leer archivo

Escribir un programa para leer el archivo vector.dat del ejercicio anterior y almacenarlo en un vector. No se conoce la cantidad de elementos y no se puede limitar.

[Solución](./dynamic_memory/2_leer.c)



### Ejercicio 3 - duplicar String

Escriba la función duplicar que reserve memoria dinámicamente para duplicar un string que se le pasa como argumento. Por ejemplo, la llamada: p = duplicar (str);
debe reservar memoria para un string de la misma longitud que str, copiar los datos y retornar un puntero a la nueva cadena de caracteres. Si la reserva de memoria falla, entonces duplicar debe retornar un puntero nulo.

[Solución](./dynamic_memory/3_duplicarString.c)



### Ejercicio 4 - puntero a vector

```c
int *crear_vector (int n, int valor_inicial);
```

La función debe retornar un puntero a un vector de enteros de tamaño n creado
dinámicamente cuyas posiciones son inicializadas con valor_inicial. La
función debe retornar NULL si no se puede reservar la memoria.


[Solución](./dynamic_memory/4_punteroAVector.c)



### Ejercicio 5 - struct

```c
struct punto {
int x;
int y;
};
struct rectangulo {
struct punto superior_izq;
struct punto inferior_der;
};
struct rectangulo *p;
```
Escriba las líneas necesarias para que p apunte a una estructura rectangulo
válida que tenga (10,25) como esquina superior izquierda y (20,15) como esquina
inferior derecha.

[Solución](./dynamic_memory/5_struct.c)



### Ejercicio 6 - memset() y memcpy()

Investigue y explique el uso de las funciones memset () y memcpy ().

#### Solución: