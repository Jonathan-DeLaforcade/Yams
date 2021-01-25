#ifndef SAUVEGARDE
#define SAUVEGARDE

struct joueur {
  char* pseudo;
  int score;
};

typedef struct joueur joueur;

void sauvegarde();

#endif