/*implementar função em C que calcula o traço de uma matriz quadrada
O traço da matriz é a soma dos elementos presentes em sua diagonal principal*/


#include <stdio.h>

void imprimirMatriz(int lm, int cm, int m[lm][cm]){
    for(int i =0; i<lm; i++){
        for(int j= 0; j<cm; j++){
            printf(" %d", m[i][j]);
        }

        printf("\n");
    }
}

int calcularTraco(int lm, int cm, int m[lm][cm]){
    int traco = 0;
    /*
    for (int i = 0; i< lm; i++){
        for (int j=0; j< cm; j++){
            if (i==j){
                traco += m[i][j];
            }

        }
    }
    ou, otimizando:
    */
   for (int i = 0; i< lm; i++){
        traco += m[i][i];
     }
    
    return traco;
}

int main(){

    printf("\nCalculador de traço da matriz\nDigite o tamanho da matriz(x:y): ");
    int line, col;
    scanf("%d:%d", &line, &col);
    while(line != col){
        printf("A matriz inserida não é quadrada, tente novamente: ");
        scanf("%d:%d", &line, &col);
    }
    int matriz[line][col];

    for (int i = 0; i<line; i++){
        for(int j=0; j<col; j++){
            printf("\n->Elemento %d%d: ", i, j);
            scanf("%d", &matriz[i][j] );

        }
    }
    imprimirMatriz(line, col, matriz);

    int traco = calcularTraco(line, col, matriz);

    printf("\nO traço da matriz é %d.\n", traco);

}