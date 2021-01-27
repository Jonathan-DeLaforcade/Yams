#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "level.h"
#include "menu.h"
// FONCTION MAINGAME //
/*
  cette fonction gére la loop du jeux pour le passage du lancement du dé pour chaque joueurs
*/

int mainGame() {
  int nbJoueur = getNbPlayer();
  struct joueur players[nbJoueur];

  for (int idx = 1; idx<=nbJoueur; idx++) {
    setPlayer(&players[0],idx);
  }

  return 0;
}

int level() {

  return 0;
}