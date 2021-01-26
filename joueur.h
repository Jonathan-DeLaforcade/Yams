#ifndef JOUEUR
#define JOUEUR

struct joueur {
  char *pseudo;
  int score;
  int nbLance;
};

typedef struct joueur joueur;

#endif