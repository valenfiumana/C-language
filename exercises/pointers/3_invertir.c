//Escribir un programa que imprima los elementos de un vector de enteros
//en orden inverso utilizando punteros (no usar subindices []).

#include <stdio.h>

int main(){
	int v [10] = {1,2,3,4,5,6,7,8,9,10};
	int i;

	for (i = 9; i >= 0 ; i--){
        printf ("Elemento %d = %d\n", i, *(v + i));
    }

	return 0;
}

//Otra forma de hacerlo
/*
int main()
	{
	int v [10] = {1,2,3,4,5,6,7,8,9,10};
	int *p;
	int i;

	p = v + 9; // &v[9]

	for (i = 0; i < 10 ; i++){
        printf ("Elemento %d: %d\n", 9 - i, *p);
		p--;
    }

	return 0;
	}
*/
