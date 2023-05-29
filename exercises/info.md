# Numeral systems

### 1. ¿Qué es la base de un sistema de numeración?

La base de un sistema de numeración es el número de símbolos distintos que se utilizan en ese sistema. Por ejemplo, en el sistema decimal (base 10) se utilizan los símbolos del 0 al 9, mientras que en el sistema binario (base 2) se utilizan los símbolos 0 y 1.

### 2.  ¿Cuáles son los 4 sistemas de numeración más utilizados en informática?

* Decimal (base 10)
* Binario (base 2)
* Hexadecimal (base 16)
* Octal (base 8)

### 3. ¿Con cuál de los sistemas de numeración cree que necesitará más dígitos para representar un valor dado? ¿Con cuál menos? ¿Por qué?

El sistema de numeración que requerirá más dígitos para representar un valor dado sería el sistema binario (base 2), ya que solo utiliza los símbolos 0 y 1. 

Por otro lado, el sistema decimal (base 10) requerirá menos dígitos para representar el mismo valor, ya que utiliza los símbolos del 0 al 9. 

A mayor cantidad de dígitos, más fácil representación de un valor dado.

### 4. ¿Cuáles son las ventajas y desventajas de los sistemas de numeración que mencionó? En otras palabras, ¿por qué se usan? 

* Decimal (base 10):
    * Ventajas: El más utilizado y fácil de entender para los seres humanos. Permite representar una amplia gama de valores numéricos convencionales.
    * Desventajas: Requiere más dígitos para representar un mismo valor en comparación con otros sistemas de numeración. No es eficiente para la representación interna de información en las computadoras.
* Binario (base 2):
    * Ventajas: Es el sistema fundamental en los sistemas digitales y en la representación interna de información en las computadoras. Es eficiente para realizar operaciones lógicas y aritméticas en circuitos digitales.
    * Desventajas: Requiere más dígitos para representar los mismos valores en comparación con el sistema decimal. La lectura y comprensión de números binarios puede resultar más compleja para los seres humanos.
* Hexadecimal (base 16):
    * Ventajas: Permite representar grandes valores con una cantidad reducida de dígitos, lo que lo hace útil en la programación y representación de direcciones de memoria. Facilita la conversión entre valores binarios y simplifica la visualización y manipulación de información en hexadecimal.
    * Desventajas: Puede resultar menos intuitivo para los seres humanos en comparación con el sistema decimal.
* Octal (base 8):
    * Ventajas: Es una base intermedia entre el sistema binario y el sistema decimal. Tiene una relación directa con la representación binaria y se utiliza ocasionalmente en sistemas antiguos o específicos.
    * Desventajas: Requiere más dígitos que el sistema hexadecimal para representar los mismos valores. Su uso es menos común en comparación con otros sistemas de numeración.

### 5. Generar una tabla de equivalencias...
...entre los primeros 100 valores de los sistemas de numeración vistos en clase: decimal, binario, hexadecimal, BCD.

| Decimal | Binario   | Hexadecimal | BCD      |
|---------|-----------|-------------|----------|
| 0       | 00000000  | 00          | 0000     |
| 1       | 00000001  | 01          | 0001     |
| 2       | 00000010  | 02          | 0010     |
| 3       | 00000011  | 03          | 0011     |
| 4       | 00000100  | 04          | 0100     |
| 5       | 00000101  | 05          | 0101     |
| 6       | 00000110  | 06          | 0110     |
| 7       | 00000111  | 07          | 0111     |
| 8       | 00001000  | 08          | 1000     |
| 9       | 00001001  | 09          | 1001     |
| 10      | 00001010  | 0A          | 0001 0000|
| 11      | 00001011  | 0B          | 0001 0001|
| 12      | 00001100  | 0C          | 0001 0010|
| 13      | 00001101  | 0D          | 0001 0011|
| 14      | 00001110  | 0E          | 0001 0100|
| 15      | 00001111  | 0F          | 0001 0101|
| 16      | 00010000  | 10          | 0001 0110|
| 17      | 00010001  | 11          | 0001 0111|
| 18      | 00010010  | 12          | 0001 1000|
| 19      | 00010011  | 13          | 0001 1001|
| 20      | 00010100  | 14          | 0010 0000|
| 21      | 00010101  | 15          | 0010 0001|
| 22      | 00010110  | 16          | 0010 0010|
| 23      | 00010111  | 17          | 0010 0011|
| 24      | 00011000  | 18          | 0010 0100|
| 25      | 00011001  | 19          | 0010 0101|
| 26      | 00011010  | 1A          | 0010 1000|
| 27      | 00011011  | 1B          | 0010 1001|
| 28      | 00011100  | 1C          | 0011 0000|
| 29      | 00011101  | 1D          | 0011 0001|
| 30      | 00011110  | 1E          | 0011 0010|
| 31      | 00011111  | 1F          | 0011 0011|
| 32      | 00100000  | 20          | 0011 0100|
...
``


### 6. ¿Cuántas magnitudes distintas se pueden representar con…?
* Con **8 bits sin tener en cuenta el signo**, se pueden representar 2^8 = 256 magnitudes distintas.

* Con **32 bits sin tener en cuenta el signo**, se pueden representar 2^32 = 4,294,967,296 magnitudes distintas.

* Con **8 bits teniendo en cuenta el signo**, se pueden representar 2^7 = 128 magnitudes distintas (considerando el bit más significativo como el bit de signo, lo que permite representar valores negativos y positivos).

* Con **32 bits teniendo en cuenta el signo**, se pueden representar 2^31 = 2,147,483,648 magnitudes distintas (considerando el bit más significativo como el bit de signo).

* Con **N bits sin almacenar signo**, se pueden representar 2^N magnitudes distintas.

* Con **2 dígitos hexadecimales sin tener en cuenta el signo**, se pueden representar 16^2 = 256 magnitudes distintas.

* Con **8 dígitos hexadecimales sin tener en cuenta el signo**, se pueden representar 16^8 = 4,294,967,296 magnitudes distintas.

* Con N dígitos hexadecimales sin signo, se pueden representar 16^N magnitudes distintas.

* Con 8 bits usando codificación BCD (sin signo), se pueden representar 10^8 = 100,000,000 magnitudes distintas (cada grupo de 4 bits representa un dígito decimal en BCD, y se pueden tener hasta 8 dígitos decimales).

### 7. ¿Cuál es el valor más grande que se puede representar con N bits si...?
a. Si **no se tiene en cuenta el signo**, el valor más grande que se puede representar con N bits es 2^N - 1.

b. Si **se tiene en cuenta el signo**, el valor más grande que se puede representar con N bits es 2^(N-1) - 1. Esto se debe a que el bit más significativo se utiliza como el bit de signo, por lo que queda un bit menos para representar los valores.

c. Si **N es múltiplo de 4, no se usa signo pero se usa codificación BCD**, el valor más grande que se puede representar depende de la cantidad de dígitos BCD que se pueden representar con N bits. Para cada dígito BCD se necesitan 4 bits. Entonces, el número máximo de dígitos BCD que se pueden representar con N bits será N/4. Por lo tanto, el valor más grande que se puede representar será el número máximo de dígitos BCD multiplicado por 9 (que es el valor máximo de un dígito BCD).

### 8.
* ¿Qué significa la palabra unsigned en lenguaje C?

En lenguaje C, la palabra "unsigned" se utiliza para indicar que un tipo de dato no incluye signo, es decir, solo puede representar valores no negativos.

* ¿Cómo se usa?

La palabra "unsigned" como un modificador de tipo de dato. Se coloca antes del tipo de dato para indicar que el rango de valores del tipo de dato no incluye números negativos.

* ¿A qué tipo de datos se puede aplicar? Provea 4 ejemplos.

    * signed int: Entero sin signo.
    * unsigned char: Carácter sin signo.
    * unsigned short: Entero corto sin signo.
    * unsigned long: Entero largo sin signo.
  
<br>

* ¿Modifica el tamaño que ocupa el tipo de datos?

Sí, el uso del modificador "unsigned" puede afectar el tamaño que ocupa el tipo de dato en memoria. 

Por ejemplo, un "int" generalmente ocupa 4 bytes en la mayoría de las plataformas, mientras que el tipo de dato "unsigned int" también ocupa 4 bytes. Sin embargo, el rango de valores que se puede representar en cada tipo de dato es diferente. Al eliminar la necesidad de representar números negativos, el modificador "unsigned" permite que el tipo de dato almacene valores no negativos más grandes, a costa de no poder representar números negativos.

### 9. Escribir un programa en lenguaje C que permita Ingresar por teclado un
valor…
a. en decimal, sin signo, de 8 bits, y lo muestre en hexadecimal
b. en hexadecimal, sin signo, de 8 bits, y lo muestre en decimal

[Solución](./info/hexaToDec.c)

### 10. Escribir un programa en lenguaje C que, haciendo uso de una función...
...que recibe como argumento un valor entero de 8 bits sin signo (unsigned char), lo convierta a binario y luego lo muestre en pantalla. El número binario impreso en pantalla deberá mostrarse siempre con una longitud de 8 caracteres.

[Solución](./info/decToBin.c)

# Ejercicios de operaciones lógicas a nivel bit

### 11. Explique el significado de los siguientes operadores en lenguaje C (en el contexto de operaciones a nivel bit): &, |, ~

* Operador & (AND a nivel de bits): realiza una operación AND a nivel de bits entre los operandos. Cada bit en el resultado será 1 solo si ambos bits correspondientes en los operandos son 1; de lo contrario, el bit resultante será 0.

```c
unsigned int a = 12;  // 1100 en binario
unsigned int b = 6;   // 0110 en binario
unsigned int result = a & b;  // Resultado: 0100 en binario (4 en decimal)
```
* Operador | (OR a nivel de bits): realiza una operación OR a nivel de bits entre los operandos. Cada bit en el resultado será 1 si al menos uno de los bits correspondientes en los operandos es 1; de lo contrario, el bit resultante será 0.

```c
unsigned int a = 12;  // 1100 en binario
unsigned int b = 6;   // 0110 en binario
unsigned int result = a | b;  // Resultado: 1110 en binario (14 en decimal)
```

* Operador ~ (NOT a nivel de bits): realiza una operación NOT (complemento) a nivel de bits en el operando. Invierte cada bit en el operando; si el bit original es 0, se convierte en 1, y si el bit original es 1, se convierte en 0.

```c
unsigned int a = 12;  // 1100 en binario
unsigned int result = ~a;  // Resultado: 0011 en binario (3 en decimal)
```

### 12. Escriba un programa que permita ingresar un valor entero de 8 bits sin signo y haga lo siguiente (empezando a contar los bits desde la derecha):
a. Muestre el nro. ingresado en hexadecimal
b. Informe si el 5to bit es cero o uno
c. Informe si el primero y el cuarto bit están en uno
d. Informe si el primero o el cuarto bit están en uno
e. Modifique el nro. poniendo en uno los bits de los extremos
f. Modifique el nro. poniendo en cero los bits de los extremos
g. Niegue el nro. (ejemplo: 00110010 -> 11001101)
h. (opcional) Niegue sólo los 4 bits menos significativos (ejemplo:
00110010 -> 00111101)

### 13. Escriba una función que reciba un valor entero de 8 bits sin signo e informe si representa o no un BCD válido (ejemplo: los bits 11111111 no representan un BCD válido)

# Ejercicios de arquitecturas de hardware

### 14. ¿Cuál es la diferencia entre hardware y software?

La diferencia entre hardware y software radica en que el hardware se refiere a los componentes físicos y tangibles de una computadora o sistema informático (ej.CPU, memoria, disco duro, teclado, monitor).

Mientras tanto, el software se refiere a los programas, datos y las instrucciones que se ejecutan en el hardware para realizar tareas específicas. El software es intangible y consiste en código de programación, sistemas operativos, aplicaciones y otros programas.

### 15. ¿Qué es un dispositivo periférico?

Un dispositivo periférico es un componente o dispositivo externo conectado a una computadora o sistema informático para proporcionar funciones adicionales o realizar tareas específicas. Estos dispositivos se utilizan para interactuar con la computadora y suelen ser opcionales. 

Algunos ejemplos comunes de dispositivos periféricos son el teclado, el mouse, la impresora, el escáner, los altavoces, el monitor, el disco duro externo, etc.

### 16. ¿Cuál es la característica fundamental de la arquitectura de Von Neumann?

La característica fundamental de la arquitectura de Von Neumann es la separación entre la unidad de procesamiento (CPU), la memoria y las unidades de entrada/salida. En este tipo de arquitectura, los programas y los datos se almacenan en la misma memoria y se accede a ellos de forma secuencial. Además, las instrucciones y los datos se representan en forma de números binarios y se manipulan mediante operaciones aritméticas y lógicas.

### 17. ¿Qué es un bus y por qué se utiliza?

Un bus es un conjunto de líneas de comunicación que permiten la transferencia de datos y señales entre los diferentes componentes de una computadora o sistema informático. Se utiliza para establecer la comunicación y la transferencia de información entre la CPU, la memoria y los dispositivos periféricos.

### 18. ¿Cuáles son los buses que utiliza la arquitectura de Von Neumann?

En la arquitectura de Von Neumann, se utilizan varios buses, incluyendo:

* **Bus de datos**: Permite la transferencia de datos entre la CPU, la memoria y los dispositivos de entrada/salida. Se utiliza para transmitir los datos que se están procesando.
* **Bus de direcciones**: Se utiliza para transmitir la dirección de memoria de una ubicación específica donde se encuentra la instrucción o el dato que se va a leer o escribir.
* **Bus de control**: Es responsable de coordinar y controlar las operaciones de lectura, escritura y ejecución de instrucciones en la CPU y la memoria. Proporciona las señales de control necesarias para sincronizar y regular el funcionamiento de los diferentes componentes del sistema.

### 19.
* ¿Qué es el período T de una señal y en qué unidades se mide?

El período T de una señal es el tiempo que tarda en completar un ciclo completo, es decir, el tiempo que se tarda en repetir exactamente la misma forma de onda. Se mide en segundos (s) o en sus múltiplos, como milisegundos (ms) o nanosegundos (ns).

* ¿Qué es la frecuencia f de una señal y en qué unidades se mide?

La frecuencia f de una señal es la cantidad de ciclos completos que ocurren por unidad de tiempo. Indica la rapidez con la que se repite la señal. Se mide en Hertz (Hz), que representa la cantidad de ciclos por segundo.

* ¿Qué relación matemática existe entre f y T y qué significa?

La relación matemática entre la frecuencia f y el período T de una señal es: f = 1 / T. Esto significa que la frecuencia es el inverso del período, y viceversa. Si conocemos la frecuencia de una señal, podemos calcular su período dividiendo 1 entre la frecuencia, y si conocemos el período, podemos calcular la frecuencia dividiendo 1 entre el período.

* ¿Cuál es la frecuencia de una señal que tiene 2ns de período?

Si una señal tiene un período de 2 ns, podemos calcular su frecuencia utilizando la relación f = 1 / T. En este caso, f = 1 / (2 ns) = 0.5 GHz (gigahertz), ya que 1 GHz representa mil millones de ciclos por segundo.

### 20. ¿Qué es el clock de un sistema digital y para qué sirve?

El clock de un sistema digital es una señal de temporización periódica que sincroniza las operaciones de los componentes del sistema. Es un pulso o una onda cuadrada que se utiliza para controlar y coordinar el flujo de información y las operaciones dentro del sistema. El clock establece el ritmo de trabajo de los componentes del sistema, asegurando que las operaciones se realicen de manera ordenada y sincronizada.

### 21. ¿Para qué sirve el procesador o CPU?

El procesador o CPU (Unidad Central de Procesamiento) es el componente principal de una computadora o sistema informático. Es responsable de ejecutar las instrucciones de los programas y realizar las operaciones de procesamiento de datos. El CPU es el cerebro de la computadora y se encarga de realizar cálculos, tomar decisiones y controlar el funcionamiento del sistema.

### 22. ¿Cuáles son los tres componentes principales de un procesador y para qué sirve cada uno?

* **Unidad de Control (Control Unit)**: Es responsable de coordinar y controlar las operaciones del procesador. Controla la secuencia de ejecución de las instrucciones, decodifica las instrucciones y genera las señales de control necesarias para manejar las operaciones del procesador.

* **Unidad Aritmético-Lógica (ALU)**: Es el componente encargado de realizar operaciones aritméticas (como sumas y restas) y operaciones lógicas (como AND, OR, NOT) en los datos. Realiza las operaciones requeridas por las instrucciones y produce los resultados.

* **Registros**: Son elementos de almacenamiento de alta velocidad que se utilizan para guardar y manipular datos temporalmente durante las operaciones del procesador. Los registros son utilizados por la Unidad de Control y la ALU para almacenar datos, direcciones de memoria, resultados intermedios y otros valores necesarios para el procesamiento de instrucciones.

### 23. ¿Qué es la RAM y qué significa que es de acceso aleatorio?

La RAM (Random Access Memory) es una forma de memoria de computadora que se utiliza para almacenar datos y programas de forma temporal. Es de acceso aleatorio, lo que significa que se puede acceder a cualquier ubicación de memoria de manera directa y rápida, sin tener que seguir una secuencia específica. La RAM permite leer, escribir y borrar datos de forma rápida y eficiente, y es una parte fundamental de la memoria principal de un sistema informático.

### 24. ¿Qué es el tamaño de palabra de un procesador?

El tamaño de palabra de un procesador se refiere al número de bits que puede procesar en una operación o instrucción. Representa la cantidad de datos que el procesador puede manipular en paralelo. Por ejemplo, un procesador de 32 bits puede procesar datos de 32 bits en una sola operación, mientras que un procesador de 64 bits puede procesar datos de 64 bits en una sola operación. El tamaño de palabra influye en la capacidad de cálculo y procesamiento del procesador, así como en la cantidad de memoria que puede direccionar.

### 25. En el contexto de hardware: ¿Qué es un núcleo?

En el contexto de hardware, un núcleo se refiere a una unidad de procesamiento independiente dentro de un procesador. Un procesador puede tener uno o varios núcleos, y cada núcleo es capaz de ejecutar instrucciones y realizar cálculos de forma independiente. Cada núcleo puede manejar su propia secuencia de instrucciones y trabajar en paralelo con otros núcleos para aumentar la capacidad de procesamiento del procesador. Los procesadores con múltiples núcleos ofrecen un mejor rendimiento en tareas que pueden ejecutarse de forma simultánea y paralela.