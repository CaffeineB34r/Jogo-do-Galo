#ifndef FAZER_JOGADAS_H
#define FAZER_JOGADAS_H

#include "../Base.h"

int JogarOpcaoMenu();

void Jogar(int jogadorAtual, char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS]);

int VerVitoria(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],int *espaços);

#endif