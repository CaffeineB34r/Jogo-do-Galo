#ifndef TURNOS_H
#define TURNOS_H

#include "../Base.h"

int VerHorizontal(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],unsigned int diferenca);
int VerVertical(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],unsigned int diferenca);
int VerDiagonalDec(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],unsigned int diferenca);
int VerDiagonalCres(char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS],unsigned int diferenca);


void Jogador(int jogadorAtual, char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS]);

void Computador(int jogadorAtual, char tabuleiro[NUMERO_LINHAS][NUMERO_COLUNAS]);

#endif