#include <stdio.h>
#include <stdlib.h>

struct f{
    union {
        char a, b;
        int c;
    } d;
    int e [5];
};

int main()
{
    struct f f, *p;
    p = &f;

    // p->b = ''; ERROR b is inside union d
    p->d.b = 'c';
    printf("%c \n",  p->d.b);

    p->e[3]=10; // ERROR it saves number 6422280
    printf("%d \n", p->e);

    (*p).d.a = '*';
    printf("%c \n", (*p).d.a);

    //p->d->c = 'x'; ERROR -> only for pointers to structs
    p->d.c = 'x';
    printf("%c \n", (p->d.c));
    return 0;
}
