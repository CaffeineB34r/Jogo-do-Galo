// Code written by Tomás Lopes in 01/2021

#include "Base.h"

 int main(void)  {
  char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS];
  int espaços=(NUMERO_LINHAS*NUMERO_COLUNAS)-1;
  
  inicRandom();
  apresentarTXT(LOGO);
  inicializarTabuleiro(tabuleiro);

  apresentarTXT(MENU);
  int  jogadorAtual = JogarOpcaoMenu();
  if(jogadorAtual)  {
        
    apresentarTabuleiro(tabuleiro);
      
    do  {
      Jogar(jogadorAtual, tabuleiro);
      apresentarTabuleiro(tabuleiro);
      jogadorAtual *= -1;
    } while(VerVitoria(tabuleiro,&espaços));
  
    
  }else return 0;
}





