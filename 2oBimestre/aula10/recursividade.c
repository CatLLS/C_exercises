//algoritmo de Euclides

#include <stdio.h>

int mdc(int divisor, int dividendo, int contador){
    int resto = divisor % dividendo;
    printf("\nRound:%d -> divisor: %d, dividendo:%d, resto:%d", contador, divisor, dividendo, resto);
    if (resto == 0){
        return dividendo;
        //printf("\n%d", resto);
    }
    return mdc(dividendo,resto,contador+1);
}

int main(){
    printf("\n%d\n",mdc(30,22,1));
}