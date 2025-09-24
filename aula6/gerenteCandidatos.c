/*Sistema de gerenciamento de candidatos de uma universidade
Você está desenvolvendo um sistema para gerenciar as inscrições de candidatos para uma
universidade. O sistema mantém um registro de números de inscrição dos candidatos que já se
inscreveram, armazenados em um vetor. São necessárias duas operações principais no sistema:

1.Verificação de Inscrição (Busca Linear): Quando um candidato tenta se inscrever, o sistema faz
uma busca linear para verificar se o número de inscrição já existe no vetor de números de
inscrição desordenados. Se o número já existir, o sistema avisa que o candidato já está inscrito.
Caso contrário, o sistema insere o número de inscrição no final do vetor.

2.Consulta de Números de Inscrição (Busca Binária): Periodicamente, o sistema precisa consultar se
um determinado número de inscrição existe. Antes de realizar essa consulta, o vetor de números
de inscrição é ordenado e, então, o sistema realiza uma busca binária para verificar rapidamente
se o número de inscrição está presente.*/

#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int verificarInscricao(int num, int tamanho,int vetor[]){
    for(int i=0; i<tamanho; i++){
        if (vetor[i] == num){
            return 1;
        }
    }
    return 0;
}

void ordenar(int tamanho, int vetor[]){}

void consultaInscricao(int tamanho,int vetor[]){
    int num = rand()%tamanho +1;

    ordenar(tamanho,vetor);
    int inicio = 0, fim = tamanho-1;
    while(inicio<=fim){
        int meio = (inicio+fim)/2;
        if (vetor[meio] == num){
            printf("\nO número %d existe.",)
            return meio;//no meu código n usa a posição, mas está aí se vc precisar
        }else if(vetor[meio]<num){
            inicio = meio+1;
        }else{
            fim = meio -1;
        }
    
    }
    return -1; //n achou nada



}

int main(){
    int periodo = 4; //a cada 4 inscrições registradas no vetor o programa faz a consulta do número de inscrição, vc pode mudar o período se desejar
    srand(time(NULL));
    int contador = 0;
    int nMaxInscritos = 100;
    int inscritos[nMaxInscritos];

    char continuar;

    do{
        //checagem periódica
        if (contador % 4 == 0){
            consultaInscricao(nMaxInscritos, inscritos);
        }
        //inserindo inscrição
        printf("\nBem vindo, por favor, digite o número que deseja inscrever: ");
        int num;
        scanf("%d", &num);
        if (verificarInscricao(num, inscritos, nMaxInscritos) == 0){
            inscritos[contador]=num;
            contador++;
            printf("Inscrição adicionada com sucesso!");
        }else{printf("Já existe um candidato inscrito com este número!");}


        printf("\nInscritos até agora: ");
        for(int i=0; i<contador; i++){
            printf(" %d",inscritos[i]);
        }

        printf("\nDeseja continuar inserindo candidatos?(S/N)");
        scanf(" %c",&continuar);
    }while(continuar!='N');

    return 0;
}