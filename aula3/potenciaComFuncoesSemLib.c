#include <stdio.h>

int potencia(int base, int expoente){
    int result = 1;
    for (int i = 1; i<= expoente; i++){
        result = result*base;
    }
    return result;
}

int main(){
    int base, exp;
    printf("Digite a base e potência(base^expoente): ");
    scanf(" %d^%d", &base, &exp);
    printf("\nResultado = %d\n", potencia(base,exp));
}