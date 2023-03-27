# File management

## Basics

</br>

The structure is always the following:

1. **Declare variables**
* that we'll use to check that the file was read and closed correctly.

```c
int c, c1;
```

* that will save the data (or that contains the data if you want to write the file)

```c
int M[4][3];
```

2. **Open the file** and check that it was opened correctly. The file must be in the same folder as the code.

```c
FILE * fp = fopen("matriz.dat", "rb");
    if(fp==NULL){
        perror("Error al abrir archivo");
        return -1;
    }
```

3. **Read (or write) the file**. This part changes depending on whether you are reading a matrix, a vector or another structure.

```c
c = fread(M, sizeof(M), 1, fp);
    if(c!=1){
        perror("Error al leer");
        return -2;
    }
```

```c
c = fwrite(M, sizeof(M), 1, fp);
    if(c != 1){
        perror("Error al escribir");
        return -2;
    }
```

4. **Close the file.**

```c
c1 = fclose(fp);
        if(c1 != 0){
            perror("Error al cerrar");
            return -3;
        }
```

5. **Everything together:**

```c
#include <stdio.h>
int main()
{
    int c, c1;
    float M[4][3];

    FILE * fp = fopen("matriz.dat", "rb");
    if(fp==NULL){
        perror("Error al abrir archivo");
        return -1;
    }
    else{
        c = fread(M, sizeof(M), 1, fp);
        if(c!=1){
            perror("Error al leer");
            return -2;
        }
        mostrarMatriz(M);

        c1 = fclose(fp);
        if(c1 != 0){
            perror("Error al cerrar");
            return -3;
        }
    }

    return 0;
}
```

6. **Inside a function:**

```c
void readingMatrix(int M[20][10]){
    int c, c1;
    FILE * fp = fopen("enteros.dat", "rb");
    if(fp==NULL){
        perror("Error al abrir archivo");
        return -1;
    }
    else{
        c = fread(M, sizeof(M), 1, fp);
        if(c!=1){
            perror("Error al leer");
            return -2;
        }
        mostrarMatriz(M);

        c1 = fclose(fp);
        if(c1 != 0){
            perror("Error al cerrar");
            return -3;
        }
    }
}
```

</br>

## Reading files
For writing files just replace 'fread' with 'fwrite'

</br>

### 1. MATRIX



* version 1

```c
    float M[4][3];
    
    c = fread(M, sizeof(M), 1, fp);
        if(c!=1){
            perror("Error al leer");
            return -2;
        }
```

* version 2

```c
    int M[4][3];
    
    c = fread(M, sizeof(M[0][0]), 4*3, fp);
    if(c!=4*3){
        perror("Error al leer");
        return -2;
    }
```

### 2. ARRAY

```c
    float v[10];

    c = fread(v, sizeof(float), 10, fp);
    if(c!=10){
        perror("Error al leer el archivo");
        return(-2);
    }
```

### 3. STRUCT

```c
```


```c
```

</br>

