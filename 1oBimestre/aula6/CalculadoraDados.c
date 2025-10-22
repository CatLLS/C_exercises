# include <stdio.h>

void preencherLista(int n, float lista[]){
    for(int i=0; i<n; i++){
        printf("\nElemento %f: ", i);
        scanf("%f",&lista[i]);
    }
}

//media
float mediaDados(int n, float lista[]){
    float soma = 0;
    for(int i=0; i<n; i++){
        soma += lista[i];
    }
    return (soma)/n;
}

//variancia

// desvio padrao

// regressao



int main(){
    char sair;

    do{
        printf("\n\n---Calculadora de Análise de dados---\nqual o tamanho da sua base de dados? ");
        int n;
        scanf("%d",&n);
        float x[n],y[n];
        printf("\nDigite a base de dados para X: ");
        preencherLista(n,x);
        printf("\nDigite a base de dados para Y: ");
        preencherLista(n,y);


        printf("Calculadora de Análise de dados"
            "\n1.Calcular Média"
            "\n2.Calcular Variância"
            "\n3.Calcular desvio padrão"
            "\n4.Calcular regressão"
        );

        int choice;
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("\nMédia de X: %.2f, \nMédia de Y: %.2f",mediaDados(n,x)); break;
            
            case 2: break;
            case 3: break;
            case 4: break;

        }


        printf("Encerrar programa?S/N");
        scanf(" %c", &sair);
        getchar();//limpar o enter que o scanf deixa para trás

    }while(sair == 'N' );

}