#ifndef TIRAGE
#define TIRAGE
#include "joueur.h"

int randomNumber();
void tirageDe(int *tirageTEMP);
void lance(int *tirageFinal,int nbManche, int playerIndex);
int checkIfTirageFinalIsEmpty(int *tirageFinal);
void retirerDe(int deARetirer, int *tirageFinal);
void ajouterDe(int deToAdd, int *tirageTEMP ,int *tirageFinal);
void echangerDe(int deToSupr, int deToAdd, int *tirageTEMP ,int *tirageFinal);
void choiceDice(int *tirageTEMP,int *tirageFinal,int nbManche,int playerIndex,int nblance);
void fillGridChoise(int *tirageFinal,int nbManche,int nbMancheMax ,int indexJoueur, joueur *joueur);
void choixCombinaisonAGarder(int *resultArray,int nbManche,joueur *joueur);
#endif