#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <string.h>

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
    printf("d - Choisir un dé à enlever\n");
    printf("a - Choisir un dé à ajouter\n");
    printf("q - Quitter\n");
    printf("==> ");
    scanf("\n%c",&choix);
  } while (choix != 'q');
  */
  return 0;
}

int setPlayer(joueur * Player, int index){

  Player->pseudo = (char *) malloc(sizeof(char)*15);
  
  if (Player->pseudo == NULL) {
    printf("Echec allocation Player->Pseudo");
    free(Player->pseudo); // Échec réallocation
    return 0;
  }
  
  printf("Entrez votre pseudo du joueur n° %d (max 15 caracteres):", index+1);
  scanf("%s", Player->pseudo);

  //strcpy(Player->pseudo,"coucou");
  //printf("%s", Player->pseudo);

  return 0;
}

int getNbPlayer(){
  int nbJoueur;
  printf("Combien de joueur etes-vous ?: ");
  scanf("%d", &nbJoueur);
  return nbJoueur;
};

int getNbManche(){
  int nbManche;
  printf("Combien de manche voulez vous jouer ? (entre 1 et 10): ");
  scanf("%d", &nbManche);
  return nbManche;
};