#include "Mensagens.h"
#include "../Base.h"

#include <time.h> 
#include <stdlib.h>

void apresentarTXT(char *nomeFicheiro) {
 FILE *fptr;
  
  char c;
  system(LIMPAR_ECRA); 

  fptr = fopen(nomeFicheiro, "r");
    
  do{
    c = fgetc(fptr);
    if (c!= EOF) printf ("%c", c);
  }while (c != EOF);
  
  fclose(fptr);
  
  printf("\n%s\n\n", VERSAO);

  esperarSeg(TEMPO_ESPERA);
}

void esperarSeg(unsigned int seg) {
  
  unsigned int tempoEspera = time(0) + seg;
  
  while(time(0) < tempoEspera);
  
}

void mensagemFinal(void)  {

  apresentarTXT(LOGO);

  printf(MENSAGEM_FINAL);
}

int inicRandom(void)    { 
  long ultime;
  time(&ultime);
  srand((unsigned) ultime);
  return 0;
}