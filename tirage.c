#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tirage.h"
#include "menu.h"
#include <time.h>
#include "joueur.h"
#define bool int
#define False 0
#define True 1

#define MIN 1
#define MAX 6

int randomNumber() {
  return ((rand() % (MAX - MIN + 1)) + MIN);
}

int checkIfTirageFinalIsEmpty(int *tirageFinal){
  bool Result = True;

  for (int i=0;i<5;i++){
    if (tirageFinal[i] != 0){ 
      Result = False; 
    };
  }
  return Result;
}

void tirageDe(int *tirageTEMP) {

  tirageTEMP[0] = randomNumber();
  tirageTEMP[1] = randomNumber();
  tirageTEMP[2] = randomNumber();
  tirageTEMP[3] = randomNumber();
  tirageTEMP[4] = randomNumber();
}

void lance(int *tirageFinal,int nbManche, int playerIndex) {  
  int nblance = 1;
  char playerChoice = 'n';

  do {
    int tirageTEMP[5] = {0};
    if (nblance > 1){
      annonceLance(nblance,nbManche,playerIndex+1,1);
      scanf("\n%c",&playerChoice);
    }
    
    if ((playerChoice == 'y') || (nblance == 1)) {
      tirageDe(tirageTEMP);

      if (checkIfTirageFinalIsEmpty(tirageFinal)){
        for (int i=0;i<5;i++){
          tirageFinal[i] = tirageTEMP[i];
        }
      }
      
      choiceDice(tirageTEMP,tirageFinal,nbManche,playerIndex,nblance);
    }
    nblance++;
  } while (((playerChoice == 'y') && (nblance <= 3)) || (nblance == 2));
}


void choiceDice(int *tirageTEMP,int *tirageFinal,int nbManche,int playerIndex,int nblance){
  char choix = 'q';
  int deAretirer = 0;
  int deToAdd = 0;
  do {


    annonceDe(tirageTEMP,tirageFinal,nbManche,playerIndex);
    annonceChoixDe(nblance);
    scanf("\n%c",&choix);
    switch (choix){
      case 'd':{
        printf("Entrez le numero du de a supprimer : ");
        scanf("%d", &deAretirer);
        retirerDe(deAretirer,tirageFinal);
        break;
      }
      case 'a':{
        if (nblance > 1){
          printf("Entrez le numero du de a ajouter : ");
          scanf("%d", &deToAdd);
          ajouterDe(deToAdd,tirageTEMP ,tirageFinal);
          break;
        }
      }
      case 'r':{
        if (nblance > 1){
          printf("Entrez le numero du de a remplacer ?: ");
          scanf("%d", &deAretirer);
          printf("Entrez le numero du de a garder ?: ");
          scanf("%d", &deToAdd);
          echangerDe(deAretirer,deToAdd,tirageTEMP ,tirageFinal);
          break;
        }
      }
    }
  } while (choix != 'q');
}


void retirerDe(int deARetirer, int *tirageFinal){
  tirageFinal[deARetirer-1] = 0;
}

void ajouterDe(int deToAdd, int *tirageTEMP ,int *tirageFinal){
  for (int idx=0; idx<5; idx++){
    if ((tirageFinal[idx] == 0) && (tirageTEMP[deToAdd-1] != 0)) {
      tirageFinal[idx] = tirageTEMP[deToAdd-1];
      tirageTEMP[deToAdd-1] = 0;
      break;
    }
  }
}

void echangerDe(int deToSupr, int deToAdd, int *tirageTEMP ,int *tirageFinal){
  if ((tirageFinal[deToSupr-1] !=0 ) && (tirageTEMP[deToAdd-1] !=0 )){
    retirerDe(deToSupr,tirageFinal);
    ajouterDe(deToAdd, tirageTEMP, tirageFinal);
  }
}


void fillGridChoise(int *tirageFinal,int nbManche,int nbMancheMax ,int indexJoueur,joueur *joueur){
    showPlayerGrid(joueur,nbManche,indexJoueur);

}

void choixCombinaisonAGarder(int *resultArray,int nbManche,joueur *joueur){
    int choixPlayer;
    scanf("%d",&choixPlayer);

    if ((choixPlayer == 0) && resultArray[0] && (joueur->scores[nbManche][0]  == 0)){}
    if ((choixPlayer == 0) && resultArray[1] && (joueur->scores[nbManche][1]  == 0)){}
    if ((choixPlayer == 0) && resultArray[2] && (joueur->scores[nbManche][2]  == 0)){}
    if ((choixPlayer == 0) && resultArray[3] && (joueur->scores[nbManche][3]  == 0)){}
    if ((choixPlayer == 0) && resultArray[4] && (joueur->scores[nbManche][4]  == 0)){}
    if ((choixPlayer == 0) && resultArray[5] && (joueur->scores[nbManche][5]  == 0)){}
    if ((choixPlayer == 0) && resultArray[6] && (joueur->scores[nbManche][8]  == 0)){}
    if ((choixPlayer == 0) && resultArray[7] && (joueur->scores[nbManche][9]  == 0)){}
    if ((choixPlayer == 0) && resultArray[8] && (joueur->scores[nbManche][10]  == 0)){}
    if ((choixPlayer == 0) && resultArray[9] && (joueur->scores[nbManche][11]  == 0)){}
    if ((choixPlayer == 0) && resultArray[10] && (joueur->scores[nbManche][12]  == 0)){}
    if ((choixPlayer == 0) && resultArray[11] && (joueur->scores[nbManche][13]  == 0)){}
};