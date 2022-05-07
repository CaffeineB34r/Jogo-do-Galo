#ifndef MENSAGEM_H
#define MENSAGEM_H

#define MENU "Jogo-do-Galo/IO/Txts/menu.txt"
#define LOGO "Jogo-do-Galo/IO/Txts/logo.txt"

#define TITULO "\nSeja Bem-vindo ao Jogo do Galo"
#define VERSAO "Versão 1.00"
#define MENSAGEM_FINAL "Até breve!!"


void apresentarTXT(char *nomeFicheiro);
void mensagemFinal(void);
void esperarSeg(unsigned int seg);
int inicRandom(void);

#endif 