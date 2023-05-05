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
  std::string keyPressed;
public:
  bool gameRunning;

  // Initialisation
  int initGame()
  {
    gameRunning = true;
    window.create(sf::VideoMode(1600, 800), "Boing!");
    window.setKeyRepeatEnabled(false);

    // TODO: Move level initialisation once the menu
    // has been implemented.
    currentLevel.initLevel("assets/backgroundL1.png", "assets/boingo.png", "assets/floorL1.png", "assets/home.wav", "assets/spike_no_background.png");
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
    pollEvents();
    currentLevel.updateLevel(window, keyPressed);
    resetEvents();
    if (currentLevel.gameOver) {
      // Close for now until menu is implemented.
      gameRunning = false;
    }
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
      case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Space) {
          keyPressed = "space";
        }
      default:
        break;
      }
    }
  }

  // We pass the current event down to the other objects as
  // a string which means we need to clear it after the action has occured.
  void resetEvents() {
    keyPressed = "";
  }
};