#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "tirage.h"
#include "joueur.h"
#include <string.h>

void affichageMainTitle(int clear){
  if (clear){
    printf("\e[1;1H\e[2J"); //Clear du terminal
  }
  printf("+-------------------------------------------------------------+\n");
  printf("|               Bienvenue dans le jeu du YAM !                |\n");
  printf("+-------------------------------------------------------------+\n");
}

int mainMenu(){ // Fonction pour afficher le menu
    int choix = 0;
    affichageMainTitle(1);
    printf("| Que voulez-vous faire ?                                     |\n");
    printf("| 1 - Jouer                                                   |\n");
    printf("| 2 - Afficher les scores sauvegardes                         |\n");
    printf("| 3 - Afficher l'aide                                         |\n");
    printf("| 4 - Quitter                                                 |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("Reponse : ");
    scanf("%d", &choix);

    if ( (choix < 1) || (choix > 4 )){
       mainMenu();
    }
    
    return choix;
}

int setPlayer(joueur * Player, int index){

  Player->pseudo = (char *) malloc(sizeof(char)*15);
  
  if (Player->pseudo == NULL) {
    printf("Echec allocation Player->Pseudo");
    free(Player->pseudo); // Échec réallocation
    return 0;
  }
  affichageMainTitle(1);
  printf("|   Entrez votre pseudo du joueur n° %d (max 15 caracteres)    |\n", index+1);
  printf("+-------------------------------------------------------------+\n");
  printf("Reponse : ");
  scanf("%s", Player->pseudo);

  //strcpy(Player->pseudo,"coucou");
  //printf("%s", Player->pseudo);

  return 0;
}

int getNbPlayer(){
  int nbJoueur;
  affichageMainTitle(1);
  printf("| Combien de joueur etes-vous ?:                              |\n");
  printf("+-------------------------------------------------------------+\n");
  printf("Reponse : ");
  scanf("%d", &nbJoueur);
  return nbJoueur;
};

int getNbManche(){
  int nbManche;
  affichageMainTitle(1);
  printf("| Combien de manche voulez vous jouer ? (entre 1 et 10):      |\n");
  printf("+-------------------------------------------------------------+\n");
  printf("Reponse : ");
  scanf("%d", &nbManche);
  return nbManche;
};

void annonceManche(int nbManche,int idxJoueur,int clear){
  affichageMainTitle(clear);
  char *addSpace = "";
  
  if ((nbManche>9) && (idxJoueur>9)){
    addSpace = "  ";
  } else if(((nbManche<=9) && (idxJoueur>9)) || ((nbManche>9) && (idxJoueur<=9))){
    addSpace = " ";
  }

  printf("|                %s    Manche N%d (joueur N%d)                    |\n",addSpace,nbManche+1,idxJoueur+1);
  printf("+-------------------------------------------------------------+\n");
}

void annonceLance(int nbLance,int nbManche,int playerIndex,int clear){
  annonceManche(nbManche,playerIndex,clear);
  printf("|         Voulez vous effectuer votre lance N%d (y/n)          |\n",nbLance);
  printf("+-------------------------------------------------------------+\n");
  printf("Reponse : ");

}

void annonceDe(int *tirageTEMP,int *tirageFinal,int nbManche,int playerIndex){
  annonceManche(nbManche,playerIndex,1);
  //printf("+-------------------------------------------------------------+\n");
  printf("|                                                             |\n");
  printf("|                    +-------------------+                    |\n");
  printf("|                    |  Selection Finale |                    |\n");
  printf("|                    +---+---+---+---+---+                    |\n");
  printf("|                    | %d | %d | %d | %d | %d |                    |\n",tirageFinal[0],tirageFinal[1],tirageFinal[2],tirageFinal[3],tirageFinal[4]);
  printf("|                    +---+---+---+---+---+                    |\n");
  printf("|                                                             |\n");
  printf("|                                                             |\n");
  printf("|                                                             |\n");
  printf("|                    +-------------------+                    |\n");
  printf("|                    | De actuel (random)|                    |\n");
  printf("|                    +---+---+---+---+---+                    |\n");
  printf("|                    | %d | %d | %d | %d | %d |                    |\n",tirageTEMP[0],tirageTEMP[1],tirageTEMP[2],tirageTEMP[3],tirageTEMP[4]);
  printf("|                    +---+---+---+---+---+                    |\n");
  printf("|                                                             |\n");
  printf("+-------------------------------------------------------------+\n");
}

void annonceChoixDe(int nbLaunch){
  printf("|                   que voulez vous faire ?                   |\n");
  printf("+-------------------------------------------------------------+\n");
  printf("|                     d - Enlever un de                       |\n");
  if (nbLaunch > 1){
    printf("|                     a - ajouter un de                       |\n");
    printf("|                    r - remplacer un de                      |\n");
  }
  printf("|                        q - Quitter                          |\n");
  printf("+-------------------------------------------------------------+\n");
  printf("Reponse :");
}

void passToOtherPlayer(int nbManche,int playerIndex){
  annonceManche(nbManche,playerIndex,0);
  printf("|      Appuyer sur entrer pour passer au joueur suivant       |\n");
  printf("+-------------------------------------------------------------+\n");
}


void showPlayerGrid(joueur *joueur,int nbManche,int playerIndex){
  annonceManche(nbManche,playerIndex,1);
  printf("|                                                             |\n");
  printf("|                    +--------------+---+                     |\n");
  printf("|                    |      AS      | %d |                     |\n",joueur->scores[nbManche][0]);
  printf("|                    |     DEUX     | %d |                     |\n",joueur->scores[nbManche][1]);
  printf("|                    |     TROIS    | %d |                     |\n",joueur->scores[nbManche][2]);
  printf("|                    |    QUATRE    | %d |                     |\n",joueur->scores[nbManche][3]);
  printf("|                    |     CINQ     | %d |                     |\n",joueur->scores[nbManche][4]);
  printf("|                    |      SIX     | %d |                     |\n",joueur->scores[nbManche][5]);
  printf("|                    |     BONUS    | %d |                     |\n",joueur->scores[nbManche][6]);
  printf("|                    +--------------+---+                     |\n");
  printf("|                    |    TOTAL 1   | %d |                     |\n",joueur->scores[nbManche][7]);
  printf("|                    +--------------+---+                     |\n");
  printf("|                    |     BRELAN   | %d |                     |\n",joueur->scores[nbManche][8]);
  printf("|                    | PETITE SUITE | %d |                     |\n",joueur->scores[nbManche][9]);
  printf("|                    | GRANDE SUITE | %d |                     |\n",joueur->scores[nbManche][10]);
  printf("|                    |     FULL     | %d |                     |\n",joueur->scores[nbManche][11]);
  printf("|                    |     CARRE    | %d |                     |\n",joueur->scores[nbManche][12]);
  printf("|                    |      YAM     | %d |                     |\n",joueur->scores[nbManche][13]);
  printf("|                    +--------------+---+                     |\n");
  printf("|                    |    TOTAL 2   | %d |                     |\n",joueur->scores[nbManche][14]);
  printf("|                    +--------------+---+                     |\n");
  printf("|                    |     TOTAL    | %d |                     |\n",joueur->scores[nbManche][15]);
  printf("|                    +--------------+---+                     |\n");
  printf("|                                                             |\n");
  printf("+-------------------------------------------------------------+\n");
}


void showCombinaisons(int resultArray[12],joueur *joueur,int nbManche){
  printf("|       Choisisez la combinaison que vous voulez garder       |\n");
  printf("+-------------------------------------------------------------+\n");
  printf("|                                                             |\n");

  if (resultArray[0] && (joueur->scores[nbManche][0]  == 0)){printf("|                       1 - Tout les 1                        |\n");}
  if (resultArray[1] && (joueur->scores[nbManche][1]  == 0)){printf("|                       2 - Tout les 2                        |\n");}
  if (resultArray[2] && (joueur->scores[nbManche][2]  == 0)){printf("|                       3 - Tout les 3                        |\n");}
  if (resultArray[3] && (joueur->scores[nbManche][3]  == 0)){printf("|                       4 - Tout les 4                        |\n");}
  if (resultArray[4] && (joueur->scores[nbManche][4]  == 0)){printf("|                       5 - Tout les 5                        |\n");}
  if (resultArray[5] && (joueur->scores[nbManche][5]  == 0)){printf("|                       6 - Tout les 6                        |\n");}
  if (resultArray[6] && (joueur->scores[nbManche][8]  == 0)){printf("|                       7 - Brelan                           |\n");}
  if (resultArray[7] && (joueur->scores[nbManche][9]  == 0)){printf("|                       8 - Petite suite                     |\n");}
  if (resultArray[8] && (joueur->scores[nbManche][10]  == 0)){printf("|                      9 - Grande suite                     |\n");}
  if (resultArray[9] && (joueur->scores[nbManche][11]  == 0)){printf("|                      10 - Full                             |\n");}
  if (resultArray[10] && (joueur->scores[nbManche][12]  == 0)){printf("|                      11 - Carre                             |\n");}
  if (resultArray[11] && (joueur->scores[nbManche][13]  == 0)){printf("|                      12 - Yam                               |\n");}
  printf("|                                                             |\n");
  printf("+-------------------------------------------------------------+\n");
  printf("reponse: ");
}