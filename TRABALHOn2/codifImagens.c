/*Lívia Calado de Carvalho Dias 10737709
  Catarina Silva E Meirelles    10239324
  Beatriz de Assis Siqueira     10741570*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printImg(int altura, int largura, int matriz[altura][largura]){
   for(int i = 0; i < altura; i++){
        printf("\n");
        for(int j = 0; j < largura; j++){ 
            printf(" %d", matriz[i][j]);
        }
   }
}

void cortar(int altura, int largura, int matriz[altura][largura]){
    int corteX2 = altura/2;//divisão inteira
    int corteX1 = altura-corteX2;
    int corteY2 = largura/2;
    int corteY1 = largura-corteY2;
    printf("\n<%d><%d><%d><%d>\n", corteX1, corteX2, corteY1, corteY2);
}

void codificar_imagem(int altura, int largura, int matriz[altura][largura], char resultado[]){//cat
    //analisar se a imagem inteira está completa, se não, cortá-la
    char preenchimento[2];
    int referencia = matriz[altura-1][largura-1];
    printf("\nreferencia =<%d>\n", referencia);

    if (referencia == 0){
            preenchimento[0] = 'B';
        }else{
            preenchimento[0] = 'P';
        }

    if (altura <= 1 && largura <= 1){
        strcat(resultado, preenchimento);
        printf("\nAltura atual: %d, Larg: %d, item[]: <%d>\n", altura, largura, matriz[altura-1][largura-1]);
        return;
    }

    for(int i=0; i<altura; i++){
        for(int j=0; j<largura; j++){
            printf("\nmatriz[%d][%d]= <%d>\n", i,j, matriz[i][j]);
            if (matriz[i][j] != referencia){
                preenchimento[0] = 'X';
                strcat(resultado, preenchimento);
                printf("\ncorte\n");
                cortar(altura, largura, matriz);
                return;
            }
        }
    } 

    strcat(resultado, preenchimento);
    printf("\n percorreu loop ->%s", resultado);

}

void modo_manual(char resultado[]){//Livia
    int largura, altura;
    printf("Modo Manual Ativado;\n");
    printf("Informe a largura da imagem: ");
    scanf("%d", &largura);
    printf("Informe a altura da imagem: ");
    scanf("%d", &altura);
    if (largura <= 0 || largura > 1024 || altura <= 0 || altura > 768){
        printf("Dimensões inválidas. A largura deve ser entre 1 e 1024, e a altura entre 1 e 768;\n->Tente novamente!\n");
        //modo_manual(resultado);
        return;
    }
    int matriz[altura][largura];
    printf("Informe os valores da matriz (0 para branco, 1 para preto):\n");
    //scanf("%d", matriz[0][0]);
    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){
            scanf("%d", &matriz[i][j]);
            if (matriz [i][j] != 0 && matriz[i][j] != 1){
                printf("Valor invalido na posição (%d, %d). Use 0 para branco e 1 para preto.\nTente novamente!\n", i, j);
                //modo_manual(resultado);
                return;
            }
        }
    }
    codificar_imagem(altura, largura, matriz, resultado);
    return;
}

/*
int modo_arquivo(char *file, char resultado[]){//bea
    int largura, altura;
    int matriz[altura][largura];
    FILE *file;     

    arqv = fopen(file[1], "r");

    if(arqv == NULL){
        printf("Erro ao abrir o arquivo. Arquivo vazio.");
        return 1;
    }

    for(int i = 0; i <= altura; i++){
        for(int j = 0; j <= largura; j++){
            fscanf(file, "%d", &matriz[i][j]);
        }
    }
    fclose(file);
    codificar_imagem(altura, largura, matriz, &resultado);
}*/

int exibir_ajuda(){
    printf("Uso: ImageEncoder [-? | -m | -f ARQ]\n");
    printf("Codifica imagens binários dadas em arquivos PBM ou por dados informados pelo usuário.\n\n");
    printf("Argumentos:\n");
    printf(" -?, --help : apresenta essa orientação na tela;\n");
    printf("-m, --manual : ativa o modo de entrada manual, em que o usuário fornece todos os dados da imagem infomando-os através do teclado;\n");
    printf("-f, --file : considera a imagem respresentado no arquivo PBM (Portable Bitmap)\n");
}

int main(int argc, char *argv[]){
    if(argc == 1 || strcmp(argv[3], "-?") == 0 || strcmp(argv[3], "--help") == 0){
        //mostra a função que exibe a ajuda
        exibir_ajuda();
        return 0;
    }

    char resultado[500];
    
    if (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "--manual") == 0){
        //ativa o modo manual
        modo_manual(resultado);
    }
    else if(strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "--file") == 0){
        //ativa o modo do arquivo
        //modo_arquivo(argv[6],resultado);
        printf("\n");
    }
    else{
        printf("Argumento inválido. Use -? ou --help para ver as opções disponíveis.\n");
        return 1;
    }
    return 0;
}
