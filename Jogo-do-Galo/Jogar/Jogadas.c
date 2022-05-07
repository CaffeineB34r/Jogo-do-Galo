#include "../Jogar/Jogadas.h"
#include "../Jogar/Turnos.h"

#include <stdlib.h> 
#include <math.h>

int EscolherJogador(void){
  int escolha;
  system(LIMPAR_ECRA);
  printf("Quer ser jogador 1 ou jogador 2?");
  scanf("%d", &escolha);
  
  int a=((escolha%2)+1==2)? 2:-2;
  return a;
  
} 


int JogarOpcaoMenu(void)  { 
  char op;

  printf("Opção:");
  scanf(" %c", &op);

  switch(op) {
    case 'J':
    case 'j':{
      system(LIMPAR_ECRA);
      printf("Jogador vs Jogador\n"); 
      esperarSeg(TEMPO_ESPERA);
      system(LIMPAR_ECRA);
      return 1;
    } 
    case 'C':
    case 'c': {
      system(LIMPAR_ECRA);
      printf("Jogador vs Computador\n"); 
      esperarSeg(TEMPO_ESPERA); 
      system(LIMPAR_ECRA);
      return EscolherJogador();
    }
    case 'X':
    case 'x': {
      system(LIMPAR_ECRA);
      printf("Computador vs Computador\n"); 
      esperarSeg(TEMPO_ESPERA); 
      system(LIMPAR_ECRA);
      return 3;
    }
    case 'S': 
    case 's': {
      system(LIMPAR_ECRA);
      esperarSeg(TEMPO_ESPERA);
      mensagemFinal();
      return 0;
    }

    default: {
      system(LIMPAR_ECRA); 
      printf("Opção inválida\n"); 
      esperarSeg(TEMPO_ESPERA); 
      return 0;
    }
  }  
  return 1;
}



void Jogar(int jogadorAtual, char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS]) {
  
  if (abs(jogadorAtual)==1) Jogador(jogadorAtual,tabuleiro);
  else if (abs(jogadorAtual)==3) Computador(jogadorAtual,tabuleiro);
  
  else if (abs(jogadorAtual)==2) {
    if (jogadorAtual>0) Jogador(jogadorAtual,tabuleiro);
    else Computador(jogadorAtual,tabuleiro);
  }

}

