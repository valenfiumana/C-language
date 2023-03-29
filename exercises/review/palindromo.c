/*Este programa permite ingresar una palabra por teclado e invierte el orden de sus letras.
Luego muestra la palabra original e invertida y el resultado de compararlas alfabeticamente.
Sirve para verificar si una palabra es palindromo (ej. anana, aviva, ojo, reconocer)*/

#include <stdio.h>
#include <string.h>
int main()
	{
	char palabra[200], invertida[200];
	int i, tam, comp;

	printf("Ingrese una palabra y la mostrare invertida:\n");
	scanf("%s", palabra);

   //Hago una copia de la palabra para demostrar el uso de strcpy
   //y para copiar el fin de cadena
   strcpy (invertida, palabra);

   //Invierto las letras de la cadena "invertida"
	tam = strlen(palabra);
	for(i = 0; i < tam; i++)
		{
		invertida [i] = palabra[tam - 1 - i];
		}

   //Muestro ambas cadenas y su tamanio
	printf("Cadena original: %s\n", palabra);
	printf("Cadena invertida: %s\n", invertida);
	printf("Tamanio de ambas: %d\n", tam);

   //Comparo ambas cadenas alfabeticamente
	comp = strcmp(palabra, invertida);
	if (comp < 0)
		{
		printf ("La palabra original va ANTES en el diccionario\n");
		}
	else if (comp > 0)
		{
		printf ("La palabra original va DESPUES en el diccionario\n");
		}
	else
		{
		printf ("FELICIDADES !!! es un palindromo o capicua\n");
		}

	return 0;
	}
