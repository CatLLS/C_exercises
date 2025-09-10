void multiplicarMatrizes(int la,int ca, int ma[la][ca], int lb, int cb, int[lb][cb], int mc[la][cb]){

    if(ca != lb){return;}//não pode!!!

    for(int linha = 0; linha<la; linha ++){
        for(int col = 0; col<cb; col++){

            int soma = 0;

            for(int j=0; j< lb; j++){
                soma += ma[linha][j]*mb[j][col];
            }
        }
    }


}