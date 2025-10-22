//usar double para o imposto e para o salário bruto!!
//solicitar salario bruto
// calcular imposto de renda; salário:
// até 2000 = isento
//de 2001 a 4000 - 7.5%
//de 4001 a 6000 - 15%
//de 6001 a 10000 - 22%
//acima de 10000 - 27.5%
//imprimir valor cobrado de imposto, e como fica o salário líquido depois disso

//LEMBRAR DE CHECAR/TESTAR DEPOIS!!
#include <stdio.h>

int main(){
    double salarioB, imposto;
    printf("Digite o valor do seu Salário Bruto: ");
    scanf("%lf", &salarioB);

    if (salarioB <= 2000){imposto = 0;}
    else if (salarioB <= 4000){imposto = 0.075;}
    else if (salarioB <= 6000){imposto = 0.15;}
    else if (salarioB <= 10000){imposto = 0.22;}
    else{imposto = 0.275;}

    printf("Será cobrado %.2f do seu salário, resultando em um salário liquido de %.2f.\n", (salarioB*imposto), (salarioB-salarioB*imposto));


    return 0;
}
