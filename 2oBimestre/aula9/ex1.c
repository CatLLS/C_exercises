/*1) Um sistema de climatização industrial recebe leituras de temperatura de 20 sensores. Para identificar anomalias, é
necessário ordenar os valores e verificar os extremos. Implemente o Bubble Sort para ordenar os dados e exiba a
menor e maior temperatura registrada.*/

#include <stdio.h>

void bubbleSort(int n, int v[]){

    int troca;
    for(int i =0; i<n-1; i++){

        troca =0;
        for (int j=0; j<n-1-i;j++){//o bubble sort vai deixando organizado no final, por isso eu paro antes, diferente do selection sort

            if(v[j]>v[j+1]){
                //se for maior a gnt troca
                //para deixar decrescente é só mudar esse sinal
                int temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;

                troca=1;
            }
        }
        if(troca == 0){break;}
    }
}


int main(){
    int nTemp = 20;
    int temperaturas[nTemp];

    for (int i= 0; i<nTemp; i++){
        printf("Digite a temperatura %d: ", i+1);
        scanf("%d", &temperaturas[i]);
    }

    bubbleSort(nTemp, temperaturas);

    printf("\nMínimo: %d, Máximo: %d", temperaturas[0], temperaturas[nTemp-1]);
}