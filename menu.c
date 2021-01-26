#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "joueur.h"
#define bool int
#define true 1
#define false 0

int mainMenu(){ 
    bool stop = false;
    int choix = 0;
    while (stop == false){
      printf("Bienvenue dans le jeu du YAM ! Que voulez-vous faire ? \n");
      printf("1 - Jouer\n");
      printf("2 - Afficher les scores sauvegardes\n");
      printf("3 - Afficher l'aide\n");
      printf("4 - Quitter\n");

      printf("Reponse : ");
      scanf("%d", &choix);

          switch (choix){

              case 1: printf("Jouer\n");
                  break;

              case 2: printf("Afficher les scores sauvergardes\n");
                  break;
              case 3: printf("Aide\n");
                  break;
              case 4: printf("Quitter\n");
                  break;

              default: printf("\nVeuillez choisir une option valide\n");
                  mainMenu();
                  break;
              }
    }
    return choix;
}


int choiceDice(tirageDE,tirageTEMP){
  /*
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
  */
  return 0;
}