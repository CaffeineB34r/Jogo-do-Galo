#include "../Jogar/Jogadas.h"
#include "../Jogar/Turnos.h"
 

//função para a verificação da Horizontal

  int VerHorizontal(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],unsigned int diferenca){
    int linha, coluna, contador,a=0;
   
    for(linha = 0 ; linha < NUMERO_LINHAS ; linha++)  {
      contador = 0;
      for(coluna = 0 ; coluna < NUMERO_COLUNAS ; coluna++){

      
        if(tabuleiro[linha][coluna] == 'X')  contador ++;
      
        else if(tabuleiro[linha][coluna] == 'O')  contador --;
        
      }
      a = (diferenca==0) ? NUMERO_LINHAS :NUMERO_LINHAS-diferenca;
      
      if(contador == a) return linha;

      else if(contador == -a) return -linha;
    }
    return -(NUMERO_COLUNAS+1);
  }
//função para a verificação da Vertical
  int VerVertical(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],unsigned int diferenca){
    int linha, coluna, contador,a=0;

    for(coluna = 0 ; coluna < NUMERO_COLUNAS ; coluna++) {
      contador = 0;
      for(linha = 0 ; linha < NUMERO_LINHAS ; linha++) {
      
        if(tabuleiro[linha][coluna] == 'X') contador ++;
        
        else if(tabuleiro[linha][coluna] == 'O')  contador --;
      }
      a =NUMERO_LINHAS-diferenca;

      if(contador == a) return coluna;

      else if(contador == -a) return -coluna;
    }
    return -(NUMERO_LINHAS+1);
  }
//função para a verificação da diagonal decrescente
  int VerDiagonalDec(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],unsigned int diferenca){
    int contador=0,a=0;

    for(int coluna = 0 ; coluna < NUMERO_COLUNAS ; coluna++) {
    
      if(tabuleiro[coluna][coluna] == 'X') contador ++;
      else if(tabuleiro[coluna][coluna] == 'O')  contador--;
  
    }
    a =NUMERO_LINHAS-diferenca;

    if(contador == a) return 1;
   else if(contador == -a) return -1;

    return 0;
  }
//função para a verificação da diagonal crescente
  int VerDiagonalCres(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],unsigned int diferenca){
    int contador=0,a=0;

    for(int coluna = 0 ; coluna < NUMERO_COLUNAS ; coluna++) {
      if(tabuleiro[coluna][2 - coluna] == 'X') contador ++;
    
      else if(tabuleiro[coluna][2 - coluna] == 'O') contador --;
    }
   
    a =NUMERO_LINHAS-diferenca;

    if(contador == a) return 1;
    else if(contador == -a) return -1;
  return 0;
  }
//

//esta função chama as verificações das direções necessárias
int Vencedor(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS])  {
  int contador=0;
  int  linhas=NUMERO_LINHAS;
  int colunas=NUMERO_COLUNAS;

  contador = VerHorizontal(tabuleiro,0); 
  
  if (contador+colunas+1) return contador;

  
  contador = VerVertical(tabuleiro,0);
  if (contador+linhas+1) return contador;
  
  if (linhas==colunas) {
  
    contador = VerDiagonalDec(tabuleiro,0);
    if (contador) return contador;

    contador = VerDiagonalCres(tabuleiro,0);
    if (contador) return contador;
  
  }
  return 0;
}

int VerVitoria(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],int *espaços){
  char ganho;
  
  int vencedor=Vencedor(tabuleiro);

  if(vencedor){   
    ganho = (vencedor == 1) ?  'X' : 'O' ;
    printf("\n\n--> VENCEDOR: '%c'\n\n", ganho); 
  
    return 0;
  
  }else if (*espaços==0){
    printf("\n\n--> EMPATE  \n\n");

    return 0;
  
  }else{
    
    *espaços= *espaços -1;
    return 1;
  }
}
