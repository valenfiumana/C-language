# Pointers

A pointer is a variable whose value is the address of another variable. 

### Declaration
Like any variable or constant, you must declare a pointer before using it to store any variable address. 
```c
int    *ip;    /* pointer to an integer */
double *dp;    /* pointer to a double */
float*  fp;    /* pointer to a float */
char*   ch     /* pointer to a character */
```

### Pointers and memory address

```c
int x = 21;     // An int variable
int* ptr = &x;  // A pointer variable that stores the address of x

printf("Value of x: %d\n", myAge); // x = 21

printf("Memory address of x: %p\n", &myAge); // &x = 0x7ffe5367e044

printf("Memory address of x with the pointer: %p\n", ptr); // ptr = 0x7ffe5367e044

printf("Value of x with the pointer: %p\n", *ptr); // *ptr = 21 --> this is called dereference
```

### Uses of *

Note that the * sign can be confusing here, as it does two different things in our code:
* When used in declaration (int* ptr), it creates a pointer variable.
* When not used in declaration, it act as a dereference operator - which means that it can output the value 

## Arrays and Pointers

Arrays **are** ponters (an array name is a pointer to the first element).

```c
int a[10];
int *pa;

pa = &a[0];
```

### V[i] == *(v+i)

```c
char v[10];

v[0] = 15;
v[4] = 32;

printf("Memory address of first array element: %p \n", v); 
printf("Value of first array elemnt: %hhd \n", *v); // 15
printf("Value of array element number 4: %hhd \n", *(v+4)); // 32
```

### Increment and decrement pointers

```c
int main(){
    int a = 22;
    int *p = &a;
    printf("p = %u\n", p); // p = 6422288
    p++;
    printf("p++ = %u\n", p); //p++ = 6422292  // + 4 bytes
    p--;
    printf("p-- = %u\n", p); //p-- = 6422288  // - 4 bytes
 
    float b = 22.22;
    float *q = &b;
    printf("q = %u\n", q);  //q = 6422284
    q++;
    printf("q++ = %u\n", q); //q++ = 6422288      // + 4 bytes
    q--;
    printf("q-- = %u\n", q); //q-- = 6422284      // - 4 bytes
 
    char c = 'a';
    char *r = &c;
    printf("r = %u\n", r);   //r = 6422283
    r++;
    printf("r++ = %u\n", r);   //r++ = 6422284     // + 1 byte
    r--;
    printf("r-- = %u\n", r);   //r-- = 6422283     // - 1 byte
    return 0;
}
```
Example of usage:

```c
#include <stdio.h>
int main () {
	int i;
    int v[4] = {10, 20, 30, 40}; 
	int *p;
    
	p = v; /* It's the same as doing p = &v[0]; */
    
	for (i = 0; i < 4; i++) {
		printf ("Memory address: %p, value: %d \n", p, *p);
		p++;
	}
    
	return 0;
}
```

```c
```