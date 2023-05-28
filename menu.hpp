#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "level.hpp"

class Menu
{
private:
  sf::Text title;
  std::vector<sf::Text> menuOptions;
  std::vector<levelInitialiser> levels;
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

    // Load menu options for main menu.
    sf::Text option1, option2, option3;
    menuOptions = {option1, option2, option3};
    initText(menuOptions[0], optionFont, "assets/Aadhunik.ttf", "Play", 50, sf::Color::White, sf::Vector2f(725.f, 350.f));
    initText(menuOptions[1], optionFont, "assets/Aadhunik.ttf", "Select Level", 50, sf::Color::White, sf::Vector2f(640.f, 475.f));
    initText(menuOptions[2], optionFont, "assets/Aadhunik.ttf", "Quit", 50, sf::Color::White, sf::Vector2f(725.f, 600.f));

    // Initalisation info for the level selection.
    levels = initLevels();

    // Game always starts on the main menu.
    currentPage == "mainMenu";
  }

  void updateMenu(sf::RenderWindow &window, std::string keyPressed, Level &level)
  {
    handleInput(keyPressed, level);
    updateOptionState();
    updatePageState();
  }

  void renderMenu(sf::RenderWindow &window)
  {
    window.setView(window.getDefaultView());
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
    else if (keyPressed == "escape")
    {
      currentPage = "mainMenu";
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

  void updatePageState()
  {
    if (currentPage == "mainMenu")
    {
      menuOptions[0].setString("Play");
      // This is the only option with a different x coordinate.
      menuOptions[1].setPosition(sf::Vector2f(640.f, 475.f));
      menuOptions[1].setString("Select Level");
      menuOptions[2].setString("Quit");
    }
    else if (currentPage == "levelSelect")
    {
      menuOptions[0].setString("Level 1");
      // Keeps level choice in line with others.
      menuOptions[1].setPosition(sf::Vector2f(725.f, 475.f));
      menuOptions[1].setString("Level 2");
      menuOptions[2].setString("Level 3");
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
      level.initLevel(levels[selectedLevel].backgroundTexturePath, levels[selectedLevel].playerTexturePath,
                      levels[selectedLevel].playerFrames, levels[selectedLevel].floorTexturePath,
                      levels[selectedLevel].musicPath, levels[selectedLevel].courseTexturePath,
                      levels[selectedLevel].spikePositions);
    }
    else if (currentOptionString == "Select Level")
    {
      currentPage = "levelSelect";
    }
    else if (currentOptionString == "Quit")
    {
      quit = true;
    }
    else if (currentPage == "levelSelect")
    {
      selectedLevel = currentOption;
      currentPage = "mainMenu";
    }
  }
};