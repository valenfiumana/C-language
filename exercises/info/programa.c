#include <stdio.h>

void mostrarBits(unsigned char number) {
    printf("Número en binario: ");
    for (int i = 7; i >= 0; i--) {
        unsigned char bit = (number >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    unsigned char number;

    printf("Ingrese un número entero de 8 bits sin signo: ");
    scanf("%hhu", &number);

    // Mostrar el número ingresado en hexadecimal
    printf("\nNúmero en hexadecimal: 0x%02X\n", number);

    // Mostrar el número ingresado en binario
    mostrarBits(number);

    // Verificar el 5to bit
    // Aquí, (number >> 4) desplaza los bits hacia la derecha 4 posiciones,
    //y luego & 1 se utiliza para obtener el bit más a la derecha y descartar los demás.
    int fifthBit = (number >> 4) & 1;
    printf("\nEl 5to bit es: %d\n", fifthBit);

    // Verificar si el primero y el cuarto bit están en uno
    int firstBit = (number >> 7) & 1;
    int fourthBit = (number >> 4) & 1;
    int firstAndFourthBits = firstBit & fourthBit;
    printf("\nEl primer y cuarto bit están en uno: %s\n", firstAndFourthBits ? "Si" : "No");

    // Verificar si el primero o el cuarto bit están en uno
    int firstOrFourthBits = firstBit | fourthBit;
    printf("\nEl primer o cuarto bit están en uno: %s\n", firstOrFourthBits ? "Si" : "No");

    // Modificar el número poniendo en uno los bits de los extremos
    unsigned char modifiedNumber = number | 0x81;
    printf("\nNúmero modificado (bits de los extremos en uno): 0x%02X\n", modifiedNumber);
    mostrarBits(modifiedNumber);

    // Modificar el número poniendo en cero los bits de los extremos
    modifiedNumber = number & 0x7E;
    printf("\nNúmero modificado (bits de los extremos en cero): 0x%02X\n", modifiedNumber);
    mostrarBits(modifiedNumber);

    // Niegue el número
    modifiedNumber = ~number;
    printf("\nNúmero negado: 0x%02X\n", modifiedNumber);
    mostrarBits(modifiedNumber);

    // Niegue solo los 4 bits menos significativos
    modifiedNumber = number ^ 0x0F;
    printf("\nNúmero con los 4 bits menos significativos negados: 0x%02X\n", modifiedNumber);
    mostrarBits(modifiedNumber);

    return 0;
}
