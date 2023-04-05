#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = 'A';
    char *p = &c; // It has to be a char pointer, not a double pointer

    printf(" c =%c\n p = %p\n *p = %c", c, p, *p);
    return 0;
}
