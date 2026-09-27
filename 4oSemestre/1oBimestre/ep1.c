/******************************************************************************
 * EP1: Mochila Inteira
 * Disciplina: Projeto e Análise de Algoritmos II
 * Professor: Antonio Luiz Basile
 * Aluno: Catarina Silva e Meirelles, 10239324
 ******************************************************************************/
//colocar entrada no in.txt na pasta do projeto,
//formato esperado:
//Primeira linha: A capacidade máxima da mochila (ex: 50).
//Linhas seguintes: O nome do objeto (sem espaços), seguido do peso (inteiro) e do valor (inteiro).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJETOS 100
#define MAX_NOME 50

// Estrutura para representar um Objeto
typedef struct {
    char nome[MAX_NOME];
    int peso;
    int valor;
} Objeto;

// -----------------------------------------------------------------------------
// 1. ALGORITMO DE PROGRAMAÇÃO DINÂMICA
// -----------------------------------------------------------------------------
void mochilaDinamica(Objeto objs[], int n, int capacidade, unsigned long long *passos) {
    *passos = 0;
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((capacidade + 1) * sizeof(int));
    }

    (*passos)++;

    // Preenchendo a tabela bottom-up
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacidade; w++) {
            (*passos)++; // Incremento por iteração dos loops
            
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (objs[i - 1].peso <= w) {
                int incluindo = objs[i - 1].valor + dp[i - 1][w - objs[i - 1].peso];
                int excluindo = dp[i - 1][w];
                if (incluindo > excluindo) {
                    dp[i][w] = incluindo;
                } else {
                    dp[i][w] = excluindo;
                }
                (*passos)++; // Operações de comparação/atribuição
            } else {
                dp[i][w] = dp[i - 1][w];
                (*passos)++;
            }
        }
    }

    // Recuperando o valor máximo e os objetos escolhidos
    int res = dp[n][capacidade];
    int w = capacidade;
    int escolhidos[MAX_OBJETOS];
    int qtdEscolhidos = 0;

    for (int i = n; i > 0 && res > 0; i--) {
        (*passos)++;
        if (res != dp[i - 1][w]) {
            escolhidos[qtdEscolhidos++] = i - 1;
            res -= objs[i - 1].valor;
            w -= objs[i - 1].peso;
        }
    }

    // Exibição dos resultados da Programação Dinâmica
    printf("\n--- RESULTADO: PROGRAMACAO DINAMICA ---\n");
    printf("Valor Maximo Total: %d\n", dp[n][capacidade]);
    printf("Objetos Escolhidos:\n");
    int pesoTotal = 0;
    for (int i = qtdEscolhidos - 1; i >= 0; i--) {
        int idx = escolhidos[i];
        printf("- %s (Peso: %d, Valor: %d)\n", objs[idx].nome, objs[idx].peso, objs[idx].valor);
        pesoTotal += objs[idx].peso;
    }
    printf("Peso Total na Mochila: %d / %s\n", pesoTotal, (pesoTotal <= capacidade) ? "OK" : "EXCEDIDO");
    printf("Numero de passos (Dinamica): %llu\n", *passos);

    // Liberando memória da tabela
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
}

// -----------------------------------------------------------------------------
// 2. ALGORITMO INGÊNUO (Força Bruta / Combinação de todos contra todos)
// -----------------------------------------------------------------------------
void mochilaIngenua(Objeto objs[], int n, int capacidade, unsigned long long *passos) {
    *passos = 0;
    int totalCombinacoes = 1 << n; // 2^n subconjuntos possíveis
    int melhorValor = -1;
    int melhorMascara = 0;

    for (int i = 0; i < totalCombinacoes; i++) {
        int pesoAtual = 0;
        int valorAtual = 0;
        (*passos)++; // Passo do loop principal

        for (int j = 0; j < n; j++) {
            (*passos)++; // Passo do loop interno
            if ((i >> j) & 1) { // Se o j-ésimo objeto está no subconjunto
                pesoAtual += objs[j].peso;
                valorAtual += objs[j].valor;
            }
        }

        // Verifica se o peso cabe na mochila e se o valor é o melhor até agora
        if (pesoAtual <= capacidade && valorAtual > melhorValor) {
            melhorValor = valorAtual;
            melhorMascara = i;
        }
        (*passos)++; // Passo de comparação de viabilidade e valor
    }

    // Exibição dos resultados do Algoritmo Ingênuo
    printf("\n--- RESULTADO: ALGORITMO INGENUO (FORCA BRUTA) ---\n");
    if (melhorValor == -1) {
        printf("Nenhum objeto cabe na mochila.\n");
    } else {
        printf("Valor Maximo Total: %d\n", melhorValor);
        printf("Objetos Escolhidos:\n");
        int pesoTotal = 0;
        for (int j = 0; j < n; j++) {
            if ((melhorMascara >> j) & 1) {
                printf("- %s (Peso: %d, Valor: %d)\n", objs[j].nome, objs[j].peso, objs[j].valor);
                pesoTotal += objs[j].peso;
            }
        }
        printf("Peso Total na Mochila: %d / %d\n", pesoTotal, capacidade);
    }
    printf("Numero de passos (Ingenuo): %llu\n", *passos);
}

int main() {
    FILE *file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo 'in.txt'. Certifique-se de que ele existe.\n");
        return 1;
    }

    int capacidade;
    if (fscanf(file, "%d", &capacidade) != 1) {
        printf("Erro ao ler a capacidade da mochila no arquivo.\n");
        fclose(file);
        return 1;
    }

    Objeto objs[MAX_OBJETOS];
    int n = 0;

    // Lendo os objetos do arquivo: nome, peso, valor
    while (n < MAX_OBJETOS && fscanf(file, "%s %d %d", objs[n].nome, &objs[n].peso, &objs[n].valor) == 3) {
        n++;
    }
    fclose(file);

    if (n == 0) {
        printf("Nenhum objeto encontrado no arquivo 'in.txt'.\n");
        return 1;
    }

    printf("=== DADOS CARREGADOS ===\n");
    printf("Capacidade da Mochila: %d\n", capacidade);
    printf("Total de Objetos: %d\n", n);

    unsigned long long passosDinamica = 0;
    unsigned long long passosIngenuo = 0;

    // Executa Programação Dinâmica
    mochilaDinamica(objs, n, capacidade, &passosDinamica);

    // Executa Algoritmo Ingênuo (Atenção: Para n > 25 ou 30, o ingênuo pode demorar muito devido à complexidade O(2^n))
    if (n > 25) {
        ("\n[AVISO] O numero de objetos e grande (%d). O algoritmo ingenuo (O(2^n)) pode demorar muito para rodar.\n", n);
    }
    mochilaIngenua(objs, n, capacidade, &passosIngenuo);

    // Comparativo Final
    printf("\n========================================\n");
    printf("         COMPARATIVO DE PASSOS          \n");
    printf("========================================\n");
    printf("Programacao Dinamica: %llu passos\n", passosDinamica);
    printf("Algoritmo Ingenuo   : %llu passos\n", passosIngenuo);
    printf("========================================\n");

    return 0;
}