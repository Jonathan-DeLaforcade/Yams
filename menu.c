#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "joueur.h"

int mainMenu(){ // Fonction pour afficher le menu
    int choix = 0;
    printf("Bienvenue dans le jeu du YAM ! Que voulez-vous faire ? \n");
    printf("1 - Jouer\n");
    printf("2 - Afficher les scores sauvegardes\n");
    printf("3 - Afficher l'aide\n");
    printf("4 - Quitter\n");

    printf("Reponse : ");
    scanf("%d", &choix);

    if ( (choix < 1) || (choix > 4 )){
            mainMenu();
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

int setPlayer(joueur * Player){

  //printf("Entrez votre pseudo :");
  //scanf("%s", Player->pseudo);

  //printf("%s", Player->pseudo);

  return 0;
}







