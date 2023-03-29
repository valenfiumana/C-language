/*
Leer un string por teclado:
1) y convertirlo a mayúsculas sin usar las funciones de string.h
2) y mostrarlo en orden inverso sin usar las funciones de string.h
Leer 5 strings por teclado:
3) y mostrar el “mayor” (alfabéticamente)
4) y mostrar el de mayor longitud
5) y almacenarlos en un archivo.
6) Leer los strings del archivo del ej. anterior y mostrarlos en pantalla.
*/

#include <stdio.h>
#include <string.h> //para funciones de strings

// MOSTRAR ARRAY
void mostrar(char array[4][10]){
  printf("\n");
  for(int i=0; i<=4; i++){
    printf("%s ", array[i]);
  }
  printf("\n");
}

// ORDEN ALFABETICO Y MAYOR
void ordenAlfabetico(char array[4][10]){
    char temp[10];
    for(int i=0; i<=4; i++){
    for(int j=0; j<=4-1-i; j++){
      if(strcmp(array[j], array[j+1]) > 0){
        //swap array[j] and array[j+1]
        strcpy(temp, array[j]);
        strcpy(array[j], array[j+1]);
        strcpy(array[j+1], temp);
      }
    }
  }

  printf("Las palabras ordenadas alfabeticamente: \n");
  mostrar(array);

    printf("La mayor alfabeticamente es: ");
    printf(array[4]);
}

// MAYOR LONGITUD
void mayorLongitud(char array[4][10]){
    char max[10] = "a";

    for(int i=0; i<=4; i++){
        if(strlen(array[i]) > strlen(max)){
            strcpy(max, array[i]);
        }
    }

    printf("\nLa palabra de mayor longitud es: ");
    printf("%s", max);
}

//INVERTIR PALABRA
void invertir(char str[]){
    char temp;
    int i=0, j;

    j = strlen(str) - 1; //-1 para no contar el final '/0'

    //ej: valen
    //str[0] = v
    //str[5] = n
    while (i < j) {
        temp = str[i]; //temp = v
        str[i] = str[j]; // str[0] = n --> 'nalen'
        str[j] = temp; // str[5] = v --> 'nalev'
        i++;
        j--;
    }
    printf("\nEl string invertido es: %s\n", str);

}

//MINUS A MAYUS
void aMinuscula(char str[]){
    for (int i=0; i<=strlen(str); i++){
        if (str[i] >= 'A' && str[i] <= 'Z') //'A' = 65 y 'Z' = 90
            str[i] = str[i] + 32; //sumamos 32 para hacerlo mayuscula
    }
    printf (" \nMayuscula a minuscula: %s", str);
}

// MAYUS A MINUS
void aMayuscula(char str[]){
    for (int i=0; i<=strlen(str); i++){
        if (str[i] >= 'a' && str[i] <= 'z') //'A' = 65 y 'Z' = 90
            str[i] = str[i] - 32; //restamos 32 para hacerlo minuscula
    }
    printf (" \nMinuscula a mayuscula: %s", str);
}

// ESCRIBIR ARCHIVO --> no se como hacer para array of Strings
void escribirArchivo(char array[4][10]){
    int n, n1;
    FILE *fp = fopen("strings.txt", "w");
    if(fp == NULL){
        perror("Error al abrir");
        exit(1);
    }
    for(int i=0; i<=4; i++){
        fwrite(array[i], sizeof(char), sizeof(array[i]), fp);
        fwrite(' ', sizeof(char), 1, fp);
    }
    if(n == 0){
        perror("Error al escribir");
        exit(2);
    }
    n1 = fclose(fp);
    if(n1 != 0){
        perror("Error al cerrar");
        exit(3);
    }
}

// LEER ARCHIVO
void leerArchivo(char array[4][10]){
    int n, n1;
    FILE *fp = fopen("strings.txt", "r");
    if(fp == NULL){
        perror("Error al abrir");
        exit(1);
    }
    n = fread(array, sizeof(char), sizeof(array), fp);
    n1 = fclose(fp);
    if(n1 != 0){
        perror("Error al cerrar");
        exit(3);
    }
}

int main()
{
    char str[10], arrayStrings[4][10], array2[4][10];
    printf("Ingresa una palabra: \n");
    scanf("%s", str);

    aMayuscula(str);
    invertir(str);

    for(int i=0; i<=4; i++){
        printf("\nIngresa una palabra: \n");
        scanf("%s", arrayStrings[i]);
    }


    ordenAlfabetico(arrayStrings);
    mayorLongitud(arrayStrings);

    escribirArchivo(arrayStrings);
    leerArchivo(array2);
    mostrar(array2);

    return 0;
}
