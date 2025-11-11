# include<stdio.h>
# include <stdlib.h>//-> como em argv só recebemos string, usamod o atoi() para transformar em int

int main(int argc, char *argv[]){
    //argV-> matriz de strings, temos um ponteiro para um vetor de caracteres, 
    //como tem o ponteiro não precisa definir quantas strings terá.
    
    printf("\nQuantidade de parâmetros: %d", argc);
    for (int i=1; i< argc; i++){
        printf("\n%s", argv[i]);
    }

    //int numero = atoi(argv[3]); //->pode dar erro se vc não passar o 3o parametro..., 
    //primeiro verificar se o parametro foi passado!/passado corretamente

    //ex: lidando com arquivo texto:

    FILE *arquivo;
    arquivo = fopen(argv[1], "r+");//-> o caminho do arquivo será passado no 1o arg da linha de comando
    /*letrinhas são os modos, r,w,a,r+,w+  -> "a" adiciona no final, w reescreve do zero, vai apagando as coisas 
    r+ modo de leitura e escrita onde estiver o seu cursor de leitura sem sobreescrever(?), w+ leitura e escrita mas substitui/reescreve o arquivo, a+ leitura e adicionar no final*/
    if (arquivo == NULL){
        printf("\nErro ao abrir o arquivo\n");
        return 1;
    }
    //fscanf(), 
    char linha[6];//o tamanho da linha nesse arquivo é mais ou menos 6
    fscanf(arquivo, "%s", linha);//lê na ordem das linhas!aqui vai ser a linha 1, por isso o pessoal usa while e percorre linha por linha
    int tamanho = atoi (linha);

    printf("\n%d\n", tamanho);
    //fprintf(arquivo, "Teste\n");

    //ou:

    int valor;
    fscanf(arquivo, "%d", tamanho);
    for (int i=0; i<tamanho; i++){//assim não preciso ler linha por linha e converter
        fscanf(arquivo,"%d", &valor);
        printf("%d", valor)

    }

    fclose(arquivo);//aí ele realmente grava os dados e encerra
    return 0;
}