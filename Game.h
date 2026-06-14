#ifndef GAME_H
#define GAME_H

#include "LinkedList.h"

class Game {
 public:
  void run();

 private:
  LinkedList list_;

  void menu();

  void loadFromConsole();
  void loadFromFile();
  void loadRandom();

  int solve();
};

#endif