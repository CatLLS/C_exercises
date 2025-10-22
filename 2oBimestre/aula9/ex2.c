/*2) Um sistema de seleção de vagas precisa ordenar a idade dos candidatos para priorizar aqueles com mais experiência.
Usando o Insertion Sort, ordene um vetor com as idades de 15 candidatos e exiba o top 5 dos candidatos mais
velhos.*/

#include <stdio.h>

void insertionSort(int n, int v[]){

    for (int i=0; i<n ; i++){//vamos percorrer todos os elementos
        
        int key = v[i];
        int j = i-1;

        while(j>=0 && v[j]>v[key]){//se o j for maior que a chave dessa repetição
            v[j+1] = v[j];
            j = j-1
        }
        v[j+1]= key;

    }
}

int main(){
    int vetor[] = {}

}