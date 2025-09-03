/*Crie uma função em C que receba um vetor de números inteiros, 
conte quantos valores estão na faixa [10, 20] e substitua os valores que estão nesta faixa pelo número zero. 

Desenvolva um programa que leia um vetor de 7 posições, 
chame a função criada e apresente o vetor modificado e a quantidade de modificações.*/

# include <stdio.h>

int valoresFaixa(int vetor[],int tamanhoVetor){//em c vetores vc altera a propria posição da memória e não uma cópia
    int modificacoes = 0;
    for (int i = 0; i<tamanhoVetor; i++){//aqui a gnt usa o menor e não o menor igual pq começa em 0, e não em 1.
        if (vetor[i] > 10 && vetor[i]<20){
            vetor[i]=0;
            modificacoes += 1;
        }
    }
    return modificacoes;
}

int main(){
    int vetor[7];
    printf("Digite 7 números para analisar a lista:");
    for (int j= 0; j<7; j++){
        printf("Elemento %d: ", j+1);
        scanf(" %d", &vetor[j]);
    }
    int mudarVetor = valoresFaixa(vetor,sizeof(vetor)-sizeof(int));
    
    printf("\nForam feitas %d alterações, resultando em na lista: \n", mudarVetor);

    for (int j=0; j<7; j++){//para printar lista tem que percorrer elemento por elemento
        printf("%d ",vetor[j]);
    }
}