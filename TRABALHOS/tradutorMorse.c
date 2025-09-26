/*Inserir cabeçalho*/


// funçao de menu
//funçao de recebimento/tratamento dos dados(guardar em uma matriz cada palavra(linha) letra(coluna))
// o maior tamanho que uma letra em morse tem é 4+\0 = 5

//a minha parte é do recebimento das strings

#include <stdio.h>
#include <string.h>

void tratarInput(int tamanhoMSG, char msgMatriz[][5]){
    int espacoNoFinal=0;

    printf("\nDigite a mensagem codificada: ");
    char msgCompleta[tamanhoMSG+espacoNoFinal];
    fgets(msgCompleta,tamanhoMSG,stdin);
    msgCompleta[strcspn(msgCompleta, "\n")] = '\0';
    
    
    char letra[5]={0};//letras em morse são no máximo 4 caracteres + \0
    int currentLetraIndex=0;
    int indexPalavrasMSGfinal=0;

    for(int i=0; i< strlen(msgCompleta);i++){
        
        
        if(msgCompleta[i]==' '){
            if (currentLetraIndex>0){
                letra[currentLetraIndex] = '\0';
                //printf("\nadicionando<%s>", letra);
                strncpy(msgMatriz[indexPalavrasMSGfinal],letra,5);
                indexPalavrasMSGfinal++;
                memset(letra, 0, sizeof(letra));//limpando o acumulador
                currentLetraIndex=0;
            }
            
            if (msgCompleta[i+1] == ' '){
                strncpy(msgMatriz[indexPalavrasMSGfinal], "_", 5);
                //printf("\nadicionando<_>");
                indexPalavrasMSGfinal++;
                i++;
            }
            
            
        }else{//para contabilizar a última letra que não terá um espaço nela
            if (currentLetraIndex < 4){
                letra[currentLetraIndex] = msgCompleta[i];
                currentLetraIndex++;
            }
        }
        
    }

    if (currentLetraIndex > 0) {
        letra[currentLetraIndex] = '\0';
        //printf("\nadicionando<%s>", letra);
        strncpy(msgMatriz[indexPalavrasMSGfinal], letra, 5);
        indexPalavrasMSGfinal++;
    }
    
}

int main(){
    char alfabetoMorse[][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--", "-.","---",".--.","--.-", ".-.", "...","-","..-","...-",".--","-..-","-.--","--.."};
    char alfabeto[]= {'A','B','C','D','E', 'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    int tamanhoMSG=300;
    char msgTratada[tamanhoMSG/5][5];
    
    tratarInput(tamanhoMSG, msgTratada);
    //para debug(o for abaixo printa cada letra da mensagem tratada, podem usar se precisarem meninas!), deletar depois:
    /*for (int i=0; i< (tamanhoMSG/5) && msgTratada[i][0] != '\0'; i++){
        printf("\nPalavra %d:>%s<", i+1, msgTratada[i]);
    }
    */

    printf("\nProgama encerrado com sucesso.\n");
    return 0;
}