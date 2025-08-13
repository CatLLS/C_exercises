#include <stdio.h>

int main() {
    int numero;
    printf("informe um número: ");
    scanf("%d", &numero);
    int dobro = numero * 2;

    printf("Dobro = %d \n", dobro); // o \n é para ele não sair colocando as próximas coisas do terminal em cima
}