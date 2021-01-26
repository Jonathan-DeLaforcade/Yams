#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tirage.h"
#include "menu.h"
//#include "sauvegarde.h"

int main() {
  srand(time(NULL));
    int gameChoice = mainMenu();
    switch(gameChoice) {
      case 1: {
        break;
      }
    }
    //sauvegarde();
    //lance();
    return 0;
}