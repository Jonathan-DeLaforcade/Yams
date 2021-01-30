#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "level.h"
#include "menu.h"
#include "joueur.h"
#include "tirage.h"

// FONCTION MAINGAME //
/*
  cette fonction gére la loop du jeux pour le passage du lancement du dé pour chaque joueurs
*/
void result(int tableau[5], int result[6]){
  int as = 0;
  int deux = 0;
  int trois = 0;
  int quatre = 0;
  int cinq = 0;
  int six = 0;
  int normal = 0;
  int paire = 0;
  int brelan = 0;
  int full = 0;
  int littleSuite = 0;
  int bigSuite = 0;
  int carre = 0;
  int yams = 0;
  int combinaisons[12];
  int totalDeTemp[6] = {0,0,0,0,0,0};

  
  for(int pos=0; pos < 5; pos++){
    totalDeTemp[tableau[pos]-1]++;
  }

  int suite=0;
  for(int compteur=0; compteur < 6; compteur ++){

    if (tableau[compteur] == 1){as = 1;}
    if (tableau[compteur] == 2){deux = 1;}
    if (tableau[compteur] == 3){trois = 1;}
    if (tableau[compteur] == 4){quatre = 1;}
    if (tableau[compteur] == 5){cinq = 1;}
    if (tableau[compteur] == 6){six = 1;}

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
  printf("as : %d\n",as);
  printf("deux : %d\n",deux);
  printf("trois : %d\n",trois);
  printf("quatre : %d\n",quatre);
  printf("cinq : %d\n",cinq);
  printf("six : %d\n",cinq);

  printf("brelan : %d\n",brelan);
  printf("littleSuite : %d\n",littleSuite);
  printf("bigSuite : %d\n",bigSuite);
  printf("full : %d\n",full);
  printf("carre : %d\n",carre);
  printf("yams : %d\n",yams);
  */
  result [0] = as;
  result [1] = deux;
  result [2] = trois;
  result [3] = quatre;
  result [4] = cinq;
  result [5] = six;
  result[6] = brelan;
  result[7] = littleSuite;
  result[8] = bigSuite;
  result[9] = full;
  result[10] = carre;
  result[11] = yams;
}

int checkIfGrilleFinish(joueur players[],int nbPlayers,int nbManche) {
  int result = 1;
  for (int idxPlayer = 0;idxPlayer<nbPlayers;idxPlayer++){
    for (int scoreIndex = 0; scoreIndex<16;scoreIndex++){
      if(players[idxPlayer].scores[nbManche][scoreIndex] != 0){
        result = 0;
      }
    }
  }
  return result;
}


int level(joueur *joueur,int nbManche,int nbMancheMax,int playerIndex) {
  int tirageFinal[5] = {0};
  int resultArray[12] = {0};
  lance(tirageFinal,nbManche,playerIndex);
  fillGridChoise(tirageFinal,nbManche,nbMancheMax,playerIndex,joueur);
  result(tirageFinal,resultArray);
  showCombinaisons(resultArray,joueur,nbManche);
  choixCombinaisonAGarder(resultArray,nbManche,joueur);




  //getchar();getchar();
  //passToOtherPlayer(nbManche,playerIndex); 
  return 0; 
}


int mainGame() {
  int nbManche = getNbManche();
  int nbJoueur = getNbPlayer();
  struct joueur players[nbJoueur];

  for (int idx = 0; idx<=nbJoueur-1; idx++) {
    setPlayer(&players[idx],idx);
    for (int i=0;i<nbManche;i++) {
      for (int j=0;j<16;j++){
        players[idx].scores[i][j] = 0;
      }
    }
  }

  for (int mancheEnCours = 0; mancheEnCours<nbManche;mancheEnCours++) {
    int continueLevels = 0;
    do {
      continueLevels = checkIfGrilleFinish(players,nbJoueur,mancheEnCours);
      for (int joueurActuel = 0;joueurActuel<nbJoueur;joueurActuel++){
        annonceManche(mancheEnCours+1,joueurActuel+1,0);
        level(&players[joueurActuel],mancheEnCours,nbManche,joueurActuel);
      }
    } while (continueLevels);
  }

  return 0;
}