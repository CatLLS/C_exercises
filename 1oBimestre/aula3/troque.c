/*Escreva um programa que implemente uma função chamada troca que recebe
 dois valores inteiros como parâmetro e troque o conteúdo destes parâmetros.*/

#include <stdio.h>

void troca(int*a, int*b){
    int aProvisorio = *a;
    int bProvisorio = *b;
    *b = aProvisorio;
    *a = bProvisorio;

}

int main(){
    int a, b;
    printf("Digite o valor das variáveis, com uma vírgula entre elas(ex: a,b):");
    scanf(" %d,%d",&a,&b);
    troca(&a,&b);
    printf("\n1o num =%d, 2o num = %d\n", a,b);
}