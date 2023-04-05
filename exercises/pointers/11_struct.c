#include <stdio.h>
#include <stdlib.h>

struct mi_estructura {
    char a, b;
    int c;
    int e [5];
};

int main()
{
    struct mi_estructura me;
    struct mi_estructura *p = &me;

    p->b = '  ';
    printf("%c  \n", p->b);

    p->e [3] = 10; // ERROR it saves number 6422280
    printf("%d \n", p->e);

    (*p).a = '*';
    printf("%c \n", (*p).a);

    //*p.b = ’?’; ERROR it needs the parenthesis
    (*p).b = '?';
    printf("%c  \n", (*p).b);

    me.c = 1;
    printf("%d  \n", me.c);

    //p.c = 1; ERROR change . with ->
    p->c = 1;
    printf("%d  \n",  p->c);
    return 0;
}
