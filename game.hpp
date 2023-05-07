#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "menu.hpp"

class Game
{
private:
  sf::RenderWindow window;
  sf::Event event;
  Menu menu;
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
    menu.initMenu();
  }

  // Runs game
  void run()
  {
    update();
    render();
  }

  // Handles either game or menu logic.
  void update()
  {
    pollEvents();
    if (menu.menuOpen)
    {
      menu.updateMenu(window, keyPressed, currentLevel);
      if (menu.quit)
      {
        gameRunning = false;
      }
    }
    else
    {
      currentLevel.updateLevel(window, keyPressed);
      if (currentLevel.gameOver)
      {
        menu.menuOpen = true;
      }
    }
    resetEvents();
  }

  // Handles whats shown on screen.
  void render()
  {
    window.clear();
    if (menu.menuOpen)
    {
      menu.renderMenu(window);
    }
    else
    {
      currentLevel.renderLevel(window);
    }
    window.display();
  }

  // We record the event and pass the outcome to the appropriate
  // handlers as a string. Passing a variable around this way may be
  // clunky but allows the event to be cleared before the next one is recorded.
  // This fixes problems such as the menu skipping an option due to the previous
  // key press event not being overwritten.
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
        if (event.key.code == sf::Keyboard::Space)
        {
          keyPressed = "space";
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
          keyPressed = "up";
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
          keyPressed = "down";
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
          keyPressed = "enter";
        }
      default:
        break;
      }
    }
  }

  // We pass the current event down to the other objects as
  // a string which means we need to clear it after the action has been triggered.
  void resetEvents()
  {
    keyPressed = "";
  }
};