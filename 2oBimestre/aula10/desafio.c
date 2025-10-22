#include <stdio.h>
#include <string.h>
#include <stdbool.h> // booleanos
#include <ctype.h>// toupper()

//checar se i = tamanho-i para cada letra até chegar no meio
// ou ir guardando em um char e no fim comparar se é igual
/*1234
1e4
2e3 
3e2->caso base, retorna igual*/

bool is_palindrome(char str[], int inicio, int fim){
 //printf("\nrun %d: <%c> X <%c>", inicio+1 ,str[inicio], str[fim-1]);
    
   if (inicio >= fim){//caso base
        return true;
   }
   if(str[inicio] == ' '){inicio ++;}
   if(str[fim-1]== ' '){fim--;}
   printf("\nrun %d: <%c> X <%c>", inicio+1 ,str[inicio], str[fim-1]);

   if (toupper(str[inicio])== toupper(str[fim-1])){
        return is_palindrome(str, inicio+1, fim-1);
   }
   return false;
    
}

int main(){
    char palavra[100];
    fgets(palavra, 100, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    printf("%ld",strlen(palavra));

    printf("\n%d\n",is_palindrome(palavra,0,(strlen(palavra)) ));
}