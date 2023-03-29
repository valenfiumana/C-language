# Exercises: Struct & Union

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
