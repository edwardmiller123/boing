#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "level.hpp"

class Game
{
private:
  sf::RenderWindow window;
  sf::Event event;
  sf::View view;
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
    currentLevel.initLevel("assets/level.png", "assets/boingo.png");
    view.setSize(sf::Vector2f(1076.f, 600.f));
    window.setView(view);
  }

  // Game logic
  void run()
  {
    update();
    render();
  }
  // Handles game logic.
  void update()
  {
    currentLevel.player.updatePosition(window);
    pollEvents();
  }
  // Handles whats shown on screen.
  void render()
  {
    window.clear();
    window.draw(currentLevel.background);
    window.draw(currentLevel.player.playerSprite);
    updateView();
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

  sf::Vector2f updateView() {
    view.setCenter(currentLevel.player.currentPosition);
  }
};