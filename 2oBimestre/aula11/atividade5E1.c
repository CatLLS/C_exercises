#include <stdio.h>

/*como soma cada dígito? 

253%10 =3 -> 25(n=253/10)
25%10 = 5 -> 2 (n=25/10)
2%10 = 2 -> 0 (n=2/10)

3+6
5+2
2+0
0+0

*/

int somarDigitos(int n){
    //printf("%d",n); -> para testes
    if ((n== 0)){//chegamos na unidade
        return 0;
    }
    return (n%10)+somarDigitos(n/10);
}

int main(){
    printf("\nDigite o número que deseja verificar:");
    int n;
    scanf("%d", &n);
    printf("\nA soma dos dígitos deste número é: %d",somarDigitos(n));
}