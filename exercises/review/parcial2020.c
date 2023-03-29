/*
Escribir un programa que ofrece el siguiente menu en forma ciclica hasta salir:
1. Leer una matriz de enteros de 5x5 desde el archivo matrix.dat
2. Grabar la matriz al archivo matrix.dat
3. Inicializar la matriz de forma tal que m(i,j) se vea ij, es decir: 11, 12, 13, 14, 15, 21, 22, ... , 55
4. Ingresar el valor de un elemento por teclado
5. Generar vector con la suma de cada columna
6. Mostrar la matriz y el vector
7. Salir
Usar al menos una funcion por cada opcion del menu (menos la 7)
*/

#include <stdio.h>
#include <stdlib.h>
#define F 5
#define C 5

int imprime_menu (void) {
   int op;
   printf ("\n1. Leer matriz desde archivo");
   printf ("\n2. Grabar matriz al archivo");
   printf ("\n3. Inicializar matriz");
   printf ("\n4. Ingresar elemento");
   printf ("\n5. Generar vector");
   printf ("\n6. Mostrar todo");
   printf ("\n7. Salir");
   printf ("\nOpcion:");
   scanf ("%d", &op);
   return op;
}

// LEER MATRIZ DE ARCHIVO
void leerMatriz (int m [F][C]) {
    int c;
    FILE *fp=fopen("matriz.dat", "r");
    if(fp == NULL) {
        perror("Error al abrir\n");
        exit(3);
    }
    else{
        c = fread (m, sizeof m[0][0], F*C, fp);
        if(c != F*C){
            perror("Error al leer\n");
            fclose(fp);
            exit(1);
        }
        if(fclose(fp) != 0){
            perror("Error al cerrar\n");
            exit(2);
        }
    }
}

// GRABAR MATRIZ EN ARCHIVO
void grabarMatriz (int m [F][C]) {
    int c;
    FILE * fp = fopen("matriz.dat", "w");
    if(fp == NULL) {
        perror("Error al abrir");
    }
    else{
        c = fwrite (m, sizeof m[0][0], F*C, fp);
        if(c != F*C){
            printf("Error al grabar\n");
            fclose(fp);
            exit(4);
        }
        if( fclose(fp) != 0){
            printf("Error al cerrar\n");
            exit(5);
        }
    }
}

// LLENAR MATRIZ CON CONDICION
//LLena la matriz con los valores 11, 12, 13, 14, 15, 21, 22, ... , 55
void llenarMatriz(int m [F][C]) {
   int i, j;
   for (i = 0; i < F; i++)
      for (j = 0; j < C; j++)
         m [i][j] = 10 * (i + 1) + (j + 1);
}

// CAMBIAR VALOR DE UNA POSICION (USUARIO)
void lee_elem (int m [F][C]) {
   int f,c;

   printf ("\nFila:");
   scanf ("%d", &f);
   printf ("Col:");
   scanf ("%d", &c);
   printf ("Valor:");
   scanf ("%d", &m [f][c]);
}

// VECTOR CON SUMA DE CADA COLUMNA
void vectorSumaColMatriz (int m [F][C], int v []) {
   for (int i = 0; i < C; i++) {
      v [i] = 0;
      for (int j = 0; j < F; j++) {
         v [i] += m [i][j];
      }
   }
}

// MOSTRAR MATRIZ
void mostrarMatriz(int M[F][C]){
    for(int i=0; i<F; i++){
        printf("\n\t");
        for(int j=0; j<C; j++){
            printf(" %d \t", M[i][j]);
        }
        printf("\n");
    }
}

// MOSTRAR VECTOR
void mostrarVector(int V[]){
    printf("[ ");
    for(int i=0; i<C; i++){
        printf("%d  ", V[i]);
    }
    printf("]");
}

/* Programa principal */
int main() {
   int M[F][C], V[C], op;

   do {
      op = imprime_menu();
      switch (op) {
         case 1:
            leerMatriz(M);
            break;
         case 2:
            grabarMatriz(M);
            break;
         case 3:
            llenarMatriz(M);
            break;
         case 4:
            lee_elem (M);
            break;
         case 5:
            vectorSumaColMatriz(M, V);
            break;
         case 6:
            mostrarMatriz(M);
            mostrarVector(V);
            break;
         case 7:
            break;
         default:
            printf ("\nOpcion invalida");
            break;
      } /* switch */
   } while (op != 7);

    return 0; /* Si llego hasta aca entonces no hubo error */
}
