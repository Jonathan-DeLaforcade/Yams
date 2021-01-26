#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int mainMenu(){

    int choix = 0;
    printf("Bienvenue dans le jeu du YAM ! Que voulez-vous faire ? \n");
    printf("1 - Jouer\n");
    printf("2 - Afficher les scores sauvergardes\n");
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
                menu();
                break;
            }
    return 0;
}


int choiceDice(){

  return 0;
}