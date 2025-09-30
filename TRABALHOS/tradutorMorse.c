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

char* resolverCorrompimento(char *msgCompleta, char alfabetoMorse[][5], char alfabeto[], int tamanhoAlfabeto){ 
    //retornar letras possíveis
    static char candidatos[28];
    int count = 0;

    for(int i = 0; i < tamanhoAlfabeto; i++){
           if (strncmp(msgCompleta, alfabetoMorse[i], strlen(msgCompleta)-1) == 0){
            candidatos[count++] = alfabeto[i];
        }
    }
    candidatos[count] = '\0';
    for (int i=0; i<count-1; i++){
        for (int j=i+1; j<count; j++){
            if (candidatos[i] > candidatos[j]){
                char tmp = candidatos[i];
                candidatos[i] = candidatos[j];
                candidatos[j] = tmp;
            }
        }
    }
    return candidatos;
} 

void decodificar(int tamanhoMSG, char msgTratada[][5], char msgDecodificada[]){
    char alfabetoMorse[][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                              ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                              "...","-","..-","...-",".--","-..-","-.--","--.."};
    char alfabeto[] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                       'M','N','O','P','Q','R','S','T','U','V','W','X',
                       'Y','Z'};

    int posicaoMsgFinal = 0;

    for (int i = 0; i < (tamanhoMSG/5) && msgTratada[i][0] != '\0'; i++){
        // se for marcador de espaço entre palavras
        if (strcmp(msgTratada[i], "_") == 0){
            msgDecodificada[posicaoMsgFinal++] = ' ';
            continue;
        }

        int len = strlen(msgTratada[i]);
        // se a letra está corrompida (termina com '*')
        if (len > 0 && msgTratada[i][len - 1] == '*'){
            char *candidatos = resolverCorrompimento(msgTratada[i], alfabetoMorse, alfabeto, 26);
            msgDecodificada[posicaoMsgFinal++] = '[';
            for (int k = 0; candidatos[k] != '\0'; k++){
                msgDecodificada[posicaoMsgFinal++] = candidatos[k];
            }
            msgDecodificada[posicaoMsgFinal++] = ']';
            continue;
        }

        // caso normal: comparar com tabela morse
        int encontrado = 0;
        for (int j = 0; j < 26; j++){
            if (strcmp(msgTratada[i], alfabetoMorse[j]) == 0){
                msgDecodificada[posicaoMsgFinal++] = alfabeto[j];
                encontrado = 1;
                break;
            }
        }
        if (!encontrado){
            // coloca '?' se não encontrou correspondencia
            msgDecodificada[posicaoMsgFinal++] = '?';
        }
    }

    // finaliza string resultante
    msgDecodificada[posicaoMsgFinal] = '\0';
}

int main(){
    char alfabetoMorse[][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--", "-.","---",".--.","--.-", ".-.", "...","-","..-","...-",".--","-..-","-.--","--.."};
    char alfabeto[]= {'A','B','C','D','E', 'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    int tamanhoMSG=300;
    char msgTratada[tamanhoMSG/5][5];
    char msgDecodificada[tamanhoMSG/5];
    char deNovo;

    do{
        printf("\n*⣾⠛⠛⠲⣤           ⣠⡴⠞⠛⢻⡆*\n*⣿      ⠙⢦⡀    ⣠⠞⠁   ⢸⡇ ⁺⊹*\n*⢿⡄        ⠹╄⡼⠁      ⣼⠇*\n*⠘⢷⣄╀.    ⠙⠁     ⣀╀╴⠟*\n  *⣼⠛⠉⠉          ⠈⠉⠙⢻⡄*\n *⠘⣷        ⡞⣦     ⣰⡟*\n*⊹ ⠈⠻⣦╤⡶⠋⠈   ⠳╦╤⡾⠋   ₊*");
        printf("\n✩₊˚.⋆☾⋆⁺₊✧ Bem vindo ao Decodificador Morse 3000 ✩₊˚.⋆☾⋆⁺₊✧ \n\n-resolvendo códigos desde a era da guerra");
        printf("\n--------🗝️⋆.⚚.⋆꩜.⚚ᐟ⋆.🗝️--------\n");

        tratarInput(tamanhoMSG, msgTratada);

        decodificar(tamanhoMSG, msgTratada, msgDecodificada);//Obs: a função resolver corrompimento está dentro da função decodificar!!!

        //para debug(o for abaixo printa cada letra da mensagem tratada, podem usar se precisarem meninas!), deletar depois:
        /*for (int i=0; i< (tamanhoMSG/5) && msgTratada[i][0] != '\0'; i++){
            printf("\nPalavra %d:>%s<", i+1, msgTratada[i]);
        }*/
        printf("\nHmm, os nossos detetives chegaram a conclusão de que a sua mensagem significa: \n");
        printf("\n%s\n", msgDecodificada);
        printf("\n\n                  ╱|、                   \n                (˚ˎ 。7  \n                 |、˜〵          \n                じしˍ,)ノ");
        
        printf("\nDeseja decodificar outra mensagem?(s/n): ");
        scanf("%c", &deNovo);
        getchar();

    }while(deNovo == 's' || deNovo == 'S');
    
    printf("\nPrograma encerrado com sucesso, obrigada por usar o Decodificador Morse 3000!\n\n ∧,,,∧\n( ̳• ·• ̳)\n/   づ♡ \n");

    return 0;
}