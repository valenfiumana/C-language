#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a [1]; //15
    int *q = &a [5]; //2

    printf("%d\n", *(p+3)); //14
    printf("%d\n", *(q-3)); //34
    printf("%p\n", q-p);
    printf("%p %p\n", p, q);
    printf("%d %d\n", *p, *q);
    return 0;
}
