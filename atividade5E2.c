#include <stdio.h>

/* como transformamos em binário?
-> nós vamos dividindo por dois e pegando o resto até que chegamos no último, aí vai ajuntando de trás para frente

se for string é mais fácil, mas provavelmente queremos int...

ex: n=15 --> 1111
15%2 = 1*10^0(=1) + próximo, devolve 15//2
7%2 = 1*10^1(=10) + próximo, devolve 7//2
3%2 = 1*10^2(=100)+ próximo, devolve 3//2
1%2 = 1 *10^3(1000)
-> caso base! quando n==0, devolver 0
*/
int transformarBIN(int n, int base){
    if (n==0){
        return 0;
    }
    return (n%2)*base + transformarBIN(n/2, base*10);
}

int main(){
    printf("\nDigite o número:");
    int n;
    scanf("%d", &n);

    printf("\nO númmero em binário é: %d\n",transformarBIN(n,1));
}