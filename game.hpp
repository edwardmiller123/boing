#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game
{
private:
  sf::Window window;
  sf::Event event;

public:
  bool gameRunning;
  void initGame()
  {
    gameRunning = true;
    window.create(sf::VideoMode(1600, 800), "Boing!");
  }
  void run()
  {
    update();
    render();
  }
  void update()
  {
    pollEvents();
  }

  void render()
  {
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