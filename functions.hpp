#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

struct levelInitialiser
{
  std::string backgroundTexturePath, playerTexturePath,
      floorTexturePath, musicPath, courseTexturePath;
  std::vector<sf::IntRect> playerFrames;
};

// A little clunky but we store all the level information here
// ready to be initialised.
std::vector<levelInitialiser> initLevels()
{
  levelInitialiser level1 = {"assets/backgroundL1.png",
                             "assets/boingo.png",
                             "assets/floorL1.png",
                             "assets/home.wav",
                             "assets/spike_no_background.png",
                             {{91, 150, 255, 243}, {479, 150, 255, 243}, {851, 150, 255, 243}, {1229, 150, 255, 243}}};

  // Initialise the other levels correctly when they arrive.
  levelInitialiser level2 = {"",
                             "",
                             "",
                             "",
                             "",
                             {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};
  levelInitialiser level3 = {"",
                             "",
                             "",
                             "",
                             "",
                             {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};
  std::vector<levelInitialiser> levels = {level1, level2, level3};
  return levels;
};

void initText(sf::Text &text, sf::Font &font, std::string fontPath,
              std::string textString, int textSize, sf::Color color, sf::Vector2f position)
{
  if (!font.loadFromFile(fontPath))
  {
    std::cout << "Error loading font";
  }
  text.setFont(font);
  text.setString(textString);
  text.setCharacterSize(textSize);
  text.setFillColor(color);
  text.setPosition(position);
}