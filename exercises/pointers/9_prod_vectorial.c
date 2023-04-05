#include <stdio.h>
#include <stdlib.h>
#define N 3

double prod_esc (const double *a, const double *b, int n){
    double suma = 0, temp;
    for(int i = 0; i<n; i++){
        temp = *(a+i) * *(b+i);
        suma+=temp;
        printf("%.2f * %.2f = %.2f \n", *(a+i), *(b+i), temp);
    }
    printf("El producto vectorial es %.2f", suma);
}

int main()
{
    double a[N] = {1.0, 3.0, 2.0}, *pa;
    double b[N] = {5.0, 2.0, 7.0}, *pb;

    pa = a;
    pb = b;

    prod_esc(a, b, N);


    return 0;
}
