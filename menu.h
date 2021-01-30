#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "joueur.h"
void affichageMainTitle(int clear);
int mainMenu();
int setPlayer(joueur * Player,int index);
int getNbPlayer();
int getNbManche();
void annonceManche(int nbManche,int idxJoueur,int clear);
void annonceLance(int nbLance,int nbManche,int playerIndex,int clear);
void annonceDe(int *tirageTEMP,int *tirageFinal,int nbManche,int playerIndex);
void affichageChoixDice(int *tirageTEMP,int nbManche, int *tirageFinal);
void annonceChoixDe(int nbLaunch);
void passToOtherPlayer(int nbManche,int playerIndex);
void showPlayerGrid(joueur *joueur,int nbManche,int playerIndex);
void showCombinaisons(int resultArray[12],joueur *joueur,int nbManche);
#endif // MENU_H_INCLUDED
