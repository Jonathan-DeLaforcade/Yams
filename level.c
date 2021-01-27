#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "level.h"
#include "menu.h"
#include "joueur.h"
// FONCTION MAINGAME //
/*
  cette fonction gére la loop du jeux pour le passage du lancement du dé pour chaque joueurs
*/
void result(int tableau[5], int result[6]){
  int normal=0;
  int paire=0;
  int brelan=0;
  int full=0;
  int littleSuite = 0;
  int bigSuite = 0;
  int carre = 0;
  int yams = 0;
  int combinaisons[6];
  int totalDeTemp[6] = {0,0,0,0,0,0};
  
  
  
  for(int pos=0; pos < 5; pos++){
    totalDeTemp[tableau[pos]-1]++;
  }

  int suite=0;
  for(int compteur=0; compteur < 6; compteur ++){

    if (totalDeTemp[compteur] == 1){
      suite++;
    } else if ((totalDeTemp[compteur] == 0) && (suite < 5)) {
      suite = 0;
    }
    
    if (totalDeTemp[compteur] == 1){

      normal++;
      
      
    }
    
    else if (totalDeTemp[compteur] == 2){

      paire = 1;
    }

    else if (totalDeTemp[compteur] == 3){
      brelan = 1;
    }
    
    else if (totalDeTemp[compteur] == 4){
      carre = 1;
    }
    
    else if (totalDeTemp[compteur] == 5){
      yams = 1;
    }
    
    if ((paire == 1) && (brelan == 1)){

      full = 1;
    }
  }

  if (suite == 5) {
    if (totalDeTemp[0] == 0) {
      bigSuite = 1;
    } else {
      littleSuite = 1;
    }
  }
  /*
  printf("brelan : %d\n",brelan);
  printf("littleSuite : %d\n",littleSuite);
  printf("bigSuite : %d\n",bigSuite);
  printf("full : %d\n",full);
  printf("carre : %d\n",carre);
  printf("yams : %d\n",yams);
  */
  result[0] = brelan;
  result[1] = littleSuite;
  result[2] = bigSuite;
  result[3] = full;
  result[4] = carre;
  result[5] = yams;
}

int mainGame() {
  int nbManche = getNbManche();
  int nbJoueur = getNbPlayer();
  struct joueur players[nbJoueur];

  for (int idx = 0; idx<=nbJoueur-1; idx++) {
    setPlayer(&players[idx],idx);
  }

  for (int mancheEnCours = 0; mancheEnCours<nbManche;mancheEnCours++) {
    printf("==> Manche N°%d <==\n",mancheEnCours+1);
    for (int joueurActuel = 0;joueurActuel<nbJoueur;joueurActuel++){
      printf("%d - %s\n",joueurActuel,(players[joueurActuel]).pseudo);
      //level(&players[joueurActuel],joueurActuel);
    }
  }

  return 0;
}

int level(joueur *joueur, int playerIndex) {
  printf("====> Joueur %d, %s c'est a vous de jouer <====\n",playerIndex+1,joueur->pseudo);
  return 0;
}