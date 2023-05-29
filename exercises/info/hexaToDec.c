#include <math.h>
#include <stdio.h>
#include <string.h>

void decToHexa(unsigned char decimal_Number) {
    int i = 1, j;
    unsigned char temp;
    char hexa_Number[100];

    // si el número decimal no es igual a cero, entrar al bucle y ejecutar las instrucciones
    while (decimal_Number != 0) {
        temp = decimal_Number % 16;

        // convirtiendo el número decimal en un número hexadecimal
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        hexa_Number[i++] = temp;
        decimal_Number = decimal_Number / 16;
    }
    // imprimir el número hexadecimal
    printf("Valor hexadecimal es: ");
    for (j = i - 1; j > 0; j--)
        printf("%c", hexa_Number[j]);
}

unsigned char hexToDecimal(const unsigned char* hexadecimalNumber)
{
    unsigned char decimalNumber = 0;
    int length = strlen(hexadecimalNumber);
    int power = 1;

    for (int i = length - 1; i >= 0; i--) {
        unsigned char currentChar = hexadecimalNumber[i];
        unsigned char digit = 0; // Dígito decimal correspondiente al carácter

        if (currentChar >= '0' && currentChar <= '9') {
            digit = currentChar - '0';  // Carácter numérico: '0' to '9'
        } else if (currentChar >= 'A' && currentChar <= 'F') {
            digit = currentChar - 'A' + 10; // Carácter alfabético mayúscula: 'A' to 'F'
        } else if (currentChar >= 'a' && currentChar <= 'f') {
            digit = currentChar - 'a' + 10; // Carácter alfabético minúscula: 'a' to 'f'
        }

         // Multiplicamos el dígito por la potencia correspondiente y lo agregamos al número decimal
        decimalNumber += digit * power;
        power *= 16; // Devolvemos el número decimal resultante
    }

    return decimalNumber;
}

int main()
{
    // - - - - DECIMAL TO HEXA - - - -

    unsigned char decimalNumber;

    //FORMA 1: USANDO FORMAT SPECIFIER %X
    printf("Ingrese un valor decimal sin signo de 8 bits: ");
    scanf("%u", &decimalNumber);
    printf("Hexadecimal es: %X", decimalNumber);


    // FORMA 2: FUNCION QUE DIVIDE
    printf("\n\nIngrese un valor decimal sin signo de 8 bits: ");
    scanf("%u", &decimalNumber);
    decToHexa(decimalNumber);


    // - - - - HEXA TO DECIMAL - - - -

    unsigned char hexaNumber;

    //FORMA 1: USANDO FORMAT SPECIFIER %hhx y %hhu
    printf("\n\nIngrese un valor hexadecimal sin signo de 8 bits (2 digitos): ");
    scanf("%hhx", &hexaNumber);
    printf("Decimal es: %hhu", hexaNumber);


    // FORMA 2: FUNCIÓN
    unsigned char hexadecimalNumber[3]; // 2 lugares por los 8 bits, 1 para el nulo

    printf("\n\nIngrese un valor hexadecimal sin signo de 8 bits (2 digitos): ");
    scanf("%2s", hexadecimalNumber);

    unsigned char decimal_Number = hexToDecimal(hexadecimalNumber);

    printf("Decimal Number: %u\n", decimal_Number);

    return 0;
}
