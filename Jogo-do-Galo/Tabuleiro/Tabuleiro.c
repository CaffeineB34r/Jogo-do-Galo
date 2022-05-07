#include "../Tabuleiro/Tabuleiro.h" 
#include <stdio.h>
#include <stdlib.h>

void inicializarTabuleiro(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS]) {
  for(int linhas = 0 ; linhas < NUMERO_LINHAS ; linhas++)  {
    for(int colunas = 0 ; colunas < NUMERO_COLUNAS ; colunas++) {
      tabuleiro[linhas][colunas] = '.';
    } 
  } 
}

void apresentarTabuleiro(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS])  {
  system(LIMPAR_ECRA);        
  printf("\n");

  for(int linhas = 0 ; linhas < NUMERO_LINHAS ; linhas++) {
    for(int colunas = 0 ; colunas < NUMERO_COLUNAS ; colunas++) {
            
      printf(" %c ", tabuleiro[linhas][colunas]); 
      if(colunas < NUMERO_COLUNAS -1)  printf("|");
                    
    }
  
    printf("\n");
  }
}
