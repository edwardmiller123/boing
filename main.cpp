#include <iostream>

#include "game.hpp"

int main()
{

  Game game;
  game.initGame();
  while (game.gameRunning)
  {
    game.run();
  }
  return 0;
}