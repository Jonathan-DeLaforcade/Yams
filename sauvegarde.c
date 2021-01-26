
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sauvegarde.h"
#include "joueur.h"

#define MAXPSEUDOSIZE 10

//FILE* sauvegarde = fopen("/home/runner/Yams/sauvegarde.txt", "a+");
void sauvegarde(){
  
  joueur j1;
  j1.pseudo = (char *) malloc(sizeof(char) * MAXPSEUDOSIZE);
  strcpy(j1.pseudo, "Jonathan");
  j1.score = 1;
  joueur j2;

  FILE* sauvegarde = fopen("sauvegarde.txt","a+");
  /*
  fwrite(j1.pseudo,sizeof(j1.pseudo),1,sauvegarde);  
  fwrite(":",sizeof(":"),1,sauvegarde); 
  fwrite(&j1.score,sizeof(j1.score),1,sauvegarde); 
  fwrite("\n",sizeof("\n"),1,sauvegarde); 


  fwrite(j1.pseudo,sizeof(j1.pseudo),1,sauvegarde);  
  fwrite(":",sizeof(":"),1,sauvegarde); 
  fwrite(&j1.score,sizeof(j1.score),1,sauvegarde); 
  fwrite("\n",sizeof("\n"),1,sauvegarde); 
  */


  joueur joueurTemp;
    fseek(sauvegarde, 0, SEEK_SET);
    fread(&joueurTemp, sizeof(joueur),1, sauvegarde);
    char phrase[50];
    while(fread(phrase, sizeof(phrase), 1, sauvegarde) != 0) {
      printf("Nom : \n");
    }

  fclose(sauvegarde);

}