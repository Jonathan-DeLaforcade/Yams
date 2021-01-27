#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include "tirage.h"
#include "menu.h"
#include "level.h"
//#include "sauvegarde.h"

int main() {
  srand(time(NULL));

  // GESTION DU MENU PRINCIPAL //
  /* 
    permet de choisir si l'on veux jouer, afficher les scores, etc
    Appel la fonction mainMenu() qui permet d'afficher les choix et de retourner la valeur choisi par l'utilisateur.

    1: jouer
    2: Afficher les scores
    3: Afficher l'aide
    4: Quitter
  */
  int gameChoice = mainMenu();
  switch(gameChoice) {
    case 1: { mainGame(); break;}
    case 2: { /*showScores();*/ break;}
    case 3: { /*showHelp();*/ break;}
    case 4: {break;}
    default: {/*main();*/ break;}
  }

    //sauvegarde();
    //lance();
    return 0;
}