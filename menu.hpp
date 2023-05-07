#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
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
  std::string currentPage;
  sf::Font titleFont, optionFont;

public:
  bool menuOpen = true;

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

  void updateMenu(sf::RenderWindow &window, std::string keyPressed)
  {
    handleInput(keyPressed);
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

  void handleInput(std::string keyPressed)
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
};