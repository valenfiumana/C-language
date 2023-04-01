// 5. Escribir una función que devuelva un puntero al máximo valor de un vector de “doubles”.
// Si el vector está vacío (cant = 0) la función debe retornar NULL.

#include <stdio.h>

double* max (double *v, int cant){
   int i;
   double *pmax;
   pmax = v;

   if(cant == 0)
      return NULL;


   for (i = 1; i < cant; i++){
      if (*(v + i) > *pmax)
         pmax = v + i;
      }
   return pmax;
}

void printMax(double *v, int cant){
    double *result;
    result = max(v, cant);

    if (result != NULL)
      printf ("Maximo: %.2f\n", *result);
    else
      printf("El vector esta vacio");
}

int main(){
   double v [10] = {11.23, 24.54, 3.87, 40.5, 5.32, 63.23, 765.6 ,843.3, 9.43, 10.23};
   double *result;

   printMax(v, 10);
   printMax(NULL, 0);


   return 0;
}
