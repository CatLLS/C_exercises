//versão do professor, a minha usava for loops, esta daqui é puramente condicional!

#include  <stdio.h>

int main(){
    int taxa;
    printf("Digite a taxa: ")
    scanf("%d", &taxa);

    int selos5, selos3;

    if (taxa % 5 == 0){
        selos5 = taxa/5;
        selos3 =0;
    }else if(taxa%5 ==1){
        selos5 = taxa/5 - 1;//pois está faltando 6 (ex: 11/5 =2 resto 1, se diminuir 1 selo de 5, o resto vira 6, que pode ser completado por 2 selos de 3!)
        selos3 = 2;
    }else if(taxa%5 == 2){
        selos5 = taxa/5 -2; //(ex: 12/5 = 10 sobra 2, se tirar apenas 1 fica 7 o que não dá certo, por isso tira 2, funciona com o 17 também!(17/5 = 3 -> 3-2 = 1 selo de 5 e o resto de selos de 3))
        selos3 = 4;
    }else if(taxa % 5 == 3){
        selos5 = taxa/5;
        selos3 = 1;
    }else if(taxa%5 == 4){
        selos5 = taxa/5 -1;
        selos3 = 3;
    }

    printf("Com %d, use %d selos de 5 e %d selos de 3 centavos.", taxa, selos5,selos3 )

}