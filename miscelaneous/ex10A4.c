#include <stdio.h>

float calcularMediaAvaliacoes(float aval[],int n){
    float sum=0;
    for(int a=0;a<n;a++){
        sum += aval[a];
    }
    return sum/n;
}


void imprimirFilmesBemAvaliados(char filmes[][10]/*??? what if I wanted the film string to be longer when reusing this function in another code?*/,
                                float aval[],
                                int n){
    float media= calcularMediaAvaliacoes(aval,n);
    printf("\nOs filmes mais bem avaliados foram:\n");
    for (int a = 0; a<n; a++){
        if(aval[a]>media){
            printf("Filme: %s, Nota: %f \n", filmes[a], aval[a]);
        }
    }
}

void categorizarFilmesPorGenero(){}


int main(){
   char encerrar;
   do{
       printf("\nCinema X, o programa, Quantos filmes deseja cadastrar?");
       int n;
       scanf("%d",&n);
       char filmes[n][10];//matriz, pq strings são listas, N é o número de strings, e 10 o tamanho de cada uma
       float aval[n];
       char gen[n];
       
       
       
       printf("\nMuito bem, vamos registrar os %d filmes agora:",n); 
       for (int i=0; i<n;i++){
           getchar();
           printf("\n\nNome do Filme: ");
           fgets(filmes[i], 10, stdin);//max 10 letras por filme
           //scanf("%c",&filmes[i]);

           
           printf("\n Avaliação: ");
           scanf("%f",&aval[i]);
           getchar();

           printf("Gênero: ");
           scanf("%c",&gen[i]);    
           getchar();       
           
       }      
       
       printf("\nO que deseja fazer com este catálogo? \n1:Calcular média das avaliações\n2: Imprimir filmes bem avaliados\n3: Categorizar Filmes Por Genero\nresposta: ");
       int escolha;
       scanf("%d",&escolha);
       switch(escolha){
           case 1: 
               float result = calcularMediaAvaliacoes(aval,n);
               printf("O resultado da média é: %f", result);
               break;//done

           case 2: imprimirFilmesBemAvaliados(filmes,aval,n);break;//done

           case 3: categorizarFilmesPorGenero(filmes,gen,n);break;
       }
       
              
       printf("\nDeseja encerrar o programa?(s/n) ");
       getchar();
       scanf("%c",&encerrar);
   }while(encerrar != 's');
}