#include <stdio.h>
#include <stdlib.h>

int main() {
    char binaryString[] = "01100001"; // Exemplo de uma string binária
    unsigned long number = strtoul(binaryString, NULL, 2);

    printf("Número inteiro: %lu\n", number);

    return 0;
}
