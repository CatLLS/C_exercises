#include <stdio.h>
#include <string.h>

typedef struct{
    int code;
    char nome[100];
    int idade;
    int gravidade;
}Paciente;

void SelectionSort(Paciente v[],int n){

    for (int i =0 ; i<n-1; i++){
        int max_indx = i;//encontra o "maior" elemento na parte não ordenada(a cada aumento de i, a parte não ordenada diminui, pq j depende de i)

        for(int j =i+1; j<n; j++){//olha todos os elementos depois desse maior, ou seja, analisa apenas a parte da lista não ordenada
            if (v[j].gravidade> v[max_indx].gravidade){//se o elemento atual for maior que o maior já encontrado,
                max_indx = j; //ele será definido como o maior
            }
        }
        //agora, depois de rodar todos os elementos da lista não ordenada e achar o maior deles,
        //vamos trocar o maior elemento com o segundo:
        if (max_indx!= i){
            Paciente temp = v[max_indx];
            v[max_indx] = v[i];
            v[i]= temp;
        }

    }
}


int main(){
    Paciente lista[]={
    {101, "Ana Paula", 45, 85},
    {102, "Carlos Eduardo", 60, 92},
    {103, "Fernanda Lima", 33, 76},
    {104, "João Marcos", 70, 98},
    {105, "Luciana Alves", 55, 88},
    {106, "Bruno Rocha", 40, 69},
    {107, "Marta Silva", 28, 58},
    {108, "Rafael Tavares", 38, 73},
    {109, "Juliana Costa", 49, 91},
    {110, "Roberto Teixeira",65, 94}
    };
    
    SelectionSort(lista,10);

    for(int i=0; i<5;i++){
        printf("\n%d - %s, idade: %d -->Gravidade: %d",lista[i].code, lista[i].nome, lista[i].idade, lista[i].gravidade);
    }
}