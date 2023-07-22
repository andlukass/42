#include <stdio.h>
#include <math.h>

int gerarNumeroAleatorio() {
    double numeroAleatorio = sin(1.0);  // Obtém um valor entre -1 e 1

    int numero = (int)(fabs(numeroAleatorio) * 4) + 1;  // Mapeia o valor absoluto para o intervalo de 1 a 4

    return numero;
}

int main() {
    int numero = gerarNumeroAleatorio();
    printf("Número aleatório: %d\n", numero);

    return 0;
}