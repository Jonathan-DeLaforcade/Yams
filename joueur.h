#ifndef JOUEUR
#define JOUEUR

struct joueur {
  char *pseudo;
  int score;
  int nbLance;
};

typedef struct joueur joueur;

struct score {
  char *pseudo;
  int score;
  int nbLance;
};

typedef struct score score;


#endif