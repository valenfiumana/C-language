# Pointers exercises

## Ejercicio 1 - Entender diferencias
Considere las siguientes instrucciones:
```c
int *p;
int i;
int k;
i = 42;
k = i;
p = &i;
```
Luego de esas instrucciones, ¿cuál de las siguientes cambia el valor de i a 75?
<br>A. k = 75;
<br>B. *k = 75;
<br>C. p = 75;
<br>D. *p = 75;
<br>E. Dos o más de las anteriores.

[Solución](./pointers/1_pointers.c)

## Ejercicio 2 - Detectar error
Explicar qué está mal en el siguiente fragmento de código:

```c
char c = 'A';
double *p = &c;
```
[Solución](./pointers/2_error.c)

## Ejercicio 3 - Invertir vector
Escribir un programa que imprima los elementos de un vector de enteros en orden inverso utilizando punteros (no usar subíndices []).

```c
int v[10] = {1,2,3,4,5,6,7,8,9,10};
int *p;
// Escribir el codigo aca
```

[Solución](./pointers/3_invertir.c)

## Ejercicio 4 - Tamaño e impares vector
Escribir una función que reciba un vector de enteros y su tamaño, y devuelva la cantidad de números impares que contiene.

```c
int impares (int *v, int tam);
```

[Solución](./pointers/4_impares.c)

## Ejercicio 5 - Maximo vector
Escribir una función que devuelva un puntero al máximo valor de un vector de “doubles”. Si el vector está vacío (cant = 0) la función debe retornar NULL.
```c
double* max (double *v, int cant);
```

[Solución](./pointers/5_max.c)


## Ejercicio 6 - Detectar diferencias
Suponga que se ejecutan las siguientes instrucciones:

```c
int a = {5, 15, 34, 54, 14, 2, 52, 72};
int *p = &a [1], *q = &a [5];
```
<br>a. ¿Cuál es el valor de *(p+3)?
<br>b. ¿Cuál es el valor de *(q-3)?
<br>c. ¿Cuál es el valor de q-p?
<br>d. ¿La condición p<q es verdadera o falsa?
<br>e. ¿La condición *p<*q es verdadera o falsa?

[Solución](./pointers/6_punteros.c)


## Ejercicio 7 - Solucionar error
Suponga que primero, ultimo y medio son punteros del mismo tipo y primero y ultimo apuntan al primer y último elemento de un vector. Si quiere que medio apunte al elemento que está en la mitad del vector ¿por qué la siguiente instrucción es inválida y cómo se podría solucionar?

```c
medio = (primero + ultimo) / 2;
```
[Solución](./pointers/7_error.c)

## Ejercicio 8 - Promedio vector
Implemente una función que reciba un vector de números en punto flotante y un entero que representa el tamaño del vector y devuelva el promedio.
Usar notación aritmética de punteros (no subíndices []) para recorrer el vector.

[Solución](./pointers/8_promedio.c)

## Ejercicio 9 - Producto escalar de dos vectores
Implemente la siguiente función para calcular el producto escalar de dos vectores:
```c
double prod_esc (const double *a, const double *b, int n);
```
Donde a y b apuntan a vectores de longitud n.
La función debe retornar:
```c
a[0]*b[0]+a[1]*b[1]+ … + a[n-1]*b[n-1]
```
Usar notación aritmética de punteros (no subíndices []) para recorrer los vectores.

[Solución](./pointers/9_prod_vectorial.c)

## Ejercicio 10 - Diafonal principal y recorrer con punteros
Escriba un programa que permita al usuario ingresar valores enteros en una matriz de 3x3 y luego imprima los elementos de la diagonal principal.
Usar notación aritmética de punteros (no subíndices []) para recorrer la matriz.

[Solución](./pointers/10_diag_principal.c)


## Ejercicio 11 - Elegir opción ( Structs )
Suponga que el puntero p está declarado como sigue:
```c
struct mi_estructura {
    char a, b;
    int c;
    int e [5];
};
struct mi_estructura me;
struct mi_estructura *p = &me;
```
¿Cuáles de las siguientes instrucciones son válidas?
<br>a) p->b = ’ ’;
<br>b) p->e [3] = 10;
<br>c) (*p).a = ’*’;
<br>d) *p.b = ’?’;
<br>e) me.c = 1;
<br>f) p.c = 1;

[Solución](./pointers/11_struct.c)

## Ejercicio 12 - Elegir opción ( Structs )
Suponga que f y p están declarados como sigue:
```c
struct {
    union {
        char a, b;
        int c;
    } d;
    int e [5];
} f, *p = &f;
```
¿Cuáles de las siguientes instrucciones son válidas?
<br>g) p->b = ’ ’;
<br>h) p->e [3] = 10;
<br>i) (*p).d.a = ’*’;
<br>j) p->d->c = ’x’;

[Solución](./pointers/12_structs.c)