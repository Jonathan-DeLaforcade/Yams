#ifndef JOUEUR
#define JOUEUR

/*
  struct joueur {
    pseudo = "PseudoDuJoueur"
    scores = [
      [
        1,  // AS
        2,  // DEUX
        3,  // TROIS
        4,  // QUATRE
        5,  // CINQ
        6,  // SIX
        7,  // TOTAL 1
        8,  // BRELAN
        9,  // PETITE SUITE
        10, // GRANDE SUITE
        11, // FULL
        12, // CARRÉ
        13, // YAM
        14, // TOTAL 2
        15  // TOTAL GÉNÉRAL
      ], //manche 1
      [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17], //manche 2
      [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17]  //manche 3
      ....
    ]
  }
*/

struct joueur {
  char *pseudo;
  int scores[10][15];
};

typedef struct joueur joueur;


#endif