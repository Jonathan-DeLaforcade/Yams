#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tirage.h"
#include <time.h>

#define MIN 1
#define MAX 6

int randomNumber() {
  return ((rand() % (MAX - MIN + 1)) + MIN);
}

Tirage tirageDe() {
  Tirage tirage;
  tirage.de1 = randomNumber();
  tirage.de2 = randomNumber();
  tirage.de3 = randomNumber();
  tirage.de4 = randomNumber();
  tirage.de5 = randomNumber();
  return tirage;
}

void lance() {  
  int nblance = 1;
  char playerChoice = 'n';
  Tirage tirageFinal;
  tirageFinal.de1 = 0;
  tirageFinal.de2 = 0;
  tirageFinal.de3 = 0;
  tirageFinal.de4 = 0;
  tirageFinal.de5 = 0;

  do {
    Tirage tirageTEMP;

    printf("voulez vous effectué votre lancer numero %d (y/n) ?\n",nblance);
    scanf("\n%c",&playerChoice);
    if (playerChoice == 'y') {
      tirageTEMP = tirageDe();
      printf("Resultat tirage:\n");

      //choixDe(&tirageTEMP,&tirageFinal);

      nblance++;
    }
  } while ((playerChoice == 'y') && (nblance <= 3));
}