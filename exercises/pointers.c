#include <stdio.h>

int main(){
    int *p;
    int i;
    int k;
    i = 42;
    k = i;
    p = &i;

    k = 75; //only changes k
    printf("%d, %d\n", k, i); // k = 75 , i = 42

    // *k = 75; does not exist

    *p = 75;
    printf("%d, %d\n", *p, i); // *p = 75, i = 75
}
