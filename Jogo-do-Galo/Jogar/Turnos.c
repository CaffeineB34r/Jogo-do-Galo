#include "../Jogar/Turnos.h"
#include <stdlib.h>
#include <math.h>

void Jogador(int jogadorAtual, char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS]){
  int linha, coluna, opcaovalida;
  
  jogadorAtual = (jogadorAtual > 0) ? 'X':'O';
  printf("\n--> Vez do jogador '%c'\n", jogadorAtual);

  do  { 
    opcaovalida=1;
    linha=1;
    coluna=1;
    
    printf("Selecione 1 linha e 1 coluna: \n"); 
    scanf(" %d %d", &linha, &coluna);
    linha --;
    coluna --;  
    
    if((linha < 0 || linha >= NUMERO_LINHAS || coluna < 0 || coluna >= NUMERO_COLUNAS) || (tabuleiro[linha][coluna] != '.')) {
      printf("Posição ocupada ou inexistente\n\n");
      opcaovalida=0;
    }

  } while (!opcaovalida);

  tabuleiro[linha][coluna] = jogadorAtual;
}

int Teste(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],int *local){

  if      (VerHorizontal(tabuleiro, 1)+NUMERO_COLUNAS+1){ 
    *local=abs(VerHorizontal(tabuleiro, 1));  
    return 1;
  }
  else if (VerVertical(tabuleiro, 1)+NUMERO_LINHAS+1){ 
    *local=abs(VerVertical(tabuleiro, 1));  
    return 2;
  }
  else if (VerDiagonalDec(tabuleiro, 1)){ 
    return 3;
  }
  else if (VerDiagonalCres(tabuleiro, 1)){ 
    return 4;
  }
  else return 0;
}

void JogarComp(int direcao,int local,char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],int jogadorAtual){
  
  if (direcao==1){
    for(int i=0;i<NUMERO_COLUNAS;i++){
     if (tabuleiro[local][i]=='.'){
       tabuleiro[local][i]= jogadorAtual;
       printf("Horizontal");
       return;
      }
    }
  }else if (direcao==2){
    for(int i=0;i<NUMERO_LINHAS;i++){
     if (tabuleiro[i][local]=='.'){
       printf("Vertical");
      tabuleiro[i][local]= jogadorAtual;
      return;
      } 
    }
  }else if (direcao==3){
    for(int i=0;i<NUMERO_COLUNAS;i++){
     if (tabuleiro[i][i]=='.'){
      tabuleiro[i][i]= jogadorAtual;
      printf("Decrescente");
      return;
      }
    }

  }else {for(int i=0;i<NUMERO_COLUNAS;i++){
     if (tabuleiro[i][2-i]=='.'){
      tabuleiro[i][2-i]= jogadorAtual;
       printf("Crescente");
      return;
      }
    }
  }
}


void JogarAleatorio(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],int jogadorAtual){
  
  int espaços=0; 
  
  for(int linhas = 0 ; linhas < NUMERO_LINHAS ; linhas++)  {
    for(int colunas = 0 ; colunas < NUMERO_COLUNAS ; colunas++) {
      if (tabuleiro[linhas][colunas] == '.') espaços ++;
    }
  } 
  
  esperarSeg(1);
  unsigned int numeroPseudoAleatorio = (espaços!=1) ? (rand()%espaços)+1 : 1;

  espaços=0;
  
  for(int linhas = 0 ; linhas < NUMERO_LINHAS ; linhas++)  {
    for(int colunas = 0 ; colunas < NUMERO_COLUNAS ; colunas++) {
      if (tabuleiro[linhas][colunas] == '.') {espaços ++;
        if (espaços == numeroPseudoAleatorio) {
          tabuleiro[linhas][colunas] = jogadorAtual;
          return;
        }
      }
    } 
  } 
}


void Computador(int jogadorAtual, char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS]){
 
  jogadorAtual = (jogadorAtual > 0) ? 'X':'O';
  printf("\n--> Vez do jogador '%c'\n", jogadorAtual);
  esperarSeg(1);

  
  int teste=0,indicador=0;
  teste= Teste(tabuleiro,&indicador);
    printf("Razão da jogada: ");
 
  if (teste) {
    JogarComp(teste,indicador,tabuleiro,jogadorAtual); 
    return;
  }else {
    JogarAleatorio(tabuleiro,jogadorAtual);
    printf("Aleatório");
   
  }
}





