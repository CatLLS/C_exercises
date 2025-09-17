//função que recebe uma lista de nomes e um nome a ser buscado e retorna a sua posição
//caso o nome não seja encontrado retorna -1
//Main: ler uma lista de 10 nomes, o nome a ser procurado e printar uma mensagem se foi encontrado ou não

#include <stdio.h>
#include <string.h>

int buscarNome(
    int qtdePalavras, 
    int tamanhoPalavras, 
    char listaNomes[qtdePalavras][tamanhoPalavras], 
    char nome[tamanhoPalavras]){

        for(int i =0; i<qtdePalavras; i++){
            printf("\nprocurando %s em %s...", nome, listaNomes[i]);
            if (strcmp(nome, listaNomes[i])==0){
                return i;                
            }
        }

        return -1;
}

int main(){
    printf("\nQuantos nomes deseja inserir?");
    int qtdeN;
    int tamanhoN = 50;//vc pode mudar se quiser
    scanf("%d", &qtdeN);
    getchar();//pq a gnt vai pegar strings depois
    char nomes[qtdeN][tamanhoN];

    for(int i=0; i<qtdeN; i++){
        printf("\nNome %d: ", i+1);
        fgets(nomes[i], tamanhoN, stdin);
        //printf("-->%s<--", nomes[i]);
        
    }
    //getchar();
    printf("\nQual nome deseja encontrar? ");
    char nomeR[tamanhoN];
    fgets(nomeR, tamanhoN, stdin);


    int result = buscarNome(qtdeN, tamanhoN, nomes, nomeR);

    //tirar o \n do nome antes de printar:
    nomeR[strcspn(nomeR, "\n")]=0;
    if (result == -1){
        printf("\nA palavra %s não foi encontrada.", nomeR);
    }else{
        printf("\n A palavra %s foi encontrada na posição %d\n", nomeR, result);
    }

    return 0;
}