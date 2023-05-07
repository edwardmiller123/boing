#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "level.hpp"
#include "functions.hpp"

class Menu
{
private:
  sf::Text title;
  std::vector<sf::Text> menuOptions;
  std::string levels[3][5] = {{"assets/backgroundL1.png", "assets/boingo.png", "assets/floorL1.png",
                               "assets/home.wav", "assets/spike_no_background.png"},
                              {"", "", "", "", ""},
                              {"", "", "", "", ""}};
  int currentOption = 0;
  int selectedLevel = 0;
  std::string currentPage, currentOptionString;
  sf::Font titleFont, optionFont;

public:
  bool menuOpen = true;
  bool quit = false;

  void initMenu()
  {
    // Load title
    initText(title, titleFont, "assets/ArcadeClassic.ttf", "Boing!", 200, sf::Color::White, sf::Vector2f(475.f, 50.f));

    // Load menu options for first page.
    sf::Text option1, option2, option3;
    menuOptions = {option1, option2, option3};
    initText(menuOptions[0], optionFont, "assets/Aadhunik.ttf", "Play", 50, sf::Color::White, sf::Vector2f(725.f, 350.f));
    initText(menuOptions[1], optionFont, "assets/Aadhunik.ttf", "Select Level", 50, sf::Color::White, sf::Vector2f(640.f, 475.f));
    initText(menuOptions[2], optionFont, "assets/Aadhunik.ttf", "Quit", 50, sf::Color::White, sf::Vector2f(725.f, 600.f));
  }

  void updateMenu(sf::RenderWindow &window, std::string keyPressed, Level &level)
  {
    handleInput(keyPressed, level);
    updateOptionState();
  }

  void renderMenu(sf::RenderWindow &window)
  {
    window.draw(title);
    for (int i = 0; i < 3; i++)
    {
      window.draw(menuOptions[i]);
    }
  }

  void handleInput(std::string keyPressed, Level &level)
  {
    if (keyPressed == "up")
    {
      if (currentOption != 0)
      {
        currentOption--;
      }
    }
    else if (keyPressed == "down")
    {
      if (currentOption != 2)
      {
        currentOption++;
      }
    }
    else if (keyPressed == "enter")
    {
      selectOption(level);
    }
  }

  void updateOptionState()
  {
    menuOptions[currentOption].setOutlineColor(sf::Color::Blue);
    menuOptions[currentOption].setOutlineThickness(2);
    for (int i = 0; i < 3; i++)
    {
      if (i != currentOption)
      {
        menuOptions[i].setOutlineThickness(0);
      }
    }
  }

  void selectOption(Level &level)
  {
    // We do this as getString() returns an sf::String type which
    // must be converted to a useable string.
    currentOptionString = menuOptions[currentOption].getString();
    if (currentOptionString == "Play")
    {
      menuOpen = false;
      level.initLevel(levels[selectedLevel][0], levels[selectedLevel][1], levels[selectedLevel][2], levels[selectedLevel][3], levels[selectedLevel][4]);
    }
    else if (currentOptionString == "Quit")
    {
      quit = true;
    }
  }
};