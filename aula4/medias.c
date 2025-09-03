/*Uma escola deseja criar um sistema de avaliação que calcule a média das notas de um grupo de estudantes
 e determine quais estudantes precisam de recuperação. A média mínima para aprovação é 7.0.
  Se a média for menor que 7.0, o estudante está de recuperação. 

Escreva um programa em C que: 

Peça ao usuário para inserir o número de estudantes.
Use um vetor para armazenar as notas finais de cada estudante.

Crie uma função calcularMediaTurma que recebe o vetor de notas e
 o número de estudantes e retorna a média das notas da turma. 

Crie uma função imprimirResultados que recebe o vetor de notas e 
o número de estudantes, e imprime quais estudantes estão de recuperação e quais estão aprovados.*/

# include <stdio.h>

float calcularMediaTurma(float vetor[], int num){//recebe o vetor de notas e o número de estudantes e retorna a média das notas da turma. 
    float somatoria =0;
    float media;
    for(int j = 0; j< num; j++){
        somatoria += vetor[j];
    }
    media = ((float)somatoria/num);
    return media;
}

void imprimirResultados(float notas[], int num){
    printf("\nComo a média mínima para aprovação é 7.0, os seguintes alunos estão de recuperação:");
    for(int j=0; j<num;j++){
        if (notas[j]<7){
            printf("\nAluno %d", j+1);
        }
    }
}

int main(){
    char encerrar;
    do{
        printf("\nBem vindo ao calculador de Médias, quantos estudantes deseja registrar?");
        int tamanho;
        scanf(" %d", &tamanho);
        float notas[tamanho];
        printf("\nOk, agora insira as notas dos estudantes(float): ");

        for(int i = 0; i<tamanho;i++){
            printf("\n Nota Aluno %d: ", i+1);
            scanf(" %f", &notas[i]);
        }
        float mediaTurma = calcularMediaTurma(notas,tamanho);
        printf("A média das Notas da turma foi de %.2f",mediaTurma);

        imprimirResultados(notas,tamanho);


        printf("\n\nDeseja encerrar o programa?(s/n): ");
        getchar();//limpando o buffer!
        scanf(" %c", &encerrar);
    }while(encerrar != 's');
}