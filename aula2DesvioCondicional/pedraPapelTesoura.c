//simular o jogo pedra papel tesoura
//usuario escolhe 1 opção (1,2,3)
//o computador escolhe aleatóriamente uma das 3 opções
//programa define vencedor ou empate
//Jogador ganha quando:
//j pedra - c tesoura 
// j tesoura - c papel 
// j papel - c pedra
// em qualquer outro caso, o jogador perde!

#include <stdio.h>//para printar/entrar
#include <stdlib.h>//para usar rand()
#include <time.h>//para variar a semente do rand

int main(){
    // começando o jogo
    int jogada;
    srand(time(NULL));//criando o número aleatório
    int jogadaComputador = rand() %3 +1 ; // associando o número aleatório à variável, o mod 3 é para ser algo de 0 a 2 e aí a gnt soma 1 para ficar de 1 a 3!
    printf("Jogo de Pedra Papel Tesoura! \nQual você vai jogar?(1=pedra, 2= tesoura, 3= papel): ");
    scanf("%d", &jogada);

    char Sjogada[10];
    char SjogadaComputador[10];

    if (jogada == jogadaComputador) { printf("Empate!");}
    else if ((jogada == 1 && jogadaComputador == 2)||(jogada == 2 && jogadaComputador == 3)||(jogada == 3 && jogadaComputador == 1)){
        printf("Você Ganhou!\n");
    }
    else{printf("Você Perdeu!\n");}

    //switch(jogada){
    //    case 1 : Sjogada = "Pedra"; break;
    //    case 2: Sjogada = "Tesoura"; break;
    //    case 3: Sjogada = "Papel"; break;}

    //switch(jogadaComputador){
    //    case 1 : SjogadaComputador = "Pedra"; break;
   //     case 2: SjogadaComputador = "Tesoura"; break;
    //    case 3: SjogadaComputador = "Papel"; break;}
    
    printf(" Pois você jogou %d e o seu oponente %d\n", jogada, jogadaComputador);


    return 0;
}