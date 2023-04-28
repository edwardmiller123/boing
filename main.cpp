#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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