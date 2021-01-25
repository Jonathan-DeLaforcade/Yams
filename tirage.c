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

void choixDe(Tirage *tirageTEMP, Tirage *tirageDE) {

  printf("+---+---+---+---+---+\n");
  printf("| %d | %d | %d | %d | %d |\n",tirageDE->de1,tirageDE->de2,tirageDE->de3,tirageDE->de4,tirageDE->de5);
  printf("+---+---+---+---+---+\n\n\n");

  printf("+---+---+---+---+---+\n");
  printf("| %d | %d | %d | %d | %d |\n",tirageTEMP->de1,tirageTEMP->de2,tirageTEMP->de3,tirageTEMP->de4,tirageTEMP->de5);
  printf("+---+---+---+---+---+\n\n\n");

  char choix = 'q';
  do {
    printf("que voulez vous faire ?\n");
    printf("a - Choisir un dé à enlever\n");
    printf("d - Choisir un dé à ajouter\n");
    printf("q - Quitter\n");
    printf("==> ");
    scanf("\n%c",&choix);
  } while (choix != 'q');
};

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

      choixDe(&tirageTEMP,&tirageFinal);

      nblance++;
    }
  } while ((playerChoice == 'y') && (nblance <= 3));
}