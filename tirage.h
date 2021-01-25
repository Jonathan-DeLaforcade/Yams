#ifndef TIRAGE
#define TIRAGE

struct tirage {
  int de1;
  int de2;
  int de3;
  int de4;
  int de5;
};

typedef struct tirage Tirage;

int randomNumber();
Tirage tirageDe();
void lance();

#endif