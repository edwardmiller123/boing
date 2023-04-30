#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "level.hpp"

class Game
{
private:
  sf::RenderWindow window;
  sf::Event event;
  Level currentLevel;
public:
  bool gameRunning;

  // Initialisation
  int initGame()
  {
    gameRunning = true;
    window.create(sf::VideoMode(1600, 800), "Boing!");

    // This will live here for now but needs to move once the menu
    // has been implemented.
    currentLevel.initLevel("assets/backgroundL1.png", "assets/boingo.png");
  }

  // Runs game
  void run()
  {
    update();
    render();
  }

  // Handles game logic.
  void update()
  {
    currentLevel.updateLevel(window);
    pollEvents();
  }
  
  // Handles whats shown on screen.
  void render()
  {
    window.clear();
    currentLevel.renderLevel(window);
    window.display();
  }

  void pollEvents()
  {
    while (window.pollEvent(event))
    {
      switch (event.type)
      {

      case sf::Event::Closed:
        window.close();
        gameRunning = false;
        break;
      default:
        break;
      }
    }
  }
};