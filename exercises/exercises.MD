# Exercises
# Strings, Struct & Union

## Reviewing concepts
1. Escribir un programa que ofrece el siguiente menu en forma ciclica hasta salir:
<br>a.  Leer una matriz de enteros de 5x5 desde el archivo matrix.dat
<br>b. Grabar la matriz al archivo matrix.dat
<br>c. Inicializar la matriz de forma tal que m(i,j) se vea ij, es decir: 11, 12, 13, 14, 15, 21, 22, ... , 55
<br>d. Ingresar el valor de un elemento por teclado
<br>e. Generar vector con la suma de cada columna
<br>f. Mostrar la matriz y el vector
<br>g. Salir
Usar al menos una funcion por cada opcion del menu (menos la 7)

</br>

[Solución](./review/parcial2020.c)

## Strings
### 1. Array of Strings
Leer un string por teclado:
</br>1)  y convertirlo a mayúsculas sin usar las funciones de string.h
</br>2) y mostrarlo en orden inverso sin usar las funciones de string.h
</br> </br>
Leer 5 strings por teclado:
</br>3. y mostrar el “mayor” (alfabéticamente)
</br>4. y mostrar el de mayor longitud
</br>5. y almacenarlos en un archivo.
</br>6. Leer los strings del archivo del ej. anterior y mostrarlos en pantalla.
</br>
</br>
[Solución](./review/strings.c)

</br>
### 2. Palindrome
Hacer un programa que permita ingresar una palabra por teclado e invertir el orden de sus letras. Luego mostrar la palabra original e invertida y el resultado de compararlas alfabeticamente.
Sirve para verificar si una palabra es palindromo (ej. anana, aviva, ojo, reconocer)
</br>
[Solución](./review/palindromo.c)

## Structs
### 1. Array of structs - writing file
Leer por teclado los detalles (legajo, nombre, promedio) de n estudiantes (n < 100) y almacenarlo en el archivo estudiantes.dat.
</br>
[Solución](./struct/estudiantes.c)

### 2. Reading array of structs - average
Leer el archivo estudiantes.dat y mostrar el estudiante con el mayor promedio.
</br>
[Solución](./struct/estudiantes.c)

### 3. Euclidean distance
Escribir una función que reciba las coordenadas cartesianas de 2 puntos en el espacio y devuelva la distancia euclídea.
</br>
[Solución](./struct/distancia2puntos.c)

### 4. Time difference
Escribir una función que reciba 2 horas h1 y h2 (hora, minutos y segundos) y devuelva la diferencia entre ambas (en horas, minutos y segundos). Se sabe que h2 es posterior a h1.
</br>
[Solución](./struct/horas.c)

## Unions
### 5. DNI vs Passport 
El programa permite ingresar apellido, tipo y nro de documento de una persona, usando el tipo de datos adecuado para el nro segun el tipo de documento 
</br>
[Solución](./struct/dni.c)


### 7. Variables
Definir un tipo de dato que tenga dos campos: tipo (1, 2, o 3) y un segundo campo para el valor. El valor dependiendo del tipo debe permitir almacenar un int, un float o un double pero sólo uno simultáneamente.
</br>
[Solución](./struct/union.c)
